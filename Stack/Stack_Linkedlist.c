#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;
// count
int count(){
    int cnt=0;
    struct Node *temp=top;
    while(temp != NULL){
        cnt ++;
        temp = temp ->next;
    }
    return cnt;
}
//push
void push(){
    int x;
    printf("Enter value:");
    scanf("%d",&x);
    struct Node *newNode ;
    newNode=(struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Stack overflow ! \n");
    }else{
        newNode->data=x;
        newNode->next=top;
        top=newNode;
    }
}
//pop
int pop(){
    int x;
    struct Node *temp=top;
    if(top == NULL){
        printf("Stack underflow ! \n");
        return -1;
    }else{
        x=top->data;
        top=top->next;
        free(temp);
        return x;
    }
}
//peek
int peek(){
    int i,pos,x,c=count();
    printf("Enter position:");
    scanf("%d",&pos);
    if(top == NULL){
        printf("Stack is Empty \n");
        return -1;
    }
    if(pos<1 || pos>c){
        printf("Invalid position !\n");
        return -1;
    }
    struct Node *temp=top;
    for(i=1;i<pos;i++){
        temp=temp->next;
    }
    x=temp->data;
    return x;
}
// display
void display(){
    struct Node *temp=top;
    if(top == NULL){
        printf("Stack is Empty \n");
        return ;
    }
    while(temp !=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// stack top
int stackTop(){
    int x;
    if(top == NULL){
        return -1;
    }else{
        x=top->data;
        return x;
    }
}
// is Empty
void isempty(){
    if(top == NULL){
        printf("Stack is EMPTY !\n");
    }else{
        printf("Stack is NOT EMPTY !\n");
    }
}
// is Full
int isfull(){
    struct Node *newNode ;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    int r = newNode ? 1 : 0;
    free(newNode);
    return r;
}
int main(){
    int choice, x, y, check;

    do{
        printf("\n___________MENU_____________\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. STACK TOP\n");
        printf("6. IS EMPTY\n");
        printf("7. IS FULL\n");
        printf("8. EXIT\n");
        printf("_____________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push();
                break;

            case 2:
                y = pop();
                if(y != -1){
                    printf("%d popped from stack\n", y);
                }
                break;

            case 3:
                y = peek();
                if(y != -1){
                    printf("Peeked value : %d\n", y);
                }
                break;

            case 4:
                printf("Stack elements : ");
                display();
                break;

            case 5:
                y = stackTop();
                if(y == -1){
                    printf("Stack is empty!\n");
                }else{
                    printf("Stack top : %d\n", y);
                }
                break;

            case 6:
                isempty();
                break;

            case 7:
                check = isfull();
                if(check != 1)
                    printf("Stack is FULL!\n");
                else
                    printf("Stack is NOT FULL!\n");
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 8);

    return 0;
}
