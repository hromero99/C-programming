#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main(int argc, char const* argv[]){
	char file[100];
	int nEle,min,max;
    if (argc != 5){
		printf("[!]Usage: ./a.out filename elements max min \n");
		exit(-1);
	}
	strcpy(file,argv[1]);
    nEle = atoi(argv[2]);
    max =atoi(argv[3]);
    min =atoi(argv[4]);
    writeFile(file,nEle,min,max);
    return 0;
}
