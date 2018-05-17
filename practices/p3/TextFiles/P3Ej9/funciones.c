#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"

void ClearLine(char* StringToClear){
  //String to delete the \n
  char* position;
  if ((position = strchr(StringToClear,'\n'))!=NULL){
    *position = '\0';
  }
}

book* MakeArray(char* FileName){
  book* Library;
  int size = BookNumber(FileName);
  //var to load temporal data from file
  char buffer[100];
  int aux = 0;
  //Open file in read mode
  FILE *file;
  file = fopen (FileName,"r");
  if (file==NULL){
    printf("[-]Error abriendo el fichero\n");
    exit(-1);
  }
  //Create dinamic array,size will be the result of a function
  if (size >0){
    Library = calloc(size,sizeof(book));
    if (Library == NULL){
      printf("[-]La reserva de memoria ha fallado\n");
      exit(-1);
    }
    //Read the file and create the Dinamic Array

    while(!feof(file)){
      book TmpData;
      fgets(buffer,100,file);
      ClearLine(buffer);
      strcpy(TmpData.title,buffer);
      fgets(buffer,100,file);
      ClearLine(buffer);
      strcpy(TmpData.author,buffer);
      //Now int values
      fscanf(file,"%f\t%i\n",&TmpData.price,&TmpData.cant);
      *(Library+aux) = TmpData;
      aux++;
    }
    fclose(file);
    return Library;
  }
  else{
    printf("No existen libros en el stock\n");
  }


}

void PrintArray(char*FileName,book* Library){
  int size = BookNumber(FileName);
  for (int i = 0; i<size;i++){
     printf("Titulo: %s\n",(Library+i)->title);
     printf("Autor: %s\n",(Library+i)->author);
     printf("Precio: %f\t",(Library+i)->price);
     printf("Cantidad: %i\n",(Library+i)->cant);
  }
}

int BookNumber(char* FileName){
  int Books=0;
  //tmp var
  char buffer[100];
  //Opening File
  FILE *file;
  file = fopen (FileName,"r");
  if (file==NULL){
    printf("[-]Error abriendo el fichero\n");
    exit(-1);
  }
  //Count the title fields on file
  while (fgets(buffer,100,file)!=NULL) {
    Books++;
    fgets(buffer,100,file);
    fgets(buffer,100,file);
  }
  //Close the file
  fclose(file);
  return Books;

}

int CheckNoTitle(char* FileName,char* Title){
  //Check the title doesn't exits
  int size=BookNumber(FileName);
  if (size != 0 ){
    book* Library;
    Library = MakeArray(FileName);
    for(int i =0;i<size;i++){
      ClearLine(Title);
      if( (strcmp(Title,(Library+i)->title) )==0){
        free(Library);
        return 1;
      }
    }
    free(Library);
    return 0;
  }
}

void AddBook(char* FileName){
  //Function to add a new book
  book TmpData;
  printf("[?]Introduce el titulo:");
  setbuf(stdin,NULL);
  fgets(TmpData.title,100,stdin);
  printf("[?]Introduce el autor:" );
  fgets(TmpData.author,100,stdin);
  printf("[?]Introduce la cantidad:");
  setbuf(stdin,NULL);
  scanf("%i",&TmpData.cant );
  setbuf(stdin,NULL);
  printf("[?]Introduce el precio:");
  scanf("%f",&TmpData.price );
  //Check the title

  if(CheckNoTitle(FileName,TmpData.title)== 0){
    char buffer[100];
    FILE *file;
    file = fopen (FileName,"a");
    if (file==NULL){
      printf("[-]Error abriendo el fichero\n");
      exit(-1);
    }
    ClearLine(TmpData.title);
    sprintf(buffer,"%s\n",TmpData.title);
    fputs(buffer,file);
    fputs(TmpData.author,file);
    sprintf(buffer,"%f\t%i\n",TmpData.price,TmpData.cant);
    fputs(buffer,file);
    fclose(file);
  }
  else{
    printf("[-]El libro ya esta agregado\n");

  }

}

