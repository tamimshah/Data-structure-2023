#include<stdio.h>
#include<string.h>
int main()
{
    int arr[10];
    int num,character=0;
    do
    {   printf("Enter array size less than or equal to 10: ");
        character = scanf("%d",&num);
        while(character!=1)
        {
            printf("Error! This not Number.\n");
            scanf("%*[^\n]");
            printf("Enter a number less than 10: ");
            character = scanf("%d",&num);
        }
    }while (num>10);
    for (int i=0; i<num; i++)
    {
        printf("Enter %d element: ",i);
        scanf("%d",&arr[i]);
    }
    printf("The array is: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
}


