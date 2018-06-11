#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void PrintArray(int* array, int*size){
  for(int i = 0; i<*size;i++){
    printf("%d\t",*(array+i) );
  }
  printf("\n");
}

/*
void OrdenarVector(int* array,int* size){
  int position,auxNumber;
  for(int i = 0;i<*size;i++){
      position = i;
      auxNumber = array[i];
      while ((position>0)&&(auxNumber < array[position-1])) {
        array[position] = array[position-1];
        position--;
      }
      array[position] = auxNumber;
  }
}*/
int comparar_int(const void*a,const void*b){
  int *x,*y;
  x = (int*)a;
  y = (int*)b;
  return *x-*y;
}
void OrdenarVector(int* array,int* size){
  int(*pf)(const void*a,const void*b);
  pf = comparar_int;
  qsort((void*)array,*size,sizeof(int),pf);
}
