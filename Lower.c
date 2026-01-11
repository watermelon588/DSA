///// ROW MAJOR FORMULA

#include<stdio.h>
#include<stdlib.h>

// creating matrix structure
struct mat {
    int *A;
    int n;
};
// set lower triangular matrix
void set(struct mat *m,int i,int j,int x){
    if (i>=j)
    {
        m->A[(i*(i-1))/2+(j-1)] = x;
    }   
}
// get lower triangular matrix
int get(struct mat m,int i,int j){
    if (i>=j)
    {
       return m.A[(i*(i-1))/2+(j-1)];
    }
    else{
        return 0;
    }
}
// display matrix function
void display(struct mat m){
    int i , j ;
    for ( i = 1; i <= m.n; i++){
        for ( j = 1 ; j<=m.n; j++){
            if(i>=j){
                printf("%d ",m.A[(i*i-1)/2+(j-1)]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }    
}
//main function
int main (){

    int i , j , x;

    struct mat m;
    printf("Enter the dimension of matrix: ");
    scanf("%d",&m.n);
    // matrix array creation!
    m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));

    // taking inputs
    printf("Enter the elements: ");
    scanf("%d",&x);
    for ( i = 1; i <=m.n ; i++)
    {
        for ( j = 1; j <= m.n ; j++)
        {
            scanf("%d ",&x);
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    display(m);
    
    return 0;
}

///// COLUMN MAJOR FORMULA

// #include<stdio.h>
// #include<stdlib.h>

// // creating matrix structure
// struct mat {
//     int *A;
//     int n;
// };
// // set upper triangular matrix
// void set(struct mat *m,int i,int j,int x){
//     if (i>=j)
//     {
//         m->A[(m.n*(j-1)-(j-2)*(j-1)/2+(i-j))] = x;
//     }   
// }
// // get upper triangular matrix
// int get(struct mat m,int i,int j){
//     if (i>=j)
//     {
//        return m.A[(m.n*(j-1)-(j-2)*(j-1)/2+(i-j))];
//     }
//     else{
//         return 0;
//     }
// }
// // display matrix function
// void display(struct mat m){
//     int i , j ;
//     for ( i = 1; i <= m.n; i++){
//         for ( j = 1 ; j<=m.n; j++){
//             if(i>=j){
//                 printf("%d ",m.A[(i*i-1)/2+(j-1)]);
//             }else{
//                 printf("0 ");
//             }
//         }
//         printf("\n");
//     }    
// }
// //main function
// int main (){

//     int i , j , x;

//     struct mat m;
//     printf("Enter the dimension of matrix: ");
//     scanf("%d",&m.n);
//     // matrix array creation!
//     m.A = (int *)malloc(m.n*(m.n+1)/2 * sizeof(int));

//     // taking inputs
//     printf("Enter the elements: ");
//     scanf("%d",&x);
//     for ( i = 1; i <=m.n ; i++)
//     {
//         for ( j = 1; j <= m.n ; j++)
//         {
//             scanf("%d ",&x);
//             set(&m,i,j,x);
//         }
//     }
//     printf("\n\n");
//     display(m);
    
//     return 0;
// }