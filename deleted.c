#include <stdio.h>//ID.222-35-1141
#define MAX_SIZE 10
int main() {
int array[MAX_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int size = 10;
int index1, index2;
printf("Original Array: ");
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
printf("Array after deleting both numbers: ");
for (int i = 0; i < size; i++) {
printf("%d ", array[i]);
}
printf("\n");
return 0;
}
