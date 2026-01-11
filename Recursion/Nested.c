#include<stdio.h>
// Nested Recursion
int func(int n){
    if(n>100){
        return n-10;
    }
    return (func(func(n+11)));
    
}

int main(){

    int n = 95;
    int r;
    r = func(n);
    printf("%d\n",r);
    return 0;
}