#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10

void entrada(char* cd[]);
void salida(char* cd[]);
int main(int argc, char const *argv[]) {
  char *cd[N];
  entrada(cd);
  salida(cd);
  return 0;
}
void salida(char* cd[]){
  for (int i =0;i<N;i++){
    printf("%s\n",cd[i] );
  }
}
void entrada(char* cd []){
  char* c_p;
  char b[121];
  printf("ANTES DEL FOR\n" );
  for(int i = 0; i<N; i++){
    gets(b);
    int tamano = (strlen(b) +1 ) *sizeof(char);
    cd[i] = (char *)malloc(tamano);
    strcpy(cd[i], b);
  }

}
