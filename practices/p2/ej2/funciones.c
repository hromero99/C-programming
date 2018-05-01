#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * buildArray(int size){
  int* pArray;
  pArray = calloc(size, sizeof(int ));
  if (pArray == NULL){
	printf("Fallo al reservar memoria\n");
	exit(-1);
  }
  else{
	return pArray;
  }
}

void fillArray(int array[], int size){
  srand(time(NULL));
  for ( int i = 0;i<size;i++){
    *(array+i) = rand()%40;
  }
}

void writeArray(int array[], int index,int valor){
    *(array+index) =valor;
}

int ArrayValues(int *vector,int size_vector, int num, int *mayores, int *menores,int* minAux,int* maxAux){

  for (int i = 0; i< size_vector;i++){
    if (*(vector + i) > num){
      writeArray(mayores,*maxAux,(*(vector+i)));
      *maxAux = *maxAux +1 ;
    }
    else{
      writeArray(menores,*minAux,*(vector+i));
      *minAux = *minAux +1 ;

    }
  }
  mayores = realloc(mayores, *maxAux * sizeof(int));
  menores = realloc(menores, *minAux * sizeof(int));

}

void printValues(int array[], int values){
  for (int i = 0; i<values;i++){
    printf("%d\t", *(array+i));
  }
}
