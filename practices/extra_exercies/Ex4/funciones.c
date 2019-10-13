#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"

BookData* MakeBookArray(int* Booksize){
  BookData* library;
  library = calloc(*Booksize,sizeof(BookData));
  if(library == NULL){
    printf("Fallo al reservar memoria\n");
    exit(-1);
  }
  srand(time(NULL));
  for(int i = 0; i< *Booksize; i++){
    strcpy((library+i)->title, "Titulo");
    strcpy((library+i)->autor, "autor");
    (library+i)->cantidad = rand()%55;
    (library+i)->precio = 2.2;
  }
  /*
  for(int i = 0; i< *Booksize; i++){
    printf("%s\n",(library+i)->title);
    printf("%s\n",(library+i)->autor);
    printf("%d\n",(library+i)->cantidad);
    printf("%f\n",(library+i)->precio);
  }*/

  return library;
}
void WriteBinaryFile(char* BinaryFile, int*BookSize){
  BookData* library = MakeBookArray(BookSize);
  FILE* file;
  file = fopen(BinaryFile,"wb");
  if ( file == NULL){
    printf("[!]No existe el fichero\n");
    exit(-1);
  }
  fwrite(library,*BookSize,sizeof(BookData),file);
  fclose(file);
}


BookData* ReadFileContent (char* BinaryFile,int*size){
  BookData* library = calloc(*size,sizeof(BookData));
  FILE* file;
  file = fopen(BinaryFile,"rb");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n");
    exit(-1);
  }
  fread(library,*size,sizeof(BookData),file);
  fclose(file);
  return library;

}

int Ordenar (const void  *a, const void  *b){

  BookData *x = (BookData *)a;
  BookData *y = (BookData *)b;
  return (x->cantidad -  y->cantidad);
}

void OrdenaLibrary(BookData* library, int* size){
  int(*pf)(const void *a, const void *b);
  pf = Ordenar;
  qsort(library,*size,sizeof(BookData),pf);
  for(int i = 0; i< *size; i++){

    printf("%d\n",(library+i)->cantidad);
  }
}

void WriteTextFile(char* TextFile, int*size, BookData* library){
  char buffer[100];
  FILE* file;
  file =fopen(TextFile,"wt");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n" );
    exit(-1);
  }
  for (int i = 0; i<*size;i++){
    fputs((library+i)->title ,file);
    fputs("\n",file);
    fputs((library +i)->autor, file);
    fputs("\n",file);
    sprintf(buffer,"%d\t%f\n",(library+i)->cantidad,(library+i)->precio);
    fputs(buffer,file);
  }
  fclose(file);
}
