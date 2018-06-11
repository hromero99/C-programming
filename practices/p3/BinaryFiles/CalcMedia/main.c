#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char  *argv[]) {
  char filename[100];
  if (argc != 2){
    printf("Usage: ./a.out filename\n" );
    exit(-1);
  }
  strcpy(filename,argv[1]);
  printf("Media: %i\n",calcMedia(filename));
  return 0;
}
