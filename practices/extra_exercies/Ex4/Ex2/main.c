#include <stdio.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {
  int size=12,min=9999,max=-2222,position = 0;
  int* array;
  array = MakeArray(&size);
  FillArray(array,&size);
  PrintArray(array,&size,&position);
  printf("\n");
  MinMax(array,&size,&min,&max);
  printf("Min --> %d \n Max --> %d \n",min,max );
  return 0;
}
