#include <stdio.h>
#include <stdlib.h>
#include "functions.h"




int main(int argc, char const *argv[]) {

  double vector[SIZE];
//Rellenamos el vector con valores aleatorios
  rellenar_vector(vector);
//Imprimimos la function del vector
  mostrar_vector(vector);
//Llenar vector
  llenar_vector(vector);
//leemos el vector llenado por nosotros
  mostrar_vector(vector);

//Sumamos los elementos mayores de cero del Vector

  printf("Suma del vector %i\n", suma_Positivos(vector));

  return 0;
}
