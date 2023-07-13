#include <stdio.h>
int main()
{
  int arr[100];
  int n,num1,num2,pos1,pos2;

  printf("Enter size of array: ");
  scanf("%d",&n);

  printf("Enter array elements: ");
  for (int i=0; i<n; i++)
    {
      scanf("%d",&arr[i]);
    }

  printf("Enter first number: ");
  scanf("%d",&num1);
  printf("Enter index of first number: ");
  scanf("%d",&pos1);

  printf("Enter second number: ");
  scanf("%d",&num2);
  printf("Enter index of second number: ");
  scanf("%d",&pos2);


  for (int i=n-1; i>=pos1; i--)
    {
        arr[i+1]=arr[i];
    }
  arr[pos1]=num1;

  for (int i=n; i>=pos2;i--)
    {
        arr[i+1]=arr[i];
    }
  arr[pos2]=num2;

  printf("The array is: ");
  for (int i=0; i<n+2; i++)
    {
        printf("%d ",arr[i]);
    }

  return 0;
}
