#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct libro{
  char titulo[100];
  char autor[50];
  float precio;
  int unidades;
}bookData;
void AddNewBook(char* filename);
bookData getbook();
int SearchBook(char*filename);
int CountBooks(char* filename);
#endif
