#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* MakeArray(int* size){
  int* array;
  array = calloc(*size,sizeof(int));
  if (array == NULL) {
    printf("Fallo al reservar memoria\n");
    exit(-1);
   }
  return array;
}

void FillArray(int* array,int*size){
  srand(time(NULL));
  for(int i = 0;i<*size;i++){
    *(array+i) = rand()%20;
  }
}
int PrintArray(int* array, int* size,int* position){
  if (*position == *size) {
    return 0;
  }
  else{
    printf("%d\t",array[(*position)]);
    (*position)++;
  }

  PrintArray(array,size,position);

}

void MinMax(int* array, int* size, int* min, int* max){
  for(int i = 0;i<*size;i++){
    if (*(array+i)>*max){
      *max = *(array+i);

    }
    else{
        if (*(array+i)<*min){
          *min = *(array+i);


        }
    }
  }

}
