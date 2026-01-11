#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
//initial declaration 
int stack[SIZE];
int top = -1;
// isFull function
int isFull(){
    return top == SIZE-1 ;
}
//isEmpty function
int isEmpty(){
    return top == -1 ;
}
//push function
void push(int val){
    if(isFull()){
        printf("Stack overflow !");
    }
    else{
        top++;
        stack[top] = val;
        printf("%d is pushed into the stack !",val);
    }
}
//pop function
void pop(){
    if(isEmpty()){
        printf("Stack underflow !");
    }
    else{
        printf("%d is popped out of the stack !",stack[top--]);
    }
}
//peek function
void peek(){
    if(isEmpty()){
        printf("Stack is empty !");
    }
    else{
        printf("Top element is %d",stack[top]);
    }
}
//display function
void display(){
    int i;
    if(isEmpty()){
        printf("Stack is empty !");
    }
    else{
        for(i=0;i<=top;i++){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
//main function(switch case)
int main(){
    int val,choice;
    do{
    printf("\n_____MENU_____\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.isEmpty\n");
    printf("4.isFull\n");
    printf("5.Peek\n");
    printf("6.Display\n");
    printf("7.Exit\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value you want to push :");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            if(isEmpty()){
                printf("Stack is currently empty!");
            }
            else{
                printf("Stack is not empty!");
            }
            break;
        case 4:
            if(isFull()){
                printf("Stack is currently full!");
            }
            else{
                printf("Stack is not full!");
            }
            break;
        case 5:
            peek();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("Exitting ....");
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }while (choice != 7);
    return 0;
}
