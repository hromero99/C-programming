#include <stdio.h>


int main(int argc, char const *argv[]) {
  FILE* log;
  log = fopen("/var/log/auth.log","rt");
  if(log == NULL){
    printf("Fallo al abrir el archivo\n");
    exit(-1);
  }
  else{
    fclose(log);
  }
  return 0;
}
