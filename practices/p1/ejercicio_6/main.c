#include <stdio.h>
#include <stdlib.h>

void minimo (int a, int b){
  int aux = 9999999;
  if ( b<a){
    aux = b;
  }
  else{
    aux = a;
  }
  printf("%i\n",aux );
}

void minimo_referencia(int* a, int* b,int* minimo){
  int aux = 9999999;
  if ( *b<*a){
    aux = *b;
  }
  else{
    aux = *a;
  }
  *minimo = aux;
}

int main(int argc, char const *argv[]) {
  int a = 2, b = 3;
  int min;
  minimo( a ,b);
  minimo_referencia(&a,&b,&min);
  printf("%i\n",min );
  return 0;
}
