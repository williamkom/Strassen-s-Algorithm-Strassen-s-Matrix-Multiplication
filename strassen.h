/***************************************************
*@file strassen.h                                  *
*@authors William Kom, Djime Gueye                 *
*@section DESCRIPTION                              *
***************************************************/
#include<iostream>

/** \brief: this function multiplicates two matrices using
 *  strassen's method
 * \param1 size of the matrix
 * \param2 first matrix to multiply
 * \param3 second matrix to multiply
 * \param4 result to save the result
 * \return the result matrix
 */
void strassen(int N, double **MatrixA, double **MatrixB, double **MatrixC)
{
    if (N == 1)/**< Trivial case, when the matrices have only one element */
	    MatrixC[0][0] = MatrixA[0][0] * MatrixB[0][0];
    else {
	 
       int size = N/2;
/** < initialization and memory allocation for the M1,...,M7 of the algorithm
  and two helpmatrices */ 
       double **M0 = new double* [size];
       double **M1 = new double* [size];
       double **M2 = new double* [size];
       double **M3 = new double* [size];
       double **M4 = new double* [size];
       double **M5 = new double* [size];
       double **M6 = new double* [size];
       double **tempA = new double* [size];
       double **tempB = new double* [size];
	
       for (int i = 0; i < size; i++)
       {
            M0[i] = new double [size];
            M1[i] = new double [size];
            M2[i] = new double [size];
            M3[i] = new double [size];
            M4[i] = new double [size];
            M5[i] = new double [size];
            M6[i] = new double [size];
            tempA[i] = new double [size];
            tempB[i] = new double [size];
 
      }
      for(int i=0;i<size;i++) {
          for (int j = 0; j < size ; j++){
              tempA[i][j] = MatrixA[i][j] + MatrixA[i+size][j+size];/**< tempA = A00+A11*/
              tempB[i][j] = MatrixB[i][j] + MatrixB[i+size][j+size];/**< tempB = B00+B11*/
          }
      }
      strassen(size,tempA,tempB,M0);/**< M0 = (A00 + A11) x (B00 + B11)*/

      for(int i=0;i<size;i++) {
          for(int j=0;j<size;j++) {
              tempA[i][j]=MatrixA[i+size][j]+ MatrixA[i+size][j+size];/**< tempA = A10+A11*/
              tempB[i][j] = MatrixB[i][j];/**< tempB = B00*/
          }
       }
     strassen(size,tempA, tempB,M1);/**< M1 = (A10 + A11) x B00 */

      for (int i = 0; i < size; ++i) {
          for(int j=0;j<size;j++){
              tempA[i][j] = MatrixA[i][j];/**< tempA = A00 */
              tempB[i][j]=MatrixB[i][j+size]- MatrixB[i+size][j+size];/**<tempB = B01 - B11*/
          }
       }
      strassen(size,tempA,tempB,M2);/**< M2 = A00 x (B01 - B11)*/

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            tempA[i][j] = MatrixA[i+size][j+size];/**< tempA = A11*/
            tempB[i][j] = MatrixB[i+size][j] - MatrixB[i][j];/**< tenpB = B10-B00*/
         }
     }
  strassen(size,tempA,tempB,M3);/**<M3 = A11 x (B10 - B00)*/
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            tempA[i][j] = MatrixA[i][j]+MatrixA[i][j+size];/**<tempA = A00+A01*/
            tempB[i][j] = MatrixB[i+size][j+size];/**<*tempB = B11*/
        }
    }

  strassen(size, tempA,tempB,M4);

    for( int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tempA[i][j] = MatrixA[i+size][j] - MatrixA[i][j];/**<tempA = (A10-A00)*/
            tempB[i][j] = MatrixB[i][j] + MatrixB[i][j+size];/**<tempB = (B00+B01)*/
        }
    }
  strassen(size, tempA, tempB, M5);/**<M5 = (A10-A00)*(B00+B01)*/

    for( int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            tempA[i][j] = MatrixA[i][j+size] - MatrixA[i+size][j+size];/**<tempA=(A01-A11)*/
            tempB[i][j] = MatrixB[i+size][j] + MatrixB[i+size][j+size];/**<tempB=(B10-B11)*/
        }
    }
  strassen(size, tempA, tempB, M6);/**<M6 = (A10-A11)*(B10+B11)*/
/**
* Now the result (Cij) is calculated
*/
 /**<C00 is calculated*/
    for(int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            MatrixC[i][j] = M0[i][j] + M3[i][j] - M4[i][j] + M6[i][j];
        }
    }
 /**<C01 is calculated*/
    for(int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            MatrixC[i][j+size] = M2[i][j] + M4[i][j];
        }
    }
 /**<C10 is calculated*/
    for(int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            MatrixC[i+size][j] = M1[i][j] + M3[i][j];
        }
    }
 /**<C11 is calculated*/
    for(int i=0; i<size; i++){
        for (int j = 0; j < size; j++){
            MatrixC[i+size][j+size] = M0[i][j] - M1[i][j] + M2[i][j] + M5[i][j];
        }
    }
  
/**< free the memory allocated for the matrices*/
    for (int i = 0; i < size; i ++) {

        delete[] M0[i]; delete[] M1[i]; delete[] M2[i]; delete[] M3[i];
        delete[] M4[i]; delete[] M5[i]; delete[] M6[i];
        delete[] tempA[i]; delete[] tempB[i];
    }
       delete[] M0; delete[] M1; delete[] M2; delete[] M3;
       delete[] M4; delete[] M5; delete[] M6;
       delete[] tempA; delete[] tempB;
  
    }
}
	
	
