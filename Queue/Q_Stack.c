#include<stdio.h>
#include<stdlib.h>

// Stack node
struct Node{
    int data;
    struct Node *next;
};

// Two stacks
struct Node *top1 = NULL;
struct Node *top2 = NULL;

// ---------- STACK OPERATIONS ----------

// push into given stack
void push(struct Node **top, int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Overflow!\n");
        return;
    }
    newNode->data = x;
    newNode->next = *top;
    *top = newNode;
}

// pop from given stack
int pop(struct Node **top){
    if(*top == NULL){
        return -1;
    }

    struct Node *temp = *top;
    int x = temp->data;
    *top = temp->next;
    free(temp);
    return x;
}

// is empty
int isEmpty(struct Node *top){
    return top == NULL;
}

// ---------- QUEUE USING 2 STACKS ----------

// enqueue
void enqueue(int x){
    push(&top1, x);
    printf("%d enqueued\n", x);
}

// dequeue
int dequeue(){
    int x;

    if(isEmpty(top2)){
        while(!isEmpty(top1)){
            x = pop(&top1);
            push(&top2, x);
        }
    }

    if(isEmpty(top2)){
        printf("Queue is empty!\n");
        return -1;
    }

    return pop(&top2);
}

// display queue (slow but simple)
void display(){
    struct Node *temp;

    printf("Queue: ");

    temp = top2;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // elements in stack1 (reverse order)
    int arr[100], i = 0;
    temp = top1;

    while(temp){
        arr[i++] = temp->data;
        temp = temp->next;
    }

    while(i--){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// ---------- MAIN ----------

int main(){
    int choice, x;

    do{
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                x = dequeue();
                if(x != -1)
                    printf("Dequeued: %d\n", x);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 4);

    return 0;
}
