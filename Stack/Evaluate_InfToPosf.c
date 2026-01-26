#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

// Stack node
struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// push
void push(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// pop
int pop(){
    if(top == NULL){
        printf("Stack underflow!\n");
        return -1;
    }

    int x = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return x;
}

// Evaluate postfix
int evaluatePostfix(char postfix[]){
    int i;
    int op1, op2, result;

    for(i = 0; postfix[i] != '\0'; i++){

        // if operand (digit)
        if(isdigit(postfix[i])){
            push(postfix[i] - '0');   // convert char to int
        }

        // if operator
        else{
            op2 = pop();
            op1 = pop();

            switch(postfix[i]){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            push(result);
        }
    }

    return pop();   // final answer
}

int main(){
    char postfix[50];

    printf("Enter postfix expression (digits only): ");
    fgets(postfix, sizeof(postfix), stdin);

    // remove newline
    postfix[strcspn(postfix, "\n")] = '\0';

    int result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
