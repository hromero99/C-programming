#include <stdio.h>


int main(){
    int valor = 95;
    int* PointToValor;
    PointToValor = &valor;
    printf("Valor AddrMemory:%p\n",valor);
    printf("Valor Value: %i\n",*PointToValor);
    int* PointToPointToValor;
    PointToPointToValor = PointToValor;
    printf("Valor AddrMemory:%p\n",*PointToPointToValor);
    printf("Valor Value: %i\n",*PointToPointToValor);
    


    return 0;
}
