#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int main() {
    char name[MAX_LENGTH];
    char teacher[MAX_LENGTH];
    char searchChar = 'j';
    int nameLength, teacherLength;
    int count = 0;
    int i;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your teacher's name: ");
    scanf("%s", teacher);
    nameLength = strlen(name);
    teacherLength = strlen(teacher);
    for (i = 0; i < nameLength; i++) {
        if (name[i] == searchChar) {
            count++;
        }
    }
    for (i = 0; i < teacherLength; i++) {
        if (teacher[i] == searchChar) {
            count++;
        }
    }
    if (count > 0) {
        printf("The character '%c' is present %d time(s).\n", searchChar, count);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
