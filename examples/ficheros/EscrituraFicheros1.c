#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  //Realizamos la aprtura del fichero
  FILE* DiskFile;
  DiskFile = fopen("test", "wt");
  if (DiskFile == NULL){
    printf("Fallo al abrir el fichero");
    exit(-1);
  }
  //Escribimos el contenido en el archivo
  int WriteControl;
  WriteControl= fputs("Hola, este mensaje es de C",DiskFile);
  if(WriteControl < 0 || WriteControl == EOF){
    printf("Fallo al escribir el fichero\n");
    exit(-1);
  }

  //Cerramos el fichero
  fclose(DiskFile);

  return 0;
}
