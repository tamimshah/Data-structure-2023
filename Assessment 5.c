#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 5
int stack[max];
int top = -1;
void push(int data);
int pop(); void print();
int main()//ID. 222-35-1141
{         //MD.TAHMID SHAH TAMIM
int choice, data;
while (1)
{
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Print all the elements of the stack\n");
printf("4.Quit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter the element to be pushed : ");
scanf("%d", &data);
push(data);
break;
case 2:
data = pop();
printf("Deleted Element is %d\n", data);
break;
case 3:
print();
break; case 5:
exit(1);
default:
printf("Wrong Choice\n");
break;
}
}
return 0;
}
void push(int data)
{
if (top == max - 1)
{
printf("Overflow should be checked");
return;
}
top = top + 1;
stack[top] = data;
}
int pop()
{
if (top == -1)
{
printf("Underflow should be checked");
exit(1);
} int value;
value = stack[top];
top = top - 1;
return value;
}
void print()
{
int i;
if (top == -1)
{
printf("stack underflow");
return;
}
for (i = top; i >= 0; i--)
{
printf("%d ", stack[i]);
printf("\n");
} }
