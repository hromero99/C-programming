#include <stdio.h>
#include "funciones.h"
int main(int argc, const char * argv[]){
    int size = 12;
    number* numberArray;
    int* array = BuildArray(&size);
    FillArray(array,&size);
    printArray(array,&size);
    printf("\n\n\n");
    countTimes(array,&size);
    numberArray  = countTimes(array,&size);
    PrintcountTimes(numberArray,&size);
    if (CheckArray(numberArray,&size) == 1){
      printf("Es vector mayoritario\n");
    }
    DeleteNumber(array,&size,2);
    printArray(array,&size);
    return 0;
}
