#include<stdio.h>
main()
{
    int n,i,value,posi=-1;
    int arr[100];
    printf("Enter Array Size:");
    scanf("%d",&n);
    printf("Enter Find Element:");
    scanf("%d",&value);
    printf("Enter the Element: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(value==arr[i]){
            posi=i+1;
            break;
        }
    }if(posi == -1){
        printf("Sorry! Element Not Found");
    } else
    printf("The %d Value Find Position %d .",value,posi);

}