#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {

  int arraySize = 12,maxSize = 12,minSize=12 , minAux = 0,maxAux = 0;
  int *array, *max,*min;
  array = buildArray(arraySize);
  max = buildArray(maxSize);
  min = buildArray(minSize);

  fillArray(array,arraySize);


  ArrayValues(array,arraySize,15,max,min,&minAux,&maxAux);

  printValues(array,arraySize);
  printf("\n" );
  printf("Max Values\n" );
  printValues(max,maxAux);
  printf("\n");
  printf("Min Values\n" );
  printValues(min,minAux);
  printf("\n");
  //Liberamos la memoria
  free(array);
  free(max);
  free(min);
  return 0;
}
