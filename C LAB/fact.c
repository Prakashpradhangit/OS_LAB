#include<stdio.h>

int fun(int a, int b);

int main(){
    int a,b;
   printf("enter a and b");
   scanf("%d %d", &a, &b );
   printf("sum is %d" );
   
}

int fun(int a, int b){
    int sum = a+b;
    return sum;
}