#include <stdio.h>
#include <stdlib.h>


int AlgoEuclides(int num1, int num2){
    if ( num1 == 0 ){
        return num2;
    }
    if ( (num2 > 0) && (num1>=num2) ){
        return AlgoEuclides(num2%num1,num1);
    }
}

int main(){
    int num2 =99, num1=101;
   printf("%i", AlgoEuclides(num1,num2));
}
