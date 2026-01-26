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
char pop(){
    struct Node *temp=top;
    char x;
    if(top == NULL){
        return -1;
    }else{
        top=top->next;
        x = temp ->data;
        free(temp);
        return x;
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
// is matching check 
int isMatchingPair(char open, char close){
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}
// parenthesis matching 
// for every kind of paranthesis [{(...)}]
int isBalanced(char exp[]){
    int i;
    char x;

    for(i=0;exp[i]!='\0';i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty()){return 0;}
            x = pop();

            if(!isMatchingPair(x, exp[i]))
                return 0;
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