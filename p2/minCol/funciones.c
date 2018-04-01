/**
@file funciones.c
@brief Matrix functions code
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
<<<<<<< HEAD
=======
/**
@file funciones.c
@brief Matrix functions code
@author Hector
@date today

Este fichero tiene funciones para trabajar con matrices
@li Reservar memoria
@li Rellenar matriz de forma aleatoria
@li Imprimir una matriz
@li Obtener los mínimos de cada columna
*/

/**
@fn buildMatrix
@brief function used to reserve memory for a Matrix
@param nFil File number
@param nCol Column number
@return matrix pointer

Esta funcion reserva memoria con calloc inicianlizando a cero los valores, para posteriormente esribir valores apropiados
*/
>>>>>>> fd32fc4b8728400d5c3a5d25dc41bc713a296a03

int ** buildMatrix(int nFil,int nCol){

  int ** pMatrix;
<<<<<<< HEAD
=======
  ///Save memory for the array of pointers
>>>>>>> fd32fc4b8728400d5c3a5d25dc41bc713a296a03
  pMatrix = calloc(nFil,sizeof(int *));

  for (int i = 0; i<nFil;i++){

    pMatrix[i] = calloc(nCol,sizeof(int));
  }
  if (pMatrix == NULL){
    printf("Fallo en la reserva de memoria\n" );
  }
  else{
    return pMatrix;
  }
}

void fildMatrix(int ** matriz,int nFil,int nCol){

  srand(time(NULL));
  for (int i = 0; i<nFil;i++){
    for (int j = 0; j<nCol;j++){
      *(*(matriz+i)+j) = rand()%20+1;
    }
  }

}

void printMatrix(int ** matriz,int nFil,int nCol){
  for (int i = 0; i<nFil;i++){
    printf("\n");
    for (int j = 0; j<nCol;j++){
      printf("%d\t",matriz[i][j]);
    }
  }

}

int * minCol(int** matriz, int nFil,int nCol){
  int min;
  int *valores;
  valores = calloc(nCol,sizeof(int));
  for (int i = 0; i<nCol;i++){
    min = matriz[0][i];
    for (int j = 0; j<nFil;j++){
      if (matriz[j][i]<min){
        min = matriz[j][i];
      }
    }
    //Guardar el minimo de la columna dentro del vector
    *(valores+i) = min;
  }

  return valores;
}
