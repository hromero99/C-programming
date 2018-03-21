
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** buildMatrix(int nFil,int nCol){

  int ** pMatrix;

  pMatrix = calloc(nFil,sizeof(int *));

  for (int i = 0; i<nCol;i++){

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
      matriz[i][j] = rand()%56;
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
  valores = calloc(nFil,sizeof(int));
  for (int i = 0; i<nFil;i++){
    min = matriz[i][0];
    for (int j = 0; j<nCol;j++){
      if (matriz[i][j]<min){
        min = matriz[i][j];
      }
    }
    valores[i] = min;
  }

  return valores;
}
