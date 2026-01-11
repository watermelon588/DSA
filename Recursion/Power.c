#include<stdio.h>
// power function
int power1(int m , int n ){
    if(m < 0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(n>0){
        return power1(m, n-1)*m;
    }
}
// less number of multiplication
int power2(int m , int n ){
    if(m < 0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(n>0){
        if(n%2 == 0){
            return power2(m*m,n/2);
        }
        else{
            return m*power2(m*m,(n-1)/2);
        }
        
    }
}

int main (){
    int m , n ;
    int r1, r2;
    printf("Enter m:");
    scanf("%d",&m);
    printf("Enter n:");
    scanf("%d",&n);
    r1 = power1(m,n);
    r2 = power2(m,n);
    printf("\n%d\n",r1);
    printf("____________________\n");
    printf("\n%d\n",r1);
    return 0;
}