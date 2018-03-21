#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(int argc, char const *argv[]) {
  int **matriz;
  int *valores;
  int nCol = 1000000, nFil = 1000000;


  matriz = buildMatrix(nFil,nCol);

  fildMatrix(matriz,nFil,nCol);
  printMatrix(matriz,nFil,nCol);
  valores = minCol(matriz,nFil,nCol);
  printf("\nValores: ");
  for (int i =0; i<nFil; i++){
    printf("\t%d",valores[i] );
  }

  return 0;
}
