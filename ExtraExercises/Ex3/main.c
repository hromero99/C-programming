#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ficheros.h"
#include "vector.h"

int main(int argc, char const *argv[]) {
  int ArraySize=12;
  char filename[100];
  char filenameText[100];
  int* data;
  if (argc !=3){
    printf("Usage: ./a.out ficheroBinario FicheroTexto \n");
    exit(-1);
  }
  strcpy(filename,argv[1]);
  strcpy(filenameText,argv[2]);
  //MakeFilledFile(filename,&ArraySize);
  data = ReadFile(filename,&ArraySize);
  PrintArray(data,&ArraySize);
  OrdenarVector(data,&ArraySize);
  PrintArray(data,&ArraySize);
  WriteTextFile(filenameText,data,&ArraySize);
  return 0;
}
