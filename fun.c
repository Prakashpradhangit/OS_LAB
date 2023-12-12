#include<stdio.h>

int prakash(int a,int b);

int main(){
    int a,b;
    printf("enter number a and b : ");
    scanf("%d %d", &a, &b);

    printf("sum is %d" , prakash(a,b));
}

int prakash(int a,int b){
    int sum  = a+b;
    return sum;
}