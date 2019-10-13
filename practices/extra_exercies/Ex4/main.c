#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char const *argv[]) {
  char BinaryFilename[100];
  char TextFilename[100];
  int LibrarySize=12;
  BookData* library;
  if (argc != 3){
    printf("Usage: ./a.out BinaryFile TextFile\n");
    exit(-1);
  }
  strcpy(BinaryFilename,argv[1]);
  strcpy(TextFilename,argv[2]);
  //WriteBinaryFile(BinaryFilename,&LibrarySize);
  library = ReadFileContent(BinaryFilename,&LibrarySize);
  OrdenaLibrary(library,&LibrarySize);
  WriteTextFile(TextFilename,&LibrarySize,library);
  return 0;
}