void WriteLibrary(char* FileName,book* Library,int size){
  char buffer[100];
  //Clear FILE
  FILE *file;
  file = fopen (FileName,"w");
  if (file!=NULL){
    fclose (file);
  }
  else{
    printf("[!]Error abriendo el fichero\n");
    exit(-1);
  }
  //Write New Library
  for (int i = 0;i<size;i++){
    FILE *file;
    file = fopen (FileName,"a");
    if (file==NULL){
      printf("Fallo al abrir el fichero\n");
      exit(-1);
    }
    sprintf(buffer,"%s\n",(Library+i)->title);
    fputs(buffer,file);
    sprintf(buffer,"%s\n",(Library+i)->author);
    fputs(buffer,file);
    sprintf(buffer,"%f\t%i\n",(Library+i)->price,(Library+i)->cant);
    fputs(buffer,file);
    fclose(file);

  }


}

void SellBook (char* FileName){
  book* Library;
  int size;
  char title[100];
  printf("Introduce el titulo para vender:" );
  setbuf(stdin,NULL);
  fgets(title,100,stdin);
  if ((CheckNoTitle(FileName,title))) {
    Library = MakeArray(FileName);
    size = BookNumber(FileName);
		if (size != 0 ){
	    for (int i = 0;i<size;i++){
  	    if(strcmp((Library+i)->title,title) == 0){
    	    if((Library+i)->cant >0){
      	    (Library+i)->cant = (Library+i)->cant -1 ;
        	}
	        else{
  	        printf("[!]El libro no tiene existencias\n");
    	    }
      	}
    	}
			WriteLibrary(FileName,Library,size);
	   	free(Library);
			CheckBooks(FileName);
	 }
		else{
			printf("No existen libros en stock\n");
		}

  }

}

void CheckBooks(char* FileName){
  book* Library;
  book* NewLibrary;
  int size = BookNumber(FileName);
  NewLibrary = calloc(size,sizeof(book));
  int aux = 0;
  FILE *file;
  file = fopen (FileName,"r");
  if (file==NULL){
    printf("[!]Error abriendo el fichero");
    exit(-1);
  }

  Library = MakeArray(FileName);
  for (int i = 0; i<size;i++){
    if ( ( (Library+i)-> cant ) > 0 ){
      *(NewLibrary+aux) = *(Library+i);
      aux++;
    }
  }
  //WriteLibrary(FileName,NewLibrary,aux+1);
  NewLibrary = realloc(NewLibrary,aux);
  WriteLibrary(FileName,NewLibrary,aux);
  free(NewLibrary);
  free(Library);
}
int ExistBook(char* NombreFichero){
  char Title[100];
  printf("Introduce el titulo: ");
  setbuf(stdin,NULL);
  fgets(Title,100,stdin);
  if (CheckNoTitle(NombreFichero,Title) == 1){
    return 1;
  }
  else{
    return 0;
  }
}
void Menu(char* FileName){
  int choose=-1;
  char buffer[100];
  book* Library;
  if (access (FileName,F_OK) == -1){
    FILE *f;
    f = fopen (FileName,"w");
    if (f!=NULL){
      fclose (f);
    }
  }
  while(choose != 7 ){
    printf("##############################################\n");
    printf("## 1.- Comprobar la existencia de un libro  ## \n");
    printf("## 2.- Agregar libro                        ##\n");
    printf("## 3.- Contar libros                        ##\n");
    printf("## 4.- Listar libros                        ##\n");
    printf("## 5.- Vender libro                         ##\n");
    printf("## 6.- Borrar libros agotados               ##\n");
    printf("## 7.- Salir                                ##\n");
    printf("##############################################\n");
    printf(":>");
    setbuf(stdin,NULL);
    scanf("%i",&choose);
    switch (choose) {
      case 1:
        if(ExistBook(FileName)==1){
          printf("El libro existe\n");
        }
        else{
          printf("El libro no existe\n");
        }
        break;
      case 2:
        AddBook(FileName);
        break;
      case 3:
        printf("Total de libros %i \n",BookNumber(FileName));
        break;
      case 4:
        Library = MakeArray(FileName);
        PrintArray(FileName, Library);
        break;
      case 5:
        SellBook(FileName);
        break;
      case 6:
        CheckBooks(FileName);
        break;
    }
  }


}
