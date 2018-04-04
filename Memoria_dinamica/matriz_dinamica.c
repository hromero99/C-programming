//Podemos reservar la memoria de las matrices conforme la ejecutamos, si queremos una matriz de orden mxn se haria asi

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int** crear_matriz(int nFil,int nCol){

  int** Matriz;

  //Si queremos una matriz de X filas e Y columnas en primer lugar tenemos que reservas las filas (primer indice)
  //Simplemente sera un vector de punteros de tipo float, que apuntan al primer indice de la fila
  Matriz = (int **) calloc(nFil,sizeof(int *));
  //Comprobamos que la mempria se ha reservado de forma correcta
  if (Matriz == NULL){
    printf("Fallo al reservar memoria\n");
    exit(-1);
  }
  //Para el numero de filas de la matriz tenemos que crear las columnas
  for (int i = 0;i<nFil;i++){

    //Para cada una de las filas (vectores) creadas con anterioridad tenemos que ajustar el tamaño
    //De esta forma cada elemento de la fila tendra el tamaño de un float
    Matriz[i] = (int *) calloc(nCol,sizeof(int));

  }
  return Matriz;
}
//llenamos la matriz de valores dinamicos
void fildMatrix(int ** matriz,int nFil,int nCol){

  srand(time(NULL));
  for (int i = 0; i<nFil;i++){
    for (int j = 0; j<nCol;j++){
      matriz[i][j] = rand()%56;
    }
  }

}

//Funcion para imprimir la matriz
void printMatrix(int ** matriz,int nFil,int nCol){
  for (int i = 0; i<nFil;i++){
    printf("\n");
    for (int j = 0; j<nCol;j++){
      printf("%d\t",matriz[i][j]);
    }
  }
}

int main(int argc, char const *argv[]) {
  srand(time(0));
  int nFil=2,  nCol=3;
  int** pMatriz;

  pMatriz = crear_matriz(nFil,nCol);
  fildMatrix(pMatriz,nFil,nCol);
  printMatrix(pMatriz,nFil,nCol);



//Hay que tener en cuenta que para liberar la memoria tenemos que liberar la memoria de cada filas
for (int i = 0; i<nFil;i++){
  free(pMatriz[i]);
}
free(pMatriz);
return 0;
}
