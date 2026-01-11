#include<stdio.h>
#include<stdlib.h>

// creating matrix structure
struct mat {
    int A[10];
    int n;
};
// set matrix diagonals
void set(struct mat *m,int i,int j,int x){
    if(i==j){
        m -> A[i-1] = x;
    }
}
// get matrix diagonals
int get(struct mat m,int i , int j){
    if(i == j){
        return  m.A[i-1];
    }
    else{
        return 0;
    }
}
// display matrix
void display(struct mat m){
    int i ,j;
    for (i=0;i<m.n;i++)
    {
        for(j=0;j<m.n;j++){
            if(i == j){
                printf("%d ",m.A[i]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }  
}
//

// main function
int main (){

    struct mat m;
    m.n = 4;

    set(&m,1,1,25);
    set(&m,2,2,50);
    set(&m,3,3,75);
    set(&m,4,4,100);

    printf("%d \n",get(m,4,4));

    display(m);

    return 0;
}
