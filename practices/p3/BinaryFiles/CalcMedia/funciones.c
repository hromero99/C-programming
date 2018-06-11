#include <stdio.h>
#include <stdlib.h>


int* makeArray(int nEle){
  int* array;
  array= calloc(nEle,sizeof(int));
  if (array== NULL){
    printf("Fallo al reservar memoria\n");
    exit(-1);
  }
  return array;
}
int calcMedia(char* filename){
  //Open file in read mode
  FILE* file;
  int NumberOfElemets=0,aux=0;
  int* array;

  file = fopen(filename,"rb");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n" );
    exit(-1);
  }
  fseek(file,0L,SEEK_END);
  NumberOfElemets = ftell(file)/sizeof(int);
  array = makeArray(NumberOfElemets);
  fseek(file,0L,SEEK_SET);

  if (fread(array,sizeof(int),NumberOfElemets,file)!= NumberOfElemets){
    printf("Fallo al leer el fichero\n");
    exit(-1);
  }
  fclose(file);
  for (int i =0;i<NumberOfElemets;i++){
    aux = aux + *(array+i);
  }
  return aux/NumberOfElemets;
}
