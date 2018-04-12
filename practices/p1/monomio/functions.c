#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void imprimir_monomio(monomio *p_monomio){

	printf("Coeficiente del monomio %i\t", p_monomio -> coeficiente);
	printf("Grado del monomio %i\n", p_monomio -> grado);

}

void leer_monomio(monomio *p_monomio){
	int coeficiente, grado;
	printf("Introduce el coeficiente: ");
	scanf("%i",&coeficiente);
	printf("Introduce el grado: ");
	scanf("%i",&grado);
	p_monomio->coeficiente = coeficiente;
	p_monomio->grado = grado;

}

void reading_vector ( monomio* pol){

	for (int i = 0; i< SIZE;i++){

		printf("Coeficiente: %i \t",(pol+i)->coeficiente);
		printf("Grado: %i\n",(pol+i)->grado);
	}
}

monomio* mayor_menor_grado(monomio* pol){

	int menor_grado = 999999999;
	int mayor_grado = -2222222;

	monomio* pol_mayor;
	monomio* pol_menor;
	for (int i = 0;i<SIZE;i++){

		if ( (pol+i)->grado > mayor_grado){

			mayor_grado  = (pol+i) -> grado;
			pol_mayor = (pol+i);
		}
		if ((pol+i)->grado < menor_grado ){
			menor_grado = (pol+i)->grado;
			pol_menor = (pol+i);
		}


	}

	printf("Polinomio de Menor grado -> %i\n",pol_menor->grado);
	printf("Polinomio de Mayor grado -> %i\n",mayor_grado);

	return 0;

}

void calcular_valor(monomio* pol){
	float x;
	float valor;
	printf("Introduce un valor para X: ");
	scanf("%f\n",&x );

	for (int i = 0 ; i<SIZE;i++){
		float coeficiente = (float ) ((pol+i)->coeficiente);
		float grado = (float )((pol+i)->grado);
		valor = (coeficiente * pow (coeficiente,grado));
		imprimir_monomio(&pol[i]);
		printf("%f\n",valor );


	}

}
