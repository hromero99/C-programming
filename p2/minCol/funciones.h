/**
@file funciones.h
@brief Matrix functions head
@author Hector
@date today

Este fichero tiene funciones para trabajar con matrices
@li Reservar memoria
@li Rellenar matriz de forma aleatoria
@li Imprimir una matriz
@li Obtener los mínimos de cada columna
*/
#ifndef FUNCIONES_H
#define  FUNCIONES_H
/**
@fn int ** buildMatrix(int nFil,int ncol);
@brief function used to reserve memory for a Matrix
@param a  raws number
@param b Column number
@return return the pointer to the matrix

This function make the memory reservation for the matrix
*/
int ** buildMatrix(int nFil,int ncol);
/**
@fn void printMatrix(int ** matriz,int nFil,int nCol)
@brief function used to print matrix values
@param a Matrix Pointer
@param b  raws number
@param c Column number
@return the matrix is printed on screen

This function print the matrix
*/
void printMatrix(int ** matriz,int nFil,int nCol);
/**
@fn void fildMatrix(int ** matriz,int nFil,int nCol)
@brief function used to fild hte matrix with random values
@param a Matrix Pointer
@param b  raws number
@param c Column number
@return Nothing, the values are written on memory

This Matrix is fild with random values (include 0)
*/
void fildMatrix(int ** matriz,int nFil,int nCol);
/**
@fn int * minCol(int** matriz, int nFil,int nCol)
@brief function to search lower values in column
@param a Matrix Pointer
@param b  raws number
@param c Column number
@return Pointer to a vector of number

The function make a vector wich contains the lower number of each column in the matrix
*/
int * minCol(int** matriz, int nFil,int nCol);
/**
@fn void FreeMatriz(int** matriz, int nFil)
@brief Fucntion to free the memory of the Matrix
@param int** matriz The matrix
@param int nFil Number of raws
@return nothing
*/
void FreeMatriz(int** matriz, int nFil);

#endif
