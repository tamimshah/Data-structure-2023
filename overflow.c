#include <stdio.h>
int main() {
    int arr[100];
    int n, num1, num2, pos1, pos2;
    printf("Enter array Size: ");
    scanf("%d",&n);
    printf("Enter %d elements: ", n);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    printf("Enter two index Number: ");
    scanf("%d %d",&pos1,&pos2);

    if (pos1>=n || pos2>=n) {
        printf("Error:Position exceeds array size.Try Again.\n");
        return 1;
    }
    arr[pos1] = num1;
    arr[pos2] = num2;

    printf("Array after inserting:\n");
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

