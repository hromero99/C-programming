#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
int suma_Positivos(double vector[]){
  int aux =0;
  for (int i = 0; i<SIZE;i++){

    if(*(vector+i) > 0 ){
      aux = aux + *(vector+i);
    }
  }
  return aux;
}

void mostrar_vector(double vector[]) {

  for (int i = 0; i<SIZE; i++){

    printf("%lf\n",*(vector+i) );

  }
}

void rellenar_vector(double vector[]){

  srand(time(NULL));
  for (int i = 0; i<SIZE;i++){
    vector[i] = (rand()%9)+10;
  }
  printf("Vector llenado correctamente\n");
}

void llenar_vector(double vector[]){
  double valor;
  for (int i = 0; i<SIZE;i++){
    printf("Introduce valores para el vector\n");
    scanf("%lf",&valor);
    vector[i] = valor;
  }
}
