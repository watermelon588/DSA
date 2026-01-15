#include<stdio.h>
#include<stdlib.h>
//matrix creation
struct Matrix{
    int *A;
    int n;
    int size;
};
// Diagonal matrix ___________________________
    // get
    void get(struct Matrix mat,int pos[]){
        int i = pos[0];
        int j = pos[1];
        if(i == 0 || j == 0){
            printf("Not zero(0) base indexing !\n");
            return;
        }
        if(i<=mat.n && j<=mat.n){
            if (i==j){
                printf("Element in (%d,%d) is : %d \n",i,j,mat.A[i-1]);
            }else{
                printf("Element in (%d,%d) is : %d \n",i,j,0);
            }
        }else{
            printf("Position not found !\n");
        }    
    }
    // display
    void display(struct Matrix mat){
        int i,j;
        for(i=0;i<mat.n;i++){
            for(j=0;j<mat.n;j++){
                if(i==j){
                    printf("%d ",mat.A[i]);
                }else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
// Lower Triangular matrix ___________________________
    // get
    void Lowerget(struct Matrix mat,int pos[]){
        int i = pos[0];
        int j = pos[1];
        int idx = i*(i-1)/2+(j-1);     // row major formula
        if(i == 0 || j == 0){
            printf("Not zero(0) base indexing !\n");
            return;
        }
        if(i<=mat.n && j<=mat.n){
            if (i>=j){
                printf("Element in (%d,%d) is : %d \n",i,j,mat.A[idx]);
            }else{
                printf("Element in (%d,%d) is : %d \n",i,j,0);
            }
        }else{
            printf("Position not found !\n");
        }    
    }
    // display
    void Lowerdisplay(struct Matrix mat){
        int i,j,k=0;
        for(i=0;i<mat.n;i++){
            for(j=0;j<mat.n;j++){
                if(i>=j){
                    printf("%d ",mat.A[k++]);
                }else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
// Upper Triangular matrix ___________________________
    // get
    void Upperget(struct Matrix mat,int pos[]){
        int i = pos[0];
        int j = pos[1];
        int idx = j*(j-1)/2+(i-1);    // column major formula
        if(i == 0 || j == 0){
            printf("Not zero(0) base indexing !\n");
            return;
        }
        if(i<=mat.n && j<=mat.n){
            if (i<=j){
                printf("Element in (%d,%d) is : %d \n",i,j,mat.A[idx]);
            }else{
                printf("Element in (%d,%d) is : %d \n",i,j,0);
            }
        }else{
            printf("Position not found !\n");
        }    
    }
    // display
    void Upperdisplay(struct Matrix mat){
        int i,j,k=0;
        for(i=0;i<mat.n;i++){
            for(j=0;j<mat.n;j++){
                if(j>=i){
                    printf("%d ",mat.A[k++]);
                }else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
// symmetric matrix ___________________________
    // get
    void Symmetricget(struct Matrix mat,int pos[]){
        int i = pos[0];
        int j = pos[1];
        int idx1 = i*(i-1)/2+(j-1);    // row major formula
        int idx2 = j*(j-1)/2+(i-1);   // column major formula
        if(i == 0 || j == 0){
            printf("Not zero(0) base indexing !\n");
            return;
        }
        if(i<=mat.n && j<=mat.n){
            if (i<=j){
                printf("Element in (%d,%d) is : %d \n",i,j,mat.A[idx2]);
            }else{
                printf("Element in (%d,%d) is : %d \n",i,j,mat.A[idx1]);
            }
        }else{
            printf("Position not found !\n");
        }    
    }
    // display
    void Symmetricdisplay(struct Matrix mat){
        int i,j,idx;
        for(i=1;i<=mat.n;i++){
            for(j=1;j<=mat.n;j++){
                if(i<=j){
                    idx = j*(j-1)/2 + (i-1);
                }else {
                    idx = i*(i-1)/2 + (j-1);
                }
                printf("%d ", mat.A[idx]);
            }
            printf("\n");
        }
        printf("\n");
    }
// Tridiagonal Matrix ___________________________
    // get
    void Tridiagonalget(struct Matrix mat, int pos[]){
    int i = pos[0];
    int j = pos[1];
    int idx;

    if(i <= 0 || j <= 0 || i > mat.n || j > mat.n){
        printf("Invalid position!\n");
        return;
    }

    if(i - j == 1){ // lower diagonal
        idx = i - 2;
    }
    else if(i == j){ // main diagonal
        idx = (mat.n - 1) + (i - 1);
    }
    else if(j - i == 1){ // upper diagonal
        idx = (2 * mat.n - 1) + (i - 1);
    }
    else{
        printf("Element in (%d,%d) is: 0\n", i, j);
        return;
    }

    printf("Element in (%d,%d) is: %d\n", i, j, mat.A[idx]);
    }
    // display
    void Tridiagonaldisplay(struct Matrix mat){
    int i, j, idx;

    for(i = 1; i <= mat.n; i++){
        for(j = 1; j <= mat.n; j++){
            if(i - j == 1){
                idx = i - 2;
                printf("%d ", mat.A[idx]);
            }
            else if(i == j){
                idx = (mat.n - 1) + (i - 1);
                printf("%d ", mat.A[idx]);
            }
            else if(j - i == 1){
                idx = (2 * mat.n - 1) + (i - 1);
                printf("%d ", mat.A[idx]);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
    }
// Sparse Matrix ________________________________
    // structure
    struct Element{
        int i;
        int j;
        int x;
    };
    struct Sparse{
        int m;
        int n;
        int num;
        struct Element *ele;
    };
    // create sparse 
    void createSparse(struct Sparse *s){
        int i;
        printf("Enter dimentions (m,n):");
        scanf("%d%d",&s->m,&s->n);
        s->ele = (struct Element*)malloc(s->num*sizeof(struct Element));
        printf("Enter no. of elements:");
        scanf("%d",&s->num);
        printf("Enter %d elements with corresponding index (i,j,val):",s->num);{
            for(i=0;i<s->num;i++){
                scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
            }
        }
    };
    // display
    void Sparsedisplay(struct Sparse s){
        int i,j,k=0;
        for(i=0;i<s.m;i++){
            for(j=0;j<s.n;j++){
                if(i == s.ele[k].i && j == s.ele[k].j ){
                    printf("%d ",s.ele[k++].x);
                }else{
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
int main(){
    int i,choice,n,pos[2],no_ele;
    int ch5;
    struct Matrix mat;
    printf("Enter size of matrix for memory allocation:");
    scanf("%d",&mat.size);
    mat.A = (int *)malloc(mat.size * sizeof(int));
    do{
        printf("\n________________ MENU _________________\n");
        printf("1. Diagonal Matrix \n");
        printf("2. Lower Triangular Matrix\n");
        printf("3. Upper Triangular Matrix\n");
        printf("4. Symmetric Matrix\n");
        printf("5. Tridiagonal Matrix \n");
        printf("6. Sparse Matrix \n");
        printf("7. Exit \n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter size of matrix :");
            scanf("%d",&mat.n);
            printf("Enter %d Diagonal elemets :",mat.n);
            for(i=0;i<mat.n;i++){
                scanf("%d",&mat.A[i]);
            }
            int ch0;
            do{
            printf("1. GET(1 base indexing) \n");
            printf("2. DISPLAY \n");
            printf("3. EXIT \n");
            printf("Enter ( 1/2/3 )? :");
            scanf("%d",&ch0);
            
                switch (ch0)
                {
                case 1:
                    printf("Enter position (i , j):");
                    for(i=0;i<2;i++){
                        scanf("%d",&pos[i]);
                    }
                    get(mat,pos);
                    break;
                case 2:
                    printf("Diagonal matrix : \n");
                    display(mat);
                    break;
                case 3:
                    printf("exiting diagonal matrix ...");
                    break;
                default:
                    printf("Invalid input !\n");
                    break;
                }
            }while(ch0!=3);
            break;
        case 2:
            printf("Enter dimention of matrix :");
            scanf("%d",&mat.n);
            no_ele = mat.n*(mat.n+1)/2;
            printf("Enter %d Non-zero elemets :",no_ele);
            for(i=0;i<no_ele;i++){
                scanf("%d",&mat.A[i]);
            }
            int ch1;
            do{
            printf("1. GET(1 base indexing) \n");
            printf("2. DISPLAY \n");
            printf("3. EXIT \n");
            printf("Enter ( 1/2/3 )? :");
            scanf("%d",&ch1);
            
                switch (ch1)
                {
                case 1:
                    printf("Enter position (i , j):");
                    for(i=0;i<2;i++){
                        scanf("%d",&pos[i]);
                    }
                    Lowerget(mat,pos);
                    break;
                case 2:
                    printf("Lower Triangular matrix : \n");
                    Lowerdisplay(mat);
                    break;
                case 3:
                    printf("exiting Lower triangular matrix ...");
                    break;
                default:
                    printf("Invalid input !\n");
                    break;
                }
            }while(ch1!=3);
            break;
        case 3:
            printf("Enter dimention of matrix :");
            scanf("%d",&mat.n);
            no_ele = mat.n*(mat.n+1)/2;
            printf("Enter %d Non-zero elemets :",no_ele);
            for(i=0;i<no_ele;i++){
                scanf("%d",&mat.A[i]);
            }
            int ch2;
            do{
            printf("1. GET(1 base indexing) \n");
            printf("2. DISPLAY \n");
            printf("3. EXIT \n");
            printf("Enter ( 1/2/3 )? :");
            scanf("%d",&ch2);
            
                switch (ch2)
                {
                case 1:
                    printf("Enter position (i , j):");
                    for(i=0;i<2;i++){
                        scanf("%d",&pos[i]);
                    }
                    Upperget(mat,pos);
                    break;
                case 2:
                    printf("Upper triangular matrix : \n");
                    Upperdisplay(mat);
                    break;
                case 3:
                    printf("exiting Upper Triangular matrix ...");
                    break;
                default:
                    printf("Invalid input !\n");
                    break;
                }
            }while(ch2!=3);
            break;
        case 4:
            printf("Enter dimention of matrix :");
            scanf("%d",&mat.n);
            no_ele = mat.n*(mat.n+1)/2;
            printf("Enter %d Non-zero elemets :",no_ele);
            for(i=0;i<no_ele;i++){
                scanf("%d",&mat.A[i]);
            }
            int ch3;
            do{
            printf("1. GET(1 base indexing) \n");
            printf("2. DISPLAY \n");
            printf("3. EXIT \n");
            printf("Enter ( 1/2/3 )? :");
            scanf("%d",&ch3);
            
                switch (ch3)
                {
                case 1:
                    printf("Enter position (i , j):");
                    for(i=0;i<2;i++){
                        scanf("%d",&pos[i]);
                    }
                    Symmetricget(mat,pos);
                    break;
                case 2:
                    printf("Symmetric matrix : \n");
                    Symmetricdisplay(mat);
                    break;
                case 3:
                    printf("exiting Symmetric matrix ...");
                    break;
                default:
                    printf("Invalid input !\n");
                    break;
                }
            }while(ch3!=3);
            break;
        case 5:   
            printf("Enter dimension of matrix : ");
            scanf("%d", &mat.n);

            no_ele = 3 * mat.n - 2;   // tridiagonal storage
            mat.A = (int *)malloc(no_ele * sizeof(int));

            printf("Enter %d non-zero elements : ", no_ele);
            for(i = 0; i < no_ele; i++){
                scanf("%d", &mat.A[i]);
            }

            int ch4;
            do{
                printf("\n1. GET (1 base indexing)\n");
                printf("2. DISPLAY\n");
                printf("3. EXIT\n");
                printf("Enter (1/2/3)? : ");
                scanf("%d", &ch4);

                switch(ch4)
                {
                case 1:
                    printf("Enter position (i , j): ");
                    for(i = 0; i < 2; i++){
                        scanf("%d", &pos[i]);
                    }
                    Tridiagonalget(mat, pos);
                    break;

                case 2:
                    printf("Tridiagonal matrix : \n");
                    Tridiagonaldisplay(mat);
                    break;

                case 3:
                    printf("Exiting Tridiagonal matrix...\n");
                    break;

                default:
                    printf("Invalid input!\n");
                    break;
                }

            } while(ch4 != 3);
            break;
        case 6:
            do{
                struct Sparse s;
                createSparse(&s);
                printf("\n1. GET (0 base indexing)\n");
                printf("2. DISPLAY (0 base indexing)\n");
                printf("3. ADD \n");
                printf("4. EXIT\n");
                printf("Enter (1/2/3)? : ");
                scanf("%d", &ch5);

                switch(ch5)
                {
                case 1:
                    printf("Not ready yet !");
                    break;
                case 2:
                    printf("Sparse matrix : \n");
                    Sparsedisplay(s);
                    break;
                case 3:
                    printf("Not ready yet !\n");
                    break;
                case 4:
                    printf("Exiting Tridiagonal matrix...\n");
                    break;
                default:
                    printf("Invalid input!\n");
                    break;
                }

            } while(ch5 != 4);
            break;
        case 7:
            printf("Exitting ...\n");
            break;
        default:
            printf("Invalid input !\n");
            break;
        }

    }while(choice != 7);
    return 0;
}