#include<stdio.h>
#include<stdlib.h>
// structure 
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head;
// create
void create(){
    int i,n;
    int arr[25];
    struct Node *temp,*newNode;
    printf("Enter Doubly Linked list elements!\n");
    printf("enter size(<25):");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid size !\n");
        return;
    }
    printf("Enter %d elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //first node
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->prev=NULL;
    head->next=NULL;
    temp = head;
    //rest other nodes
    for(i=1;i<n;i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data=arr[i];
        newNode->next=NULL;
        newNode->prev = temp;
        temp->next=newNode;
        temp = newNode;
    }
    printf("Doubly Linked list created successfully!\n");  
}
// add
void Addnode(int x){
    struct Node *temp;
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    //if head == NULL
    if(head == NULL){
        head = newNode;
        head->prev=NULL;
        printf("Node added with val %d successfully!\n",x);
    }else{
        temp = head;
        while(temp->next != NULL){
            temp = temp ->next;
        }
        temp->next=newNode;
        newNode->prev = temp;
        printf("Node added with val %d successfully!\n",x);
    }
}
//count
int count(){
    struct Node *temp = head;
    int cnt = 0;
    while(temp!= NULL){
        cnt ++;
        temp = temp->next;
    }
    return cnt;
}
// insert
void insert(){
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
    newNode->prev = NULL;
    newNode->next = NULL;
    //if pos == 1
    if(pos == 1){
        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head=newNode;
        }  
    }else{      //other than that
        temp = head;
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        newNode->prev=temp;
        newNode->next = temp->next;
        if(temp->next!=NULL){
            temp->next->prev=newNode;   //if next node is present then only modify
        }
        temp->next = newNode;
    }
    printf("Node inserted with val %d successfully!\n",val);  
}
// delete
int deleteNode(int pos){
    int i,n=count(),x;
    struct Node *temp;
    //position validate
    if(pos<1 || pos>n){
        printf("Invalid position!\n");
        return -1;
    }
    if(head == NULL){
        printf("List is empty !");
        return -1;
    }
    // 1. pos == 1
    if(pos==1){
        temp = head;
        head = head->next;
        if(head != NULL){
            head->prev=NULL;
        }
        x=temp->data;
        free(temp);
        return x;
    }else{      // 2. pos != 1
        temp = head;
        for(i=1;i<pos;i++){
            temp = temp->next;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        x=temp->data;
        free(temp);
        return x;
    }
}
// reverse
void reverse(){
    struct Node *temp = head;
    struct Node *swap = NULL;

    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    while(temp != NULL){
        swap = temp->next;     // store next
        temp->next = temp->prev;
        temp->prev = swap;
        temp = temp->prev;    // move to original next
        if(temp!=NULL && temp->next==NULL){
            head = temp;
        }
    }

    printf("List reversed successfully!\n");
}

// display
void display(){
    struct Node *temp=head;
    while(temp != NULL){
        printf("%d",temp->data);
        if(temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
//sum
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
int main(){
    int choice;
    int mrg,res,srt,x,Count,mX,mN,sM,key,del,pos;
    do{
        printf("\n");
        printf("___________MENU_____________\n");
        printf("1. CREATE \n");
        printf("2. ADDNODE \n");
        printf("3. INSERT NODE\n");
        printf("4. DELETENODE\n");
        printf("5. COUNT\n");
        printf("6. DISPLAY \n");
        printf("7. SUM\n");
        printf("8. FIND MAX / MIN\n");
        printf("9. REVERSE\n");
        printf("10. REMOVE DUPLICATE\n");
        printf("11. REVERSE\n");
        printf("12. CONCATINATION(2 LL)\n");
        printf("13. MERGE(2 sorted LL)\n");
        printf("14. EXIT\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice){
            case 1:
                create();
                break;
            case 2:
                printf("Enter val:");
                scanf("%d",&x);
                Addnode(x);
                break;
            case 3:
                insert();
                break;
            case 4:
                printf("Enter position(1 base):");
                scanf("%d",&pos);
                del=deleteNode(pos);
                if(del == -1){
                    printf("Cannot delete !\n");
                }else{
                    printf("%d deleted successfully\n",del);
                }
                break;
            case 5:
                Count=count();
                printf("Total elements : %d\n",Count);
                break;
            case 6:
                printf("Circular Linked list :");
                display();
                break;
            case 7:
                sM=Sum();
                printf("Total elements : %d\n",sM);
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
                reverse();
                printf("Reversed List :");
                display();
                break;
            case 14:
                printf("Exitting ...\n");
                break;    
            default:
                printf("Invalid choice!\n");
                break;
        }

    }while(choice != 14);

    return 0;
}