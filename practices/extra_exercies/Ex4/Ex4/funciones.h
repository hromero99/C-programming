#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct libro{
  char title[100];
  char autor[100];
  int cantidad;
  float precio;
}BookData;

BookData* MakeBookArray(int* Booksize);
void WriteBinaryFile(char* BinaryFile, int*BookSize);
BookData* ReadFileContent (char* BinaryFile,int*size);
void OrdenaLibrary(BookData* library, int* size);
void WriteTextFile(char* TextFile, int*size, BookData* library);
#endif
