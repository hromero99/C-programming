#include <stdio.h>
#include <stdlib.h>


int Algorithm(int dividendo,int divisor){
    
    if (dividendo < divisor){
        return 0;
    }
    else{  
        dividendo = dividendo - divisor;
        return Algorithm(dividendo,divisor) +1; 
    }
}

int main(){
    int dividendo = 10, divisor= 5;
    printf("\n%i\n",Algorithm(dividendo,divisor));

    return 0;
}
