/**
@file funciones.h
@author Hector Romero Lopez
@date Indeterminada
@version ¿1.X?

Fichero que contiene las funciones para trabajar con un registro de libros, contiene las funcioes que permiten:
@li Agregar libros
@li Comprobar existencia de libros
@li Mostrar el stock de libros
@li Contar el numero de libros
@li Eliminar libros con existencias agotadas
@li Vender libros

*/
#ifndef FUNCIONES_H
#define FUNCIONES_H

/**
@struct BookData
@brief Estructura para almacenar los datos del libro
Estructura creada que contiene informacion detallada (Titulo, autor, cantidad y precio) de un determinado libro
*/
/**
@typedef book
@brief definicion de struct BookData
Creacion del tipo book para trabajr con mayor comodidad en las estructuras
*/
typedef struct BookData{
  char title[100];
  char author[100];
  float price;
  int cant;
}book;
/**
@fn book* MakeArray(char* FileName)
@brief Funcion para crear vector de libros
@param FileName Nombre del fichero existente en disco
@return Vector de tipo book* con el contenido de los libros en stock
*/
book* MakeArray(char* FileName);
/**
@fn void ClearLine(char* StringToClear)
@brief Funcion para eliminar los saltos de linea
@param StringToClear Linea para limpiar
@return void
*/
void ClearLine(char* StringToClear);
/**
@fn void PrintArray(char*FileName,book* Library)
@brief Funcion para imprimir el contenido de un vector de libros generado anteriormente
@param FileName Nombre del fichero existente en disco
@param Library Vector para imprimir
@return void, imprime informacion por pantalla
*/
void PrintArray(char*FileName,book* Library);
/**
@fn int BookNumber(char* FileName)
@brief Devuelve la cantidad de libros existentes en stock
@param FileName Nombre del fichero existente en disco
@return Cantidad de libros existentes
*/
int BookNumber(char* FileName);
/**
@fn int CheckNoTitle(char* FileName,char* Title)
@brief Funcion que compueba la existencia de un Titulo
@param FileName Nombre del fichero existente en disco
@param Title titulo del libro que buscamos
@return valor entero (1 si existe el titulo, 0 si no existe)
*/
int CheckNoTitle(char* FileName,char* Title);
/**
@fn void AddBook(char* FileName)
@brief Funcion para agregar un libro al stock
@param FileName Nombre del fichero existente en disco
@return void, los cambios son escritos en el fichero
*/
void AddBook(char* FileName);
/**
@fn void SellBook (char* FileName)
@brief Funcion para vender libros
@param FileName Nombre del fichero existente en disco
@return void, se reduce en 1 unidad el titulo vendido
*/
void SellBook (char* FileName);
/**
@fn void WriteLibrary(char* FileName,book* Library,int size);
@brief Funcion para escribir el archivo en libreria, paritendo de un vector de estructuras
@param FileName Nombre del fichero existente en disco
@param Library Vector de estructuras con los libros
@param size longitud del vector para escribir
@return void, los cambios se realizan en el fichero
*/
void WriteLibrary(char* FileName,book* Library,int size);
/**
@fn void CheckBooks(char* FileName)
@brief Fucnion para eliminar los libros que no tienen existencias
@param FileName Nombre del fichero existente en disco
@return void, en el fichero los libros sin existencias son eliminadas
*/
void CheckBooks(char* FileName);
/**
@fn int ExistBook(char* NombreFichero)
@brief Funcion para comprobar la existencia de libros por el usuario
@param FileName Nombre del fichero existente en disco
@return valor entero (1 si existe el titulo, 0 si no existe)
*/
int ExistBook(char* NombreFichero);
/**
@fn void Menu(const char* FileName)
@brief Menu
@param FileName Nombre del fichero existente en disco
@return imprime el menu por pantalla
*/
void Menu(char* FileName);
#endif
