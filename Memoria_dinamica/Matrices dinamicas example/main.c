#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {
  int** matrix;
  int columns = 2;
  int raws = 3;
  int number = 29;
  matrix = BuildMatrix(&raws,&columns);
  FillMatrix(matrix,&number,&raws,&columns);
  PrintMatrix(matrix,&raws,&columns);
  FreeMatrix(matrix,&raws);
  return 0;
}
