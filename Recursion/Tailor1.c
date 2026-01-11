#include<stdio.h>
// Tailors series using recursion !
double tailor(int x , int n){
    static double p=1 , f=1;
    double r;
    if(n==0 ){
        return 1;
    }
    else{
        r=tailor(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

int main(){
    int x,n;
    double R;
    printf("Enter x:");
    scanf("%d",&x);
    printf("Enter n:");
    scanf("%d",&n);
    R=tailor(x,n);
    printf("Summation is: %lf\n",R);
    return 0;
}