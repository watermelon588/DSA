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
// create
void create(struct poly *p){
    int i;
    printf("Enter no. of terms:");
    scanf("%d",&p->n);
    p->t=(struct term*)malloc(p->n*sizeof(struct term));
    printf("Enter coeff. and exp. of each term :");
    for(i=0;i<p->n;i++){
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}
// display
void display(struct poly p){
    int i;
    for(i=0;i<p.n;i++){
        printf(" %dX%d +",p.t[i].coeff,p.t[i].exp);
    }
    printf("0\n");
}
// evaluation
int evaluate(struct poly p,int x){
    int i;
    int sum=0;
    for(i=0;i<p.n;i++){
        sum += p.t[i].coeff*pow(x,p.t[i].exp);
    }
    return sum;
}
// add 
struct poly *add(struct poly *p1,struct poly *p2){
    int i,j,k;
    i=j=k=0;
    struct poly *sum;
    sum->t=(struct term*)malloc((p1->n+p2->n)*sizeof(struct term));
    while(i<p1->n && j<p2->n){
        if(p1->t[i].exp>p2->t[j].exp){
            sum->t[k++] = p1->t[i++];
        }
        else if(p1->t[i].exp<p2->t[j].exp){
            sum->t[k++] = p2->t[j++];
        }
        else{
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff+p2->t[j++].coeff;
        }
    }
    for(;i<p1->n;i++){
        sum->t[k++] = p1->t[i];
    }
    for(;j<p2->n;j++){
        sum->t[k++] = p2->t[j];
    }
    sum->n=k;
    return sum;
}
// main
int main(){
    int choice ,i,n,x;
    int eva;
    struct poly p1,p2,*p3;
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
            create(&p1);
            display(p1);
            break;
        case 2:
            create(&p1);
            printf("Enter value of X :");
            scanf("%d",&x);
            eva = evaluate(p1,x);
            printf("Value of polynomial P(%d): %d\n",x,eva);
            break;
        case 3:
            printf("P1(x):----\n");
            create(&p1);
            printf("P2(x):----\n");
            create(&p2);
            p3 = add(&p1,&p2);
            printf("P1(x)+P2(x) :---- ");
            display(*p3);
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