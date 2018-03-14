//Podemos reservar la memoria de las matrices conforme la ejecutamos, si queremos una matriz de orden mxn se haria asi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



float** crear_matriz(int* fil,int* col){

  float** Matriz;

  //Si queremos una matriz de X filas e Y columnas en primer lugar tenemos que reservas las filas (primer indice)
  //Simplemente sera un vector de punteros de tipo float, que apuntan al primer indice de la fila
  Matriz = (float **) calloc(fil,sizeof(float *));
  //Para el numero de filas de la matriz tenemos que crear las columnas
  for (int i = 0;i<fil;i++){

    //Para cada una de las filas (vectores) creadas con anterioridad tenemos que ajustar el tamaño
    //De esta forma cada elemento de la fila tendra el tamaño de un float
    Matriz[i] = (float *) calloc(col,sizeof(float));

  }
  return Matriz;
}

int main(int argc, char const *argv[]) {
   srand(time(0));
  int fil=2,  col=3;
  float** p;
/*  printf("Introduce las filas\n" );
  scanf("%i\n",&fil );
  printf("Introduce las columnas\n" );
  scanf("%i\n",&col );*/

  p = crear_matriz(fil,col);

  p[0][0]=1.1;
  p[0][1]=1.2;
  p[0][2]=1.3;
  p[1][0]=2.1;
  p[1][1]=2.2;
  p[1][2]=2.3;

  for (int k=0; k<fil; k++){
  printf("\n");
  for (int l=0; l<col; l++)
    printf("\t%f", p[k][l] );
}


  free(p);
  return 0;
}
