#include <stdio.h>
#include <stdlib.h>

int main () {
   char *str;


   str = (char *) malloc(15);
   strcpy(str, "cyberh99");
   printf("String = %s,  Address = %p\n", str, str);


   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %p\n", str, str);

   free(str);

   return(0);
}
