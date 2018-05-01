#include <stdio.h>
#include <stdlib.h>

int count(int a,int b, int c){

  printf("%i %i %i\n",a,b,c );
}

int main(int argc, char const *argv[]) {
  count(1,2,3);
  return 0;
}
