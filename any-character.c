#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter string Size: ");
    scanf("%d",&n);
    char arr[n+1];
    printf("Enter Character: ");
    for(i=0;i<n;i++)
    {
        scanf(" %c",&arr[i]);
    }

    char swap;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    char x;
    printf("Enter Searching Character: ");
    scanf(" %c",&x);
    printf("The sorting Character: ");
    for(i=0;i<n;i++)
    {
        printf("%c ",arr[i]);
    }
    int mini=0;
    int maxi=n-1;
    int mid;
    while (mini<=maxi)
    {

         mid = mini + (maxi-mini)/2;
         if(arr[mid]==x){
            printf("\ncharacter Found. Index-%d\n",mid);
            break;
         }
         else if(arr[mid]<x){
            mini=mid+1;
         }
         else{
            maxi=mid-1;
       }

    }
    if(arr[mid]!=x){
        printf("\nCharacter Not Found!\n");
    }
    
}
