#include <stdio.h>
#include <string.h>
//ID. 222-35-1141
int main() {
    int n;
    printf("Enter the number of array: ");
    scanf("%d", &n);
    char arr[n];
    printf("Enter the elements in descending order: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }
    char key;
    printf("Enter the search key: ");
    scanf(" %c", &key);
    int low = 0;
    int high = n-1;
    int found = -1;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            found = mid;
            break;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found == -1) {
        printf("Element is not Found in the array\n");
    } else {
        printf("Element is Found at index %d\n", found);
    }
    return 0;
}
