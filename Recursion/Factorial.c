#include<stdio.h>

int fact(int n){
    if(n<0){
        return 0;
    }
    if(n==0 || n==1){
        return 1;
    }
    else
    {
        return fact(n-1)*n;
    }
    
}

int main(){
    int n;
    printf("enter number: ");
    scanf("%d",&n);
    int r = fact(n);
    printf("%d\n",r);
    return 0;
}