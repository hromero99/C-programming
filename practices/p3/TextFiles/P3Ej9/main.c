#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {
  if (argc != 2){
    printf("Tienes que introducir el fichero de stock\n");
    exit(-1);
  }
  else{
    char File[100];
    strcpy(File,argv[1]);
    Menu(File);
  }
  return 0;
}
