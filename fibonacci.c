#include<stdio.h>

int FIB[20];

int fib(int n){
    if(n<=1)
    return n;

    FIB[0]=0;
    FIB[1]=1;

    for(int i=2 ; i<=n ; i++){

        FIB[i] = FIB[i-1]+FIB[i-2];
    } 

    return FIB[n];
}

int Recursive(int n){
    if(n<=1)

    return n;

    else
    {
        return fib(n-1)+fib(n-2);
    }
    
}

int main(){
    printf(" %d :: %d",fib(7),Recursive(7));
}