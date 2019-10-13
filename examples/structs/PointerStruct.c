#include <stdio.h>
#include <stdlib.h>
#include "PointerStruct.h"


int main(){
    DatosAlumno* hector;
    hector = calloc(1,sizeof(DatosAlumno));
    int numero = 2;
    hector->numero = numero;
    printf("%i",hector->numero);
}
