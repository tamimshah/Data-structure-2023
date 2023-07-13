#include<stdio.h>
int main()
{
    int arr[15],n,i,j,tmp,target,count1=1,count2=1;
    printf("enter array size less than or equal to 15: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("enter %d element of array: ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[j] <arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("enter search element: \n");
    scanf("%d",&target);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == target){
            break;
        }
        count1++;
    }
    
    int minimum,maximum,middle;
    minimum=0;
    maximum=n-1;
    middle=(maximum+minimum)/2;
    
    while (minimum <= maximum) {
    if (arr[middle] < target)
      minimum = middle + 1;
    else if (arr[middle] == target) {
      break;
    }
    else{
      maximum = middle - 1;
    }
    middle = (minimum + maximum)/2;
    count2++;
  }
    printf("searched element %d found in %d binary search and %d liner search\n",target,count2,count1);
}

