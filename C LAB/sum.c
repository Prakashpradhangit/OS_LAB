#include<stdio.h>

int sum(int a, int b );
int sub(int a, int b );
int multi(int a, int b );
int div(int a, int b );




int main(){
    int a,b;
    printf("enter a and b \n");
    scanf("%d %d", &a, &b);
    printf("sum is : %d \n",sum(a,b) );
    printf("substraction is : %d  \n",sub(a,b) );
    printf("multiplication is : %d \n",multi(a,b) );
    printf("division is : %d \n",div(a,b) );

    
    // return 0;
}

int sum(int a, int b ){
    int sum;
    sum = a+b;
    return sum;
}


int sub(int a, int b ){
    int sub;
    sub = a-b;
    return sub;
}
int multi(int a, int b ){
    int sub;
    sub = a*b;
    return sub;
}
int div(int a, int b ){
    int sub;
    sub = a/b;
    return sub;
}




