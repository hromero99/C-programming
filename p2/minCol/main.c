#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(int argc, char const *argv[]) {
  int **matriz;
  int *valores;
  int nCol =2,  nFil =3;

  matriz = buildMatrix(nFil,nCol);

  fildMatrix(matriz,nFil,nCol);
  printMatrix(matriz,nFil,nCol);
  valores = minCol(matriz,nFil,nCol);
  printf("\nValores: ");
  for (int i =0; i<nCol; i++){
    printf("\t%d",*(valores+i));
  }
  FreeMatriz(matriz,nFil);

  return 0;
}
