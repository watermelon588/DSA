#include<stdio.h>
#include<stdlib.h>
// structure 
struct Node{
    char data;
    struct Node *next;
};
struct Node *top=NULL;
// push 
void push(char x){
    struct Node * newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return ;
    }
    newNode->data=x;
    newNode->next = top;
    top=newNode;
}
// pop
void pop(){
    struct Node *temp=top;
    if(top == NULL){
        return ;
    }else{
        top=top->next;
        free(temp);
    }
}
// is empty
int isEmpty(){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}
// parenthesis matching
int isBalanced(char exp[]){
    int i;

    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            if(isEmpty()){return 0;}
            pop();
        }
    }
    if(isEmpty()){
        return 1;
    }else{
        return 0;
    }
}
int main (){
    int x;
    char exp[50];
    printf("Enter the expression:  ");
    fgets(exp,sizeof(exp),stdin);
    x=isBalanced(exp);
    if(x==1){
        printf("Paranthesis are matched !\n");
    }else{
        printf("Paranthesis are not matched !\n");
    }
    return 0;
}