#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define  SIZE 10

void FillVector(int vector[]){

    for (int i=0;i<SIZE;i++){
        srand(time(NULL));
        *(vector+i)=rand()%2;
         }
}

int main(){
    int vector[SIZE];
    FillVector(vector);    
    for (int i = 0; i<SIZE;i++){
        printf("%i\n",vector+i);
    }

    return 0;
}
