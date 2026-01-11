#include<stdio.h>
// Head Recursion
int func(int n){
    if(n>0){
        func(n-1);
        printf("%d \n",n);
    }
}

int main(){

    int n = 4;
    func(n);
    return 0;
}