#ifndef FUNCIONES_H
#define FUNCIONES_H
typedef struct N{
    int num;
    int times;
}number;
int* BuildArray(int* size);
void FillArray(int* array,int* size);
void printArray(int* array,int* size);
number *countTimes(int* array,int*size);
void PrintcountTimes(number* numberArray,int*size);
number* MakeNumberArray(int* size);
int CheckArray(number* array,int*size);
void DeleteNumber(int* array,int*size, int number);
#endif
