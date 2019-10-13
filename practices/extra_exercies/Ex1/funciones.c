#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
int* BuildArray(int* size){
    int *array;
    array = calloc(*size,sizeof(int));
    if(array == NULL){
        printf("[!]Error with memory reservation");
        exit(-1);
    }
    return array;
}
void FillArray(int* array, int* size){
    srand(time(NULL));
    for (int i=0;i<*size;i++){
        *(array+i) = rand()%20;
    }
}
void printArray(int* array,int* size){
    for (int i=0;i<*size;i++){
        printf("%i\t",*(array+i));
    }
}


number* MakeNumberArray(int* size){

  number* array;
  array = calloc(*size, sizeof(number));
  if(array == NULL){
    printf("[!] Error during memory reservation\n");
    exit(-1);
  }
  return array;
}

number* countTimes(int* array,int*size){
  number* numberArray;
  numberArray = MakeNumberArray(size);
  number TmpNumber;
  for (int i = 0;i<*size;i++){
    TmpNumber.num = array[i];
    TmpNumber.times=0;
    for (int j = 0; j<*size;j++){
      if(*(array+j)== TmpNumber.num){
        TmpNumber.times +=1;
      }
    }
    *(numberArray+i) = TmpNumber;
  }
  return numberArray;
}
int CheckArray(number* array,int*size){
  for (int i = 0;i<*size;i++){
    if ( ((array+i)->times) == *size/2){
      return 1;
    }
  }
  return 0;
}
void DeleteNumber(int* array,int*size, int number){
  int aux = 0;
  for (int i = 0;i<*size;i++){
    if (*(array+i) == number){
      printf("Found\n");
      aux++;
      array[i] = array[i+1];
    }
  }

}
void PrintcountTimes(number* numberArray,int*size){
  for (int i = 0;i<*size;i++){
    printf("%d \t",(numberArray+i)->num);
    printf("%d\n",(numberArray+i)->times);
  }
}
