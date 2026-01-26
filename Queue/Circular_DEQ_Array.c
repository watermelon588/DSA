#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
//initial declaration !
int queue[SIZE];
int front = -1, rear=-1;
//isEmpty
int isFull(){
    return((rear+1)%SIZE==front);
}
//isFull
int isEmpty(){
    return front == -1;
}
//enqueueFront
void enqueueFront(int val){
    if(isFull()){
        printf("Queue is full !");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }
    else{
        front = (front-1+SIZE)%SIZE;
    }
    queue[front] = val;
    printf("%d inserted at front\n", val);
    
}
//enqueueRear
void enqueueRear(int val){
    if(isFull()){
        printf("Queue is full !");
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }
    else{
        rear = (rear+1)%SIZE;
    }
    queue[rear] = val;
    printf("%d inserted at rear\n", val);
    
}
//dequeueFront
void dequeueFront(){
    if(isEmpty()){
        printf(" queue is empty!");
        return;
    }
    printf("%d deleted from front\n", queue[front]);
    if(front==rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%SIZE;
    }
    
}
//dequeueRear
void dequeueRear(){
    if(isEmpty()){
        printf(" queue is empty!");
        return;
    }
    printf("%d deleted from rear\n", queue[rear]);
    if(front==rear){
        front = rear = -1;
    }
    else{
        rear = (rear-1+SIZE)%SIZE;
    }
    
}
//display
void display(){
    if (isEmpty()) {
        printf("queue is empty!\n");
        return;
    }
    int i = front;
    while(i != rear){
        printf("%d\t",queue[i]);
        i=(i+1)%SIZE;
    }
    printf("%d\t",queue[rear]);
    printf("\n");
}
int main() {
    int choice, value;

    do {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Check isEmpty\n");
        printf("7. Check isFull\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            enqueueFront(value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            enqueueRear(value);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
            break;
        case 7:
            printf(isFull() ? "Queue is full\n" : "Queue is not full\n");
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}