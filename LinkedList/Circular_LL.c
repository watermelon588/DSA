#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// STRUCTURE NODE
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// create 
void create(){
    int i,n,arr[25];
    struct Node *last;
    struct Node *newNode ;
    printf("Enter Linked list elements!\n");
    printf("enter size(<25):");
    scanf("%d",&n);
    if(n <= 0){
        printf("Invalid size!\n");
        return;
    }
    printf("Enter %d elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data=arr[i];
        newNode->next=head;
        last->next=newNode;
        last = newNode;
    }
}
// count
int count(){
    if(head == NULL) return 0;

    int cnt = 0;
    struct Node *temp = head;

    do{
        cnt++;
        temp = temp->next;
    } while(temp != head);

    return cnt;
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
//insert node
void insertNode(){
    int pos, val, i, n = count();   
    struct Node *newNode, *temp;

    printf("Enter position (1 base): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1){
        printf("Invalid position!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &val);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    // Insert at beginning
    if(pos == 1){
        if(head == NULL){
            newNode->next = newNode;
            head = newNode;
        } else {
            temp = head;
            while(temp->next != head){   // go to last node
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }
    else{
        temp = head;
        for(i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted with value %d successfully!\n", val);
}
// display
void display(){
    struct Node *temp=head;
    if(head == NULL){
        printf("List is empty !\n");
        return;
    }
    do{
        printf(" %d ->",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}
// delete
int deleteNode (int pos){
    struct Node *q=NULL;
    struct Node *temp ;
    int i,x=-1;
    if(head == NULL){
        printf("List Empty !\n");
        return -1;
    }
    //validate position
    int n = count();
    if(pos < 1 || pos > n){
        printf("Invalid position!\n");
        return -1;
    }
    // 1. delete 1st node
    if(pos==1) {
        temp = head;
        x = head -> data;
        // 0nly one element !
        if(head -> next = head){
            head = NULL;
            free(head);
            return x;
        }
        // more than one node 
        q= head;
        while(q->next != head){
            q = q->next;
        }
        q->next = head->next;
        head = head->next;
        free(temp);
        return x;
    }else{          // 2. delete other nodes
        temp = head;
        for(i=1;i<pos ;i++){
            q= temp;
            temp = temp->next;
        }
        q->next = temp->next;
        x = temp ->data;
        free(temp);
        return x;
    }
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
        printf("2. INSERT NODE\n");
        printf("3. DELETE NODE\n");
        printf("4. COUNT\n");
        printf("5. DISPLAY \n");
        printf("6. SUM\n");
        printf("7. L SEARCH (Improved)\n");
        printf("8. FIND MAX / MIN\n");
        printf("9. CHECK IF SORTED\n");
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
                printf("Circular Linked list :");
                display();
                break;
            case 6:
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