 #include<stdio.h>
 int main()
 {
    int n,i;
    printf("Enter Array Size: ");
    scanf("%d",&n);
    while (1)
    {
        if(n>15)
        {
            printf("Wrong Input.Please Enter Correct Input: ");
            scanf("%d",&n);
            
        }else{
            break;
        }
    }
    int arr[n];
    printf("Enter %d Element: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array %d Element is: ",n);
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
 }