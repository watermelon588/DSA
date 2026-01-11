//STACK IMPLEMENTATION USING SINGLY LINKEDLIST.

#include<stdio.h>
#include<stdlib.h>
//initialization
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
//push 
void push(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(!newNode){
        printf("Memory allocation failed !");
        return ;
    }
    newNode -> data = val;
    newNode ->next = top;
    top  = newNode;
    printf("%d is pushed to the stack !",val);
}
//pop
void pop(){
    if(top == NULL){
        printf("Stack underflow!");
        return;
    }
    struct Node* temp  = top;
    printf("%d popped from stack\n", top->data);
    top = top ->next;
    free(temp);
}
//peek 
//isEmpty
//int main