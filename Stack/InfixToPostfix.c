#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// structure
struct Node {
    char data;
    struct Node *next;
};
struct Node *top=NULL;
// push
void push (char x){
    struct Node *newNode ;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = x;
    newNode ->next = top;
    top = newNode;
}
// pop
char pop (){
    char x;
    if(top == NULL){
        return -1;
    }
    struct Node *temp = top;
    top = top->next;
    x = temp->data;
    free(temp);
    return x;
}
// check precedence
int precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '^'){
        return 3;
    }else{
        return 0;
    }
}
// check if operand
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
        return 0;
    }else{
        return 1;
    }
}
// infix To postfix
char * InfixToPostfix(char *infix){
    int i=0,j=0;
    char *postfix;
    int len = strlen(infix);

    postfix = (char *)malloc((len +2)*sizeof(char));
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }else{
            if(precedence(infix[i])>precedence(top->data)){
                push(infix[i++]);
            }else{
                postfix[j++] = pop();
            }
        }
    }
    while(top != NULL){     // pop out remaining operators from the stack
        postfix[j++]=pop();
    }
    postfix[j]='\0' ; // NULL terminator
    return postfix;
}
int main(){
    char infix[50];
    char *postfix;
    printf("Enter the Infix expression:  ");
    fgets(infix,sizeof(infix),stdin);
    infix[strcspn(infix, "\n")] = '\0';   // remove newline
    push(' ');
    postfix = InfixToPostfix(infix);
    printf("Postfix expression :  ");
    printf("%s ",postfix);
    return 0;
}