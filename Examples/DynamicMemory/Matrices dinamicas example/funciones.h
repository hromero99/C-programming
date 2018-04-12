/**
@file funciones.h
@brief Functions to do simple operations with Functions
@adate 03/04/18
@author Hector Romero Lopex

This file contains some functions to work correctly with nMatrix
@li BuildMatrix --> Makes the matrix using calloc
@li FillMatrix --> Fill the matrix given with random numbers
@li PrintMatrix --> Use screen output to print the nMatrix
@li FreeMatrix --> Free the memory used by matrix
*/
#ifndef FUNCIONES
#define FUNCIONES
/**
@func int** BuildMatrix(int* raws,int* columns)
@brief Makes the matrix using calloc
@param raws --> Pointer to the number of raws
@param columns --> Pointer to the number of columns
@return Pointer to the matrix
*/
int** BuildMatrix(int* raws,int* columns);
void TestMemory(int* pointer);
void FillMatrix(int** matrix, int* number,int* raws,int* columns);
void PrintMatrix(int** matrix,int* raws,int* columns);
void FreeMatrix(int** matrix,int* raws);


#endif
