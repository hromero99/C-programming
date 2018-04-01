/**
@file funciones.c
@brief Matrix functions code
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** buildMatrix(int nFil,int nCol){

  int ** pMatrix;
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
