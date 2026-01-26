#include<stdio.h>
#include<stdlib.h>
// structure
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
// create 
void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
// is empty
int isEmpty(struct Queue *q){
    return (q->front==q->rear);
}
// is full
int isFull(struct Queue *q){
    return ((q->rear+1)%q->size == q->front);
}
// enqueue
void enqueue(struct Queue *q,int val){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full !\n");
        return ;
    }
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear]=val;
}
// dequeue
int dequeue(struct Queue *q){
    int x;
    if(isEmpty(q)){
        printf("Queue is empty !\n");
        return -1;
    }else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        return x;
    }
}
// display
void display(struct Queue q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i != (q.rear+1)%q.size);
    printf("\n");
}
int main(){
    int size,ch,val,x;
    struct Queue q;
    printf("Enter the size of queue : ");
    scanf("%d",&size);
    create(&q,size);
    do{
         printf("\n___________MENU_____________\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. IS EMPTY\n");
        printf("5. IS FULL\n");
        printf("6. EXIT\n");
        printf("_____________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter value : ");
                scanf("%d",&val);
                enqueue(&q,val);
                break;
            case 2:
                x=dequeue(&q);
                if(x==-1){
                    printf("Cannot dequeue \n");
                }else{
                    printf("Dequeued element %d \n",x);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                if(isEmpty(&q)){
                    printf("Queue is Empty !\n");
                }else{
                    printf("Queue is NOT Empty !\n");
                }
                break;
            case 5:
                if(isFull(&q)){
                    printf("Queue is Full !\n");
                }else{
                    printf("Queue is NOT Full !\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(ch != 6);
    return 0;
}