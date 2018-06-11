#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {
  char filename[100];
  if (argc !=2){
    printf("USAGE: ./library filename \n");
    exit(-1);
  }
  strcpy(filename,argv[1]);
  //AddNewBook(filename);
  //SearchBook(filename);
  printf("%d\n",CountBooks(filename));
  return 0;
}
