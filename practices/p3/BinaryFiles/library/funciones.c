#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

bookData getbook(){
  bookData tmpData;
  printf("Introduce el titulo\n");
  fgets(tmpData.titulo,100,stdin);
  printf("Introduce el autor\n");
  fgets(tmpData.autor,50,stdin);
  printf("Introduce el precio\n" );
  scanf("%f",tmpData.precio );
  printf("Introduce las cantidades\n" );
  scanf("%i",tmpData.precio );
  return tmpData;
}

void AddNewBook(char* filename){
  bookData libro = getbook();
  FILE* file;
  file = fopen(filename,"ab");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n");
    exit(-1);
  }
  else{
    fwrite(&libro,sizeof(bookData),1,file);
    fclose(file);
  }
}
int SearchBook(char*filename){
  char title[100];
  FILE* file;
  bookData buffer;
  printf("Introduce el titulo a para buscar: " );
  fgets(title,100,stdin);
  file =fopen(filename,"rb");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n");
    exit(-1);
  }
  while(fread(&buffer,sizeof(bookData),1,file)>0){
    if(strcmp(buffer.titulo,title) == 0){
      printf("Found\n");
      return 1;
    }
    else{
      return 0;
    }
  }
}
int CountBooks(char* filename){
  FILE* file;
  int books=0;
  file = fopen(filename,"rb");
  if (file==NULL){
    printf("Fallo al abrir el fichero\n");
    exit(-1);
  }
  fseek(file,0L,SEEK_END);
  books = ftell(file)/sizeof(bookData);
  fclose(file);
  return books;
}
