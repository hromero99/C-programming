#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeArray(int min, int max, int size){
    int* Array;
    Array = calloc(size,sizeof(int));
    if(Array == NULL){
        printf("[!]Fallo al reservar memoria");
        exit(-1);
    }
    srand(time(NULL));
    for (int i = 0; i<size;i++){
        *(Array+i) = rand()%(max+1 - min) ;
        printf("%i\t",*(Array+i));
    }
    return Array;
}
void writeFile(char* filename, int nEle,int min,int max){
    FILE* file;
    int* array = makeArray(min,max,nEle);
    file = fopen(filename,"wb");
    if (file == NULL){
        printf("[!]Fallo al crear el fichero");
        exit(-1);
    }

    fwrite(array,sizeof(int),nEle,file);
    fclose(file);
}
