#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// STRUCTURE NODE
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// count
int count(){
    int count=0;
    struct Node *temp=head;
    while(temp!= NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}
// add node
void addnode(int x){
    int i;
    struct Node *tail=head;
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode-> next = NULL;
    // if newNode == NULL
    if(head==NULL){
        head = newNode;
        printf("Node added with val %d successfully!\n",x);
    }else{  // if List is already present
        struct Node *tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newNode;
        printf("Node added with val %d successfully!\n",x);
    }
}
// insert node 
void insertNode(){
    int pos , val,i,n=count();
    printf("Enter position(1 base):");
    scanf("%d",&pos);
    if(pos<1 || pos>n+1){
        printf("Invalid position!\n");
        return;
    }
    printf("Enter value:");
    scanf("%d",&val);
    struct Node *newNode,*temp;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    // if pos == 1
    if(pos == 1){
        newNode->next = head;
        head = newNode;
    }else{// if pos > 1 && pos < count()
        temp = head;
        for(i=1;i<pos-1 ;i++){
            temp = temp->next;
        }
        newNode->next=temp->next;
        temp->next = newNode;
    }
    printf("Node inserted with val %d successfully!\n",val);  
}

// display
void display(){
    struct Node *temp=head;
    while(temp != NULL){
        printf(" %d ->",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// sum
int Sum(){
    int s=0;
    struct Node *temp = head;
    while(temp !=NULL){
        s += temp->data;
        temp=temp->next;
    }
    return s ;
}
// max
int Max(){
    struct Node *temp = head;
    if(head==NULL){
        return 0;
    }
    int m= temp->data;
    temp = temp->next;
    while(temp !=NULL){
        if(temp->data>m){
            m= temp->data;
            
        }
        temp=temp->next;
    }
    return m ;
}
// min
int Min(){
    struct Node *temp = head;
    if(head==NULL){
        return 0;
    }
    int m= temp->data;
    temp = temp->next;
    while(temp !=NULL){
        if(temp->data<m){
            m= temp->data;
            
        }
        temp=temp->next; 
    }
    return m ;
}
// linear search
void Lsearch(int key){
    struct Node *temp = head;
    struct Node *q=NULL;
    while(temp!=NULL){
        if(temp->data == key){
            printf("%d Found!\n", key);
            // Move to front (if not already first)
            if(q != NULL){
                q->next = temp->next;
                temp->next = head;
                head = temp;
            }
            return;
        }
        q=temp;
        temp=temp->next;
    }
    printf("%d Not Found!\n", key);
}
// delete
int deleteNode(int pos){
    int i,x=-1;
    struct Node *temp;
    struct Node *q=NULL;
    // 1. delete 1st Node
    if(head == NULL){
        printf("List Empty !\n");
        return -1;
    }
    if(pos == 1){
        x = head ->data;
        temp=head;
        head = head->next;
        free(temp);
    }else{              // 2. delete other node
        temp = head;
        for(i=1;i<pos && temp ;i++){
            q=temp;
            temp=temp->next;
        }
        if(temp!=NULL){
            q->next = temp->next;
            x=temp->data;
            free(temp);
        }
    }
    return x;
}
// main function
int main(){
    int choice;
    int x,Count,mX,mN,sM,key,del,pos;
    do{
        printf("___________MENU_____________\n");
        printf("1. ADD NODE\n");
        printf("2. INSERT NODE\n");
        printf("3. DELETE NODE\n");
        printf("4. COUNT\n");
        printf("5. DISPLAY \n");
        printf("6. SUM\n");
        printf("7. L SEARCH (Improved)\n");
        printf("8. FIND MAX / MIN\n");
        printf("9. EXIT\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter val:");
            scanf("%d",&x);
            addnode(x);
            break;
        case 2:
            insertNode();
            break;
        case 3:
            printf("Enter position(1 base):");
            scanf("%d",&pos);
            del=deleteNode(pos);
            if(del == -1){
                printf("Cannot delete !\n");
            }else{
                printf("%d deleted successfully\n",del);
            }
            break;
        case 4:
            Count=count();
            printf("Total elements : %d\n",Count);
            break;
        case 5:
            printf("Linked List:");
            display();
            break;
        case 6:
            sM=Sum();
            printf("Total elements : %d\n",sM);
            break;
        case 7:
            printf("Enter key:");
            scanf("%d",&key);
            Lsearch(key);
            break;
        case 8:
            mX=Max();
            mN=Min();
            if(mX==0){
                printf("List is empty!\n");
            }else{
                printf("Maximum value is : %d\nMinimum value is : %d",mX,mN);
                printf("\n");
            }
            break;
        case 9:
            printf("Exitting ...\n");
            break;    
        default:
            printf("Invalid choice!\n");
            break;
        }

    }while(choice != 9);
    return 0;
}