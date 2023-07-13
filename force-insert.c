#include <stdio.h>
 int main()
 {
     int n,i, array[10];

    while (1) {
    printf("Enter value of Size(less than 10): ");
    scanf("%d",&n);

    if (n<10) {
      break;
    }
    printf("Invalid input. Try again.\n");
  }

  printf("Enter Array Element: ");
  for(i=0;i<n;i++)
  {
      scanf("%d",&array[i]);
  }

  printf("Enter Array Is: ");
  for(i=0;i<n;i++)
  {
      printf("%d ",array[i]);
  }

  return 0;
}
