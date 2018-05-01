#include <stdio.h>
#include <stdio.h>
#include <string.h>




int main(){
    char cadena[100];
    
    printf("introduce una cadena por teclado\n");
    fgets(cadena,100,stdin);
    printf("Cadena:\t%s",cadena);
    printf("%i\n",cadena[0]);
    for (int i =0 ; i<(strlen(cadena))+1;i++){
        printf("%i\n",cadena[i]);
    }
}
