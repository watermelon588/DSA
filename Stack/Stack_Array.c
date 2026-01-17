// STACK ADT USING ARRAY
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// structure Stack
struct Stack {
    int top ;
    int size;
    int *ele;
};
// create stack
struct Stack create(struct Stack *st){
    int i;
    printf("Enter Stack size:");
    scanf("%d",&st->size);
    st->ele = (int *) malloc (st->size*sizeof(int));
    st->top = -1;
}
// isEmpty
int isEmpty(struct Stack st){
    return (st.top == -1);
}
// isFull
int isFull(struct Stack st){
    return (st.top == st.size - 1);
}
//push
void push(struct Stack *st, int x){
    if(isFull(*st)){
        printf("Stack overflow!\n");
    } else {
        st->top++;
        st->ele[st->top] = x;
    }
}

// Pop
int pop(struct Stack *st){
    int x = -1;
    if(isEmpty(*st)){
        printf("Stack underflow!\n");
    } else {
        x = st->ele[st->top--];
    }
    return x;
}

// display
void display(struct Stack st){
    int i;
    if(isEmpty(st)){
        printf("Stack is empty!\n");
    } else {
        for(i = 0; i <= st.top; i++){
            printf("%d ", st.ele[i]);
        }
        printf("\n");
    }
}
// Peek
int peek(struct Stack st, int pos){
    if(st.top - pos + 1 < 0){
        printf("Invalid position!\n");
        return -1;
    }
    return st.ele[st.top - pos + 1];
}

// StackTop
int stackTop(struct Stack st){
    if(!isEmpty(st))
        return st.ele[st.top];
    return -1;
}
int main(){
    int choice,x,y,check,pos;
    struct Stack st;
    create(&st);
    do{
        printf("___________MENU_____________\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY \n");
        printf("5. STACK TOP\n");
        printf("6. IS EMPTY\n");
        printf("7. IS FULL\n");
        printf("8. EXIT\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter value:");
            scanf("%d",&x);
            push(&st,x);
            break;
        case 2:
            y = pop(&st);
            if(y != -1)
                printf("%d popped from stack\n", y);
            break;
        case 3:
            printf("Enter position from top: ");
            scanf("%d", &pos);
            y = peek(st, pos);
            if(y != -1)
                printf("Peeked value: %d\n", y);
            break;
        case 4:
             printf("Stack is: ");
            display(st);
            break;
        case 5:
            y = stackTop(st);
            if(y != -1)
                printf("Stack top: %d\n", y);
            break;
        case 6:
            if(isEmpty(st))
                printf("Stack is empty!\n");
            else
                printf("Stack is not empty!\n");
            break;
        case 7:
            if(isFull(st))
                printf("Stack is full!\n");
            else
                printf("Stack is not full!\n");
            break;
        case 8:
            printf("Exitting ...\n");
            break;    
        default:
            printf("Invalid choice!\n");
            break;
        }

    }while(choice != 8);
    free(st.ele);
    return 0;
}