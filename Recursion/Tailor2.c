#include<stdio.h>
// Tailors series using recursion !
double tailor(int x, int n){
    double s = 1.0000;
    if(n==0){
        return s;
    }else{
        for(;n>0;n--){
            s=(1+x/n)*s;
        }
        return s;
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