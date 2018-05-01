#include <stdio.h>



int main(){
    int a = 19;
    int* b;

    b = &a;
    printf ("A Memory Address: %p \n",&a);
    printf ("A Memory Address: %p\n ", b);
    printf ("B Memory Address: %p\n",&b);
    printf ("A Value:%d \n",*b);
}
