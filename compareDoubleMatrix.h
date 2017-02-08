/***************************************************
*@file compareDoubleMatrix.h                       *
*@authors William Kom, Djime Gueye                 *
*@section DESCRIPTION                              *
***************************************************/

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

 /** \brief this function compare two double numbers.
 * \param1 double a
 * \param2 doule b
 * \return true if the nummbers to compare are equal or else  false
 *
 */ 
bool compareDouble(double a,double b){
     double diff = a - b;
     if( diff <= 0 ) diff = -diff;
     if( diff < 0.001 ) return true;
     else return false;
    }	
 /** \brief this function compare two double matrices.
 * \param1  matrix to compare
 * \param2  matix to compare
 * \param3  size of the matrix
 * \return true if the matrices to compare are equal or else  false
 */
bool compareMatrix(double** MatrixA , double** MatrixB, int size){

    for(int i=0;i<size; i++){
        for(int j=0; j<size;j++){
            if(!(compareDouble(MatrixA[i][j],MatrixB[i][j]))){
                cout<< MatrixA[i][j]<<" "<<MatrixB[i][j]<<endl;
                return false;
                break;
            }
        }
     }
    return true;   
}
