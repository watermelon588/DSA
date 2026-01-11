#include<stdio.h>
// Tail recursion
void func( int n){
    if(n>0){
        printf("%d \n",n);
        func(n-1);    
    }
}

int main(){
    int n=4;
    func(n);
    return 0;
}