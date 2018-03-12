//Podemos reservar la memoria de las matrices conforme la ejecutamos, si queremos una matriz de orden mxn se haria asi

#include <stdio.h>
#include <stdlib.h>


float** crear_matriz(int* fil,int* col){

  float** Matriz;

  //Si queremos una matriz de X filas e Y columnas en primer lugar tenemos que reservas las filas (primer indice)
  //Simplemente sera un vector de punteros de tipo float, que apuntan al primer indice de la fila
  Matriz = (float **) calloc(fil,sizeof(float *));

  for (int i = 0;i<col;i++){

    //Para cada una de las filas (vectores) creadas con anterioridad tenemos que ajustar el tamaño
    //De esta forma cada elemento de la fila tendra el tamaño de un float
    Matriz[i] = (float *) calloc(col,sizeof(float));

  }
  return Matriz;
}

int main(int argc, char const *argv[]) {
  int fil=5,  col=5;
  float** p;
/*  printf("Introduce las filas\n" );
  scanf("%i\n",&fil );
  printf("Introduce las columnas\n" );
  scanf("%i\n",&col );*/

  p = crear_matriz(fil,col);



  free(p);
  return 0;
}
