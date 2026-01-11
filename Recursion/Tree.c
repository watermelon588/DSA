#include<stdio.h>
// Tree recursion

int func(int n){
    if(n>0){
        printf("%d \t", n);
        func(n-1);
        func(n-1);
    }
}

int main(){
    int n = 4;
    func(n);
    return 0;
}