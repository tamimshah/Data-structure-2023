#include <stdio.h>
//ID.222-35-1141
int main () {

   int a[10],n;
   int i;

   printf("Enter a number less than 11 : ");
   scanf("%d",&n);
   if(n>10)
    return 0;

   printf("Enter %d elements for the array : ",n);
   for ( i = 0; i < n; i++ ) {
      scanf("%d",&a[i]);
   }
   printf("Inserted elements of the array : \n");
   for (i = 0; i < n; i++ ) {
      printf("Element[%d] = %d\n", i, a[i] );
   }

   return 0;
}
