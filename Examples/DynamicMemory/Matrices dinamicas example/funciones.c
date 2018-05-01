/**
@file funciones.c
@brief Matrix functions implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

void TestMemory(int* pointer){
  if (pointer == NULL){
    printf("\nError during the memory reservation\n");
    exit(-1);
  }
}

int ** BuildMatrix(int* raws,int* columns){
  int** matrix;

  matrix = (int **) calloc(*raws,sizeof(int *));
  if (matrix != NULL){
    for (int i = 0; i< *raws;i++){
      *(matrix+i) = (int * ) calloc(*columns,sizeof(int));
      TestMemory(*(matrix+i));
    }
    printf("\nMatrix Build Correctly\n");

    return matrix;
  }



}

void FillMatrix(int** matrix,int* number,int* raws,int* columns){
  srand(time(NULL));
  for (int i=0;i<*raws;i++){
    for(int j=0;j<*columns;j++){
      matrix[i][j] = rand()%*number;
    }
  }
  printf("\nMatrix completed :-) \n");
}

void PrintMatrix(int** matrix,int* raws,int* columns){
  for (int i=0;i<*raws;i++){
    printf("\n");
    for(int j=0;j<*columns;j++){
      printf("%d\t",*(*(matrix+i)+j ));
    //printf("%d\t",matrix[i][j] );
    }
  }
  printf("\n");
}

void FreeMatrix(int** matrix,int* raws){
  for (int i=0;i<*raws;i++ ){
    free(*((matrix)+i));
  }
  free(matrix);
  printf("\nMemory libered correctly\n");
}
