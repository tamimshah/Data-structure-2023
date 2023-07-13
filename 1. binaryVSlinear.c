#include<stdio.h>
int main()
{
    int arr[15],n,i,j,tmp,target,count1=1,count2=1;
    printf("enter array size less than or equal to 10: ");
    scanf("%d",&n);
    for (i = 0; i<n; i++)
    {
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
    printf("Enter search element: \n");
    scanf("%d",&target);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == target){
            break;
        }
        count1++;
    }
    
    int mini,maxi,middle;
    mini=0;
    maxi=n-1;
    middle=(maxi+mini)/2;
    
    while (mini <= maxi) {
    if (arr[middle] < target)
      mini = middle + 1;
    else if (arr[middle] == target) {
      break;
    }
    else{
      maxi = middle - 1;
    }
    middle = (mini + maxi)/2;
    count2++;
  }
    printf("Search element %d found in %d Binary search and %d Liner search\n",target,count2,count1);
}
//Linear search is best for finding those specific elements.
