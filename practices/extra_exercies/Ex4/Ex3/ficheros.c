#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MakeFilledFile(char* filename,int* size){
  FILE* file;
  int* array;
  array = calloc(*size,sizeof(int));
  if(array==NULL){
    printf("Fallo al reservar memoria");
    exit(-1);
  }
    srand(time(NULL));
  for (int i  =0 ;i<*size;i++){
    *(array+i) = rand()%20;
    }

  file = fopen(filename,"wb");
  if (file == NULL){
    printf("Fallo al abrir el fichero\n" );
    exit(-1);
    }
  fseek(file,0,SEEK_SET);
  fwrite(array,sizeof(int),*size,file);
  fclose(file);
}

int* ReadFile(char* filename,int*size){
  FILE *file;
  int* data;
  data = calloc(*size,sizeof(int));
  if(data==NULL){
    printf("Fallo al reservar memoria");
    exit(-1);
  }
  file = fopen (filename,"rb");
  if (file==NULL){
    printf("Fallo al abrir el fichero\n" );
    exit(-1);
  }
  fread(data,sizeof(int),*size,file);
  fclose(file);
  return data;
}

void WriteTextFile(char* filenameText,int* array,int* size){
  char buffer[100];
  FILE *file;
  file = fopen (filenameText,"wt");
  if (file==NULL){
    printf("Fallo al abrir el archivo\n");
    exit(-1);
  }
  for(int i = 0;i<*size;i++){
    sprintf(buffer,"%d\n",array[i]);
    fputs(buffer,file);
  }
  fclose(file);
  }
