#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  //Abirmos el fichero
  FILE* DiskFile;
  DiskFile = fopen("/etc/passwd","rt");
  if (DiskFile==NULL){
    printf("Fallo al abrir el archivo\n");
    exit(-1);
  }
  //Leemos el contenido
  //Usamos un bucle While para recorrer el fichero
  char contenido[120];
  while (fgets(contenido,120,DiskFile) != NULL) {
    printf("%s\n",contenido );
  }

  //Cerramos el fichero
  fclose(DiskFile);
  return 0;
}
