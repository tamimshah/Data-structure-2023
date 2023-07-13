#include<stdio.h>
int addition(int x, int y){
    int c;
    return c= x+y;
}
int Subtraction(int m, int n){
    int c;
    return c=m-n;
}
int multipication(int a, int b){
    int c;
    return c=a*b;
}// Use Function(Basic level)
int main(){
    int a,b;
    printf("Enter Two Numbers: ");
    scanf("%d %d",&a,&b);
    int result;
    result= addition(a,b);
    printf("The %d and %d Addition is: %d",a,b,result);
    result= Subtraction(a,b);
    printf("\nThe %d and %d Subtraction is: %d",a,b,result);
    result= multipication(a,b);
    printf("\nThe %d and %d multipication is: %d",a,b,result);
    return 0;
}