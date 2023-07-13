#include<stdio.h>
 int main(){

     int n;
     printf("Enter Array Size: ");
     scanf("%d",&n);
     printf("Enter Array Element: ");
     int i,arr[n];
     for(i=0;i<n;i++){
         scanf("%d",&arr[i]);
     }
     int j,swap;
     for(i=0;i<n-1;i++){
         for(j=0;j<n-1-i;j++){
             if(arr[j]>arr[j+1]){
                 swap=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j]=swap;
             }
         }
     }

     printf("Ascending Array Element is: ");
     for(i=0;i<n;i++){
         printf("%d ",arr[i]);
     }
     int s,count=0;
     printf("\nSeraching Array: ");
     scanf("%d",&s);
     for(i=0;i<n;i++){
        count=count+1;
         if(arr[i]==s){
             printf("Element Found.Index-%d\nTotal Count-%d",i,count);
             return 0;
         }
     }
        printf("Sorry Element Not Found!!!");

 }
