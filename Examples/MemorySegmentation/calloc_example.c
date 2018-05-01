#include <stdio.h>
#include <stdlib.h>

int main () {
   int i, n;
   int *a;
   printf("%f\n",*a );
   printf("%p\n",&a );
   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));

   printf("%p\n",&a );
   printf("%d\n",*a );

  free(a);
   return(0);
}
