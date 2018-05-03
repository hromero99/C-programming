#include <stdio.h>
#include <stdlib.h>

int Espar(int num){
  //Funcion para determinar si el numero es par y devulva valor booleano
  if (num %2 == 0){
    return 1;
  }
  else{
    return 0;
  }
}


int main(int argc, char const *argv[]) {
  FILE* file;
  int aux;
  int Npar=0;
  int Ntotal=0;
  //Comprobamos que los argumentos esten bien introducidos
  if (argc != 2){
    printf("Necesitas introducir el nombre dle fichero por argumentos\n");
    exit(-1);
  }
  //El fichero lo recibe por argumentos
  file = fopen(argv[1],"r");
  if (file == NULL){
    printf("Fallo al abrir el archivo\n");
    exit(-1);
  }
  //Recorremos el fichero
  while (!feof(file)){
    fscanf(file,"%i",&aux);
    //Llamamos a la funcion anteriormente definida
    if (Espar(aux)){
      Npar++;
      Ntotal = Ntotal + aux;
    }
  }
  printf("Media: %i\n",Ntotal/Npar );
  return 0;
}
