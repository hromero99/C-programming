#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void FillFile(int down,int up,char* NombreFichero,int Nele){
  FILE* file;
  file = fopen(NombreFichero,"w");
  if ( file == NULL){
    printf("Fallo al abrir el fichero\n");
    exit(-1);
  }
  for (int i = 0; i<Nele;i++){
    char buffer[199];
    sprintf(buffer,"%i\n",rand()%down+up);
    fputs(buffer,file);
  }
  fclose(file);
}
