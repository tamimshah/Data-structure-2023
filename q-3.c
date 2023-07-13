#include<stdio.h> //ID.222-35-1141
#include<string.h> //Md. Tahmid Shah Tamim
int main() {
 char stabing[] = {'s', 't', 'a', 'b', 'i', 'n', 'g'};
 int top = 6;
 top -= 3;
 while (top >= 0) {
 printf("%c ", stabing[top]);
 top--;
 }
 return 0;
}
