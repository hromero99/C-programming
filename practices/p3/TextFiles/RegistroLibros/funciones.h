#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct DatosLibro{
  char nombre[100];
  char autor[100];
  int cantidad;
  int precio;
}libro;

void AddBook(char* NombreFichero);
void Searchbook(char* NombreFichero,char* Title);
void ClearString(char* StringToClear);
int CountBooks(char* NombreFichero);
libro* BookArray(char* NombreFichero);
libro* SellBook(char* NombreFichero,char* Title);
void PrintVector(char* NombreFichero,libro* Library);


#endif
