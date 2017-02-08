/***************************************************
*@file trivialMatrixMultiplication.h                                  *
*@authors William Kom, Djime Gueye                 *
*@section DESCRIPTION                              *
***************************************************/
#include <sstream>
#include <string>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>

using namespace std;

/** \brief: This funktion creates a random double matrix with a 
    given number of columns and rows
 *
 * \param1 number of rows of the matrix to create 
 * \param2 number of rows of the matrix to create 
 * \return a matrix with a number rows of rows and a number cols of columns 
 *
 */

double **createRandomDoubleMatrix(int rows, int cols) {

    double **arr = NULL;
    arr = new double*[rows];
    srand((time(NULL)));/**< initialization of the random seed*/
    for(int i=0; i<rows; i++){
        *(arr+i) = new double[cols];
    }
    for (int i=0;i<rows;++i){
        for(int j=0; j<cols; j++){
             arr[i][j] = ((double)(rand()%100)/10.0) +1.0;
        }
     }
    sleep(1);
    return arr;
}
/** \brief: this function multiplicates two matrix with the standard
 *  matrixmultiplicationsalgorithm
 * \param1 size of the matrix
 * \param2 first matrix to multiply
 * \param3 second matrix to multiply
 * \param4 result to save the result
 * \return the result matrix
 *
 */
void** trivialMatrixMultiplication(int size,double **MatrixA, double** MatrixB,double **Result){

    for (int i = 0; i < size; i++) {
        *(Result+i) = new double[size];
        for (int j = 0; j < size; j++) {
             Result[i][j] = 0.0;
            for (int k = 0; k < size; k++) {
                Result[i][j] += MatrixA[i][k] * MatrixB[k][j];
            }
        }
    }
}
/** \brief: this function shows a matrix
 *  \param1: matrix to show
 *  \param2: number of rows of the matrix 
 *  \param3: number of columns of the matrix  
 *  \return void  
 */
void printMatrix(double **mat, int rows, int cols) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
     }
}
/** \brief: this function frees the memory allocated for a matrix
 *  \param1: matrix to be deleted
 *  \param2: number of rows of the matrix 
 *  \param3: number of columns of the matrix  
 *  \return void  
 *
 */
void killMatrix(double **mat, int rows, int cols) {
  for (int i=0;i<rows;++i)
    delete [] *(mat+i);

  delete [] mat;
  mat = 0;
}

