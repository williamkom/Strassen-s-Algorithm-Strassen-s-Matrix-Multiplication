#include <sstream>
#include <string>
#include<math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include "TrivialMult.h"
#include "Strassen.h"
#include "compareDoubleMatrix.h"


int main(int argc, char **argv) {

  int rows= 512, cols= 512;//groeße der Matrix

  double**MatrixA = createMatrix(rows, cols);
  double**MatrixB = createMatrix(rows, cols);
 //printMatrix(MatrixA, rows, cols);
 //cout<<"--------------------"<<endl;
 //printMatrix(MatrixB, rows, cols);
 // cout<<"--------------------"<<endl;
  /*
    Leere Matrizen zum Speichern des ergebnisses 
*/
  double **MatrixC = new double*[rows];
	for(int i=0;i<rows;i++){
		MatrixC[i] = new double[rows]; }
  
    double **MatrixD = new double*[rows];
	for(int i=0;i<rows;i++){
		MatrixD[i] = new double[rows]; }

  clock_t start0, start1,end0,end1;
  
  start0 = clock();//beginn der zeit Messung fuer die TrivialMult
  MatrixC = TrivialMult(MatrixA,MatrixB,rows,cols);//MatrixC speichert das ergebiss von TrivialMult
  end0 = clock();//ende der Messung
  cout<<"TrivialMult: "<<endl;
  //printMatrix(MatrixC, rows, cols);
  double duration0 = end0 - start0;//Dauer berechnen in Sekunden
  cout<< "Time: "<<duration0/CLOCKS_PER_SEC << endl;// zeit ausgeben 
  
  start1 = clock();//beginn der zeit Messung fuer die TrivialMult
  Strassen(rows, MatrixA,MatrixB,MatrixD);
  end1 = clock(); // ende der Messung
  cout<<"Strassen: "<<endl;
  //printMatrix(MatrixD, rows, cols);
  double duration1 = end1 - start1;//Dauer berechnen in Sekunden
  cout<< "Time: "<<duration1/CLOCKS_PER_SEC << endl;
//gibt True zurueck wenn die Ergebnisse gleich sind.
  cout<<boolalpha<<compareMatrix(MatrixC,MatrixD,rows)<<endl;
  


  //Löschen nicht vergessen,
  //Speicher wurde in createMatrix mit new[] allokiert!!
  killMatrix(MatrixA, rows, cols);
  killMatrix(MatrixB, rows, cols);
  killMatrix(MatrixC, rows, cols);
  return 0;
};
