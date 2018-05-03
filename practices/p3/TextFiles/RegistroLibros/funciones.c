#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


void ClearString(char* StringToClear){
  char* pos;
  if ((pos=strchr(StringToClear, '\n')) != NULL){
    *pos = '\0';
  }
}

void PrintVector(char* NombreFichero,libro* Library){
  int Arraysize=CountBooks(NombreFichero);
  for (int i=0;i<Arraysize;i++){
    printf("Titulo: %s\n",(Library+i)->nombre);
    printf("Autor: %s\n",(Library+i)->autor);
    printf("Cantidad: %i\t",(Library+i)->cantidad);
    printf("Precio: %i\n",(Library+i)->precio);
    }
}

void WriteRegister(libro* BookData, char* NombreFichero){
  FILE* file;
  char buffer[100];
  file = fopen(NombreFichero,"a");
  if (file == NULL){
    printf("Fallo al abrir el fichero");
    exit(-1);
  }
  sprintf(buffer,"%s\n",BookData->nombre);
  fputs(buffer,file);
  sprintf(buffer,"%s\n",BookData->autor);
  fputs(buffer,file);
  //Funcion para formatear la entrada como string
  sprintf(buffer,"%i\t%i\n",BookData->cantidad,BookData->precio);
  fputs(buffer,file);
  fclose(file);
}

void AddBook(char* NombreFichero){
  libro Dlibro;
  printf("Introduce el nombre del libro:");
  setbuf(stdin,NULL);
  fgets(Dlibro.nombre,100,stdin);
  printf("Introduce el autor: " );
  fgets(Dlibro.autor,100,stdin);
  printf("Introduce la cantidad:");
  setbuf(stdin,NULL);
  scanf("%i",&Dlibro.cantidad );
  printf("Introduce el precio:");
  scanf("%i",&Dlibro.precio );
  WriteRegister(&Dlibro,NombreFichero);
}

void Searchbook(char* NombreFichero,char* Title){
  FILE* file;
  char buffer[100];
  char nombre[100];
  char title[100];
  file = fopen(NombreFichero,"r");
  if(file ==NULL){
    printf("Fallo al abrir el archivo\n" );
    exit(-1);
  }

  while(fgets(nombre,100,file)!= NULL){
    ClearString(nombre);
    if(strcmp(nombre,Title) == 0){
      printf("Found\n");
    }
    fgets(buffer,100,file);
    fgets(buffer,100,file);

  }

}

int CountBooks(char* NombreFichero){
  int aux=0;
  char buffer[100];
  FILE* file;
  file = fopen(NombreFichero,"r");
  if (file == NULL){
    printf("Hay un fallo con el fichero\n" );
    exit(-1);
  }

  while(fgets(buffer,100,file) != NULL){
    aux++;
    fgets(buffer,100,file);
    fgets(buffer,100,file);
  }
  fclose(file);
  return aux;
}

libro *BookArray(char* NombreFichero){
  FILE* file;
  libro TmpData;
  libro* FinalLibrary;
  char buffer[100];
  int aux = 0,precio,cantidad;
  int Arraysize = CountBooks(NombreFichero);
  //Abrimos el fichero
  file = fopen(NombreFichero,"r");
  if(file == NULL){
    printf("Fallo al abrir el fichero\n" );
    exit(-1);
  }
  //Creamos el vector dinamico
  FinalLibrary = calloc(Arraysize,sizeof(libro));
  if (FinalLibrary == NULL){
    printf("Fallo al reservar memoria\n");
    exit(-1);

  }
  //Recorremos el fichero para ir rellenando las estructuras
  while(!feof(file)){
    fgets(buffer,100,file);
    ClearString(buffer);
    strcpy(TmpData.nombre,buffer);
    fgets(buffer,100,file);
    ClearString(buffer);
    strcpy(TmpData.autor,buffer);
    fscanf(file,"%d\t%d\n",&precio,&cantidad);
    TmpData.precio = precio;
    TmpData.cantidad = cantidad;
    //Introducimos las estructuras en el vector
    *(FinalLibrary+aux) = TmpData;
    aux++;
  }
  fclose(file);
  return FinalLibrary;
}

void SellBook(char* NombreFichero,char* Title){
  libro* Library;
  //Leemos la informacion existente actualmente dentro del fichero
  Library = BookArray(NombreFichero);
  //Obtenemos la cantidad de libros que tenemos disponibles usando las funciones
  int Arraysize = CountBooks(NombreFichero);

  FILE *file;
  file = fopen (NombreFichero,"r");
  if (file==NULL){
    printf("Fallo al abrir el archivo\n" );
    exit(-1);
  }

  for (int i = 0;i<Arraysize;i++){
    printf("%s\t %s\t", ((Library+i)->nombre),Title);
    ClearString((Library+i)->nombre);
    ClearString(Title);
    printf("%i\n",strcmp( (Library+i)->nombre ,Title));
      if ( strcmp(((Library+i)->nombre),Title) == 0){
        (Library+i)->cantidad = ((Library+i)->cantidad)-1;
      }
    }

  //Funcion para escribir todos los libros dentro del fichero
  /*for(int i=0;i<Arraysize;i++){
    WriteRegister((Library+i),NombreFichero);
  }*/

}
