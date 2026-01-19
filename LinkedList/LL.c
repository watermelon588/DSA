#include<stdio.h>
#include<stdlib.h>
// structure linked list
struct Node {
    int data;
    struct Node *next;
};
struct Node *first=NULL;
//create linked list
void create(int a[],int n){
    int i;
    struct Node *last, *t;
    first = (struct Node*)malloc(sizeof(struct Node));
    first ->data = a[0];
    first ->next = NULL;
    last = first;

    for(i=1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t-> data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }

}
// display linked list (using WHILE loop)
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
// display linked list (recursive)
void Rdisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}
// Count
int count(struct Node *p){
    int count = 0;
    while(p!=NULL){
        count ++;
        p = p-> next;
    }
    return count;
}
// recursive count
int Rcount(struct Node *p){
    int count = 0;
    if(p!=NULL){
       return Rcount(p->next)+1;
    }
    return count;
}
// sum
int summation (struct Node *p){
    int s = 0 ;
    while(p!= NULL){
        s+=p->data;
        p = p->next;
    }
    return s;
}
// recursive sum
int Rsummation (struct Node *p){
    int s = 0 ;
    if(p!= NULL){
        return Rsummation(p->next)+p->data;
    }
    return s;
}
// maximum
int Max(struct Node *p){
    int max = -32768;
    while(p!=NULL){
        if(p->data>max){
            max = p->data;
        }
        p= p->next;
    }
    return max;
}
// search
struct Node* Lsearch(struct Node *p, int key){
    struct Node *q;
    q= NULL;
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
// insert 
void insert (struct Node *p,int pos,int val){
    struct Node *t,*temp=first;
    int i;
    if(pos<0 || pos> count(p)){
        printf("Invalid index ! can't be nevetive \n");
        return;
    }
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = val;
    if(pos == 0){
        t->next = first;
        first = t;
        printf("%d has been inserted on position %d!\n",val,pos);
    }else{
        for(i=0;i<pos-1 && temp != NULL;i++){
            temp = temp-> next;
        }
        t->next = temp-> next;
        temp -> next = t;
        printf("%d has been inserted on position %d!\n",val,pos);
    }
}
int main(){
    int i,n,choice,x,y,check,pos,Count,Sum,Maxx,key,val;
    struct Node *Search;
    int a[5];
    do{
        printf("___________MENU_____________\n");
        printf("1. CREATE\n");
        printf("2. COUNT\n");
        printf("3. SUM\n");
        printf("4. DISPLAY \n");
        printf("5. MAX\n");
        printf("6. SEARCH (Improved)\n");
        printf("7. INSERT\n");
        printf("8. EXIT\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter the elements:");
            for(i=0;i<5;i++){
                scanf("%d",&a[i]);
            }
            create(a,5);
            break;
        case 2:
            Count = count(first);
            printf("No. of elements : %d",Count);
            printf("\n");
            break;
        case 3:
            Sum = Rsummation(first);
            printf("Sum of elements : %d",Sum);
            printf("\n");
            break;
        case 4:
            printf("\nLinked list : ");
            display(first);
            printf("\n");
            break;
        case 5:
            Maxx = Max(first);
            printf("\nMax value : %d",Maxx);
            printf("\n");
            break;
        case 6:
            printf("Enter the key:");
            scanf("%d",&key);
            Search = Lsearch(first,key);
            if(Search!=NULL){
                printf("%d found !\n",key);
            }else{
                printf("%d not found\n",key);
            }  
            break;
        case 7:
            printf("Enter the position and value:");
            scanf("%d%d",&pos,&val);
            insert(first,pos,val);
            break;
        case 8:
            printf("Exitting ...\n");
            break;    
        default:
            printf("Invalid choice!\n");
            break;
        }

    }while(choice != 8);
    return 0;
}