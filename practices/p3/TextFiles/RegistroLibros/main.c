#include "funciones.h"

int main(int argc, char const *argv[]){
  libro* Library = BookArray("fichero.txt");
  //AddBook("fichero.txt");
  //Searchbook("fichero.txt","asd");
  //CountBooks("fichero.txt");
  //BookArray("fichero.txt");
  Library = SellBook("fichero.txt","titulo2");
  PrintVector("fichero.txt",Library);
  return 0;
}
