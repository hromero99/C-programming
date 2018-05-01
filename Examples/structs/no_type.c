#include <stdlib.h>


int main(int argc, char const *argv[]) {
  struct monomio{
    int grado;
    int coeficiente;
  };
  struct monomio pol;
  pol.grado = 3;
  printf("%i\n",pol.grado );
  return 0;
}
