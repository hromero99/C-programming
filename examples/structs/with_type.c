#include <stdio.h>
#include <stdlib.h>
#include "with_type_header.h"


void pol_f(monomio* pol){
//No sirve el operador . tiene que hacerse uso del operador ->
  pol->grado = 2;
  printf("%d\n",pol->grado );
}

int main(int argc, char const *argv[]) {
  monomio p;
  p.grado = 2;
  printf("%d\n",p.grado );
  monomio pol[2];
  pol_f(pol);
  return 0;
}
