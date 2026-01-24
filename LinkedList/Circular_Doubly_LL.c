#include<stdio.h>
#include<stdlib.h>

// stucture
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head;
// create node
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
    head->prev=head;
    head->next=head;
    temp = head;
    //rest other nodes
    for(i=1;i<n;i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data=arr[i];
        newNode->next=head;
        newNode->prev = temp;
        temp->next=newNode;
        temp = newNode;
    }
    temp->next = head;
    head->prev = temp;
    printf("Circular Doubly Linked list created successfully!\n");  
}
// add node
void Addnode(int x){
    struct Node *temp;
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    //if head == NULL
    if(head == NULL){
        head = newNode;
        head->prev=head;
        head->next=head;
        printf("Node added with val %d successfully!\n",x);
    }else{
        temp = head;
        temp->prev->next=newNode;
        newNode->prev = temp->prev;
        newNode->next=temp;
        temp->prev = newNode;
        printf("Node added with val %d successfully!\n",x);
    }
}
// count
int count(){
    struct Node *temp = head;
    if(head == NULL) return 0;
    int cnt = 0;
    do{
        cnt++;
        temp = temp->next;
    }while(temp!=head);
    return cnt;
}
// insert node
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
            head->prev=head;
            head->next = head;
        }else{
            temp = head;
            temp->prev->next=newNode;
            newNode->prev=temp->prev;
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
        temp->next->prev=newNode;
        temp->next = newNode;
    }
    printf("Node inserted with val %d successfully!\n",val);  
}
// delete node
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

    //  only one node
    if(n == 1 && pos == 1){
        x = head->data;
        free(head);
        head = NULL;
        return x;
    }
    if(pos==1){
        temp = head;
        x=temp->data;

        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        
        free(temp);
        return x;
    }else{      // 2. pos != 1
        temp = head;
        for(i=1;i<pos;i++){
            temp = temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        x=temp->data;
        free(temp);
        return x;
    }
}
// display
void display(){
    struct Node *temp=head;
    if(head == NULL){
        printf("List is empty !\n");
        return;
    }
    do{
        printf("%d",temp->data);
        temp = temp->next;
        if(temp != head)
            printf(" <-> ");
        
    }while(temp!=head);
    printf("\n");
}
// sum
int Sum(){
    if(head == NULL) return 0;

    int s = 0;
    struct Node *temp = head;

    do{
        s+=temp->data;
        temp = temp->next;
    } while(temp != head);

    return s;
}
// max 
int Max(){
    struct Node *temp = head;
    if(head==NULL){
        return 0;
    }
    int m= temp->data;
    temp = temp->next;
    do {
        if(temp->data > m){
            m = temp->data;
        }
        temp = temp->next;
    } while(temp != head);
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
    do {
        if(temp->data < m){
            m = temp->data;
        }
        temp = temp->next;
    } while(temp != head);
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
        printf("9. EXIT\n");
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
                printf("Sum of elements : %d\n",sM);
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