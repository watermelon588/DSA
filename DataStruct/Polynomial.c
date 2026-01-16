#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// structure
struct term{
    int coeff;
    int exp;
};
struct poly{
    int n;
    struct term *t;
};
void create(struct poly *p){
    int i;
    printf("Enter no. of terms:");
    scanf("%d",&p->n);
    p->t=(struct term*)malloc(p->n*sizeof(struct term));
    printf("Enter coeff. and exp. of each term :");
    for(i=0;i<p->n;i++){
        scanf("%d%d",&p->t->coeff,&p->t->exp);
    }
}
int main(){
    int choice ,i,n;
    struct poly *p;
    do{
        printf("___________MENU_____________\n");
        printf("1. CREATE\n");
        printf("2. EVALUATE\n");
        printf("3. ADD\n");
        printf("4. Exit\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            printf("Exitting ...\n");
            break;
        default:
            break;
        }

    }while(choice != 4);
    return 0;
}