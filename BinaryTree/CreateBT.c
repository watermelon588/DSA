#include <stdio.h>
#include <stdlib.h>

/* structure for tree */
typedef struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

/* structure for queue */
struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
};

/* create queue */
void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (Node **)malloc(size * sizeof(Node *));
}

/* is empty */
int isEmpty(struct Queue *q){
    return q->front == q->rear;
}

/* enqueue */
void enqueue(struct Queue *q, Node *val){
    if(q->rear == q->size - 1){
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->Q[q->rear] = val;
}

/* dequeue */
Node* dequeue(struct Queue *q){
    if(isEmpty(q)){
        return NULL;
    }
    q->front++;
    return q->Q[q->front];
}

/* global root */
Node *root = NULL;

/* create tree (level order) */
void TreeCreate(){
    Node *p, *t;
    int x;
    struct Queue q;

    create(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (Node *)malloc(sizeof(Node));
    root->data = x;
    root->lchild = root->rchild = NULL;

    enqueue(&q, root);

    while(!isEmpty(&q)){
        p = dequeue(&q);
        if(p == NULL) break;

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if(x != -1){
            t = (Node *)malloc(sizeof(Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

/* preorder traversal */
void preorder(Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
/* inorder traversal */
void inorder(Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

/* postorder traversal */
void postorder(Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
/* level traversal */
void levelOrder(Node *root){
    struct Queue q;
    Node *p;

    create(&q, 100);

    printf("Level order traversal: ");

    enqueue(&q, root);

    while(!isEmpty(&q)){
        p = dequeue(&q);
        if(p){
            printf("%d ", p->data);

            if(p->lchild)
                enqueue(&q, p->lchild);

            if(p->rchild)
                enqueue(&q, p->rchild);
        }
    }
}
// count
int count(struct Node *p){
    int x,y;
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}
// height
int height(struct Node *p){
    int x,y;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
            
    }
}

int main(){
    int choice;

    while(1){
        printf("\n\n===== BINARY TREE MENU =====");
        printf("\n1. Create Tree");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Level Order Traversal");
        printf("\n6. Count Nodes");
        printf("\n7. Height of Tree");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                TreeCreate();
                break;

            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                break;

            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                break;

            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                break;

            case 5:
                levelOrder(root);
                break;

            case 6:
                printf("Total nodes: %d", count(root));
                break;

            case 7:
                printf("Height of tree: %d", height(root));
                break;

            case 0:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.");
        }
    }

    return 0;
}
