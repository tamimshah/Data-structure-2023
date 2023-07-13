#include <stdio.h> //MD.TAHMID SHAH TAMIM
#define MAX_SIZE 10 //222-35-1141
int main() {
    int array[MAX_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = 10;
    int index1, index2, index3;

    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the index of the first number to delete (0-%d): ", size - 1);
    scanf("%d", &index1);

    if (index1 < 0 || index1 >= size) {
        printf("Invalid index!\n");
        return 0;
    }

    for (int i = index1; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    if (size == 0) {
        printf("Underflow! Array is now empty.\n");
        return 0;
    }

    printf("Array after deleting the first number: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the index of the second number to delete (0-%d): ", size - 1);
    scanf("%d", &index2);

    if (index2 < 0 || index2 >= size) {
        printf("Invalid index!\n");
        return 0;
    }

    for (int i = index2; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    if (size == 0) {
        printf("Underflow! Array is now empty.\n");
        return 0;
    }

    printf("Array after deleting the second number: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the index of the third number to delete (0-%d): ", size - 1);
    scanf("%d", &index3);

    if (index3 < 0 || index3 >= size) {
        printf("Invalid index!\n");
        return 0;
    }

    for (int i = index3; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;

    if (size == 0) {
        printf("Underflow! Array is now empty.\n");
        return 0;
    }
    printf("Array after deleting all three numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
