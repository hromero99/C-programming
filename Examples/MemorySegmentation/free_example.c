#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  int *puntero_para_heap;
  //Con sizeof nos encargamos de ver el tamaño de una determinada variable
  puntero_para_heap = (int *) malloc(sizeof(int));

  printf("%p\n",puntero_para_heap );

  *puntero_para_heap = 213213123;

  printf("%i\n",*puntero_para_heap );

  free(puntero_para_heap);
  printf("After free\n");
  printf("%i\n",*puntero_para_heap );
  return 0;
}
