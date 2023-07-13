#include<stdio.h>
int main(){
    int a,i;
    printf("Enter Array Size: ");
    scanf("%d",&a);
    int arr[a];
    printf("Enter desending %d Element: ",a);
    for(i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int search,mid;
    int mini=0;
    int maxi=a-1;
    printf("Enter The Search Element: ");
    scanf("%d",&search);
    while (mini<=maxi)
    {
       mid=(mini+maxi)/2;
       if (arr[mid]==search)
       {
         printf("Element Found.Index-%d",mid);
         return 0;
       }
        else if(arr[mid] <search){
        mini=mid+1;
       }
       else{
        maxi=mid-1;
       }    
    }
    printf("Element Not Found!");

}