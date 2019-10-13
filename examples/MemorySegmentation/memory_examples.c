#include <stdio.h>
#include <stdlib.h>

int global_var;
int global_var_inicializada = 5;

void function(){

  int stack_var;
  printf("Direccion de memoria de variable en stack %p\n", &stack_var);
}

int main(int argc, char const *argv[]) {
  int stack_var;
  static int static_var;
  static int static_var_inicializada = 2;
  int *heap_puntero;

  heap_puntero = (int *) malloc(sizeof(int));

  printf("Data Segment\n");
  printf("%p\n%n",&global_var_inicializada,&static_var_inicializada );

  printf("BSS Segment\n");
  printf("%p\n%p\n",&static_var,&global_var );

  printf("Heap Segment\n" );
  printf("%p\n",&heap_puntero );

  printf("Stack Segment\n" );
  printf("%p\n",&stack_var );

  function();

  return 0;
}
