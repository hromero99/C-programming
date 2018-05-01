#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"


int main(){

	monomio polinomio[SIZE];

	for(int i = 0; i<SIZE; i++){
		leer_monomio(&polinomio[i]);
		printf("Monomio añadido al vector\n");
	}

	reading_vector(polinomio);

	monomio* m = mayor_menor_grado(polinomio);


	calcular_valor(polinomio);
}
