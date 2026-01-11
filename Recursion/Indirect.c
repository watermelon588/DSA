#include<stdio.h>
// Indirect recursion
void B(int n);

void A(int n){
    if(n>0){
        printf("%d \t", n);
        B(n-1);
    }
}
void B(int n){
    if(n>0){
        printf("%d \t", n);
        A(n/2);
    }
}

int main(){
    int n = 21;
    A(n);
    return 0;
}