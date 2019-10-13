#include <stdio.h>


void PrintNumbers(){
    for (int i = 0;i<11;i++){
        printf("%d\t",i);
    }
}

int Module(int number1, int number2){
    int aux = number1%number2;
    return aux;
}

int main(){
    int number1 = 10, number2=9;
    PrintNumbers();
    printf("\n Module: %d \n",Module(number1,number2));
    return 0;
}
