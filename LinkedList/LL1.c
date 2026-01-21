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
// check if sorted
int ifsorted(){
    struct Node *temp = head;
    int x=-31278;
    if(head == NULL){
        printf("List Empty !\n");
        return -1;
    }
    while(temp != NULL){
        if(temp->data < x){
            return 0;
        }
        x = temp ->data;
        temp = temp->next;
    }
    return 1;
}
// remove duplicates
int remDuplicate(){
    struct Node *temp=head,*q;
    int x=0;
    if(head == NULL){
        printf("List Empty !\n");
        return -1;
    }
    while(temp->next != NULL){
        if(temp->data != temp->next->data){
            temp = temp->next;
        }else{
            q= temp->next;
            temp->next = q->next;
            free(q);
            x++;
        }
    }
    return x;
}
void reverse(){
    struct Node *temp=head,*p=NULL,*q=NULL;
    if(head == NULL){
        printf("List Empty !\n");
    }
    while(temp !=NULL){
        q=p;
        p=temp;
        temp=temp->next;
        p->next = q;
    }
    head = p;
}
void concat(){
    // creating second linked list !
    int i,n,arr[10];
    struct Node *head2,*last;
    struct Node *newNode2 ;
    printf("Enter a second Linked list!\n");
    printf("enter size(<10):");
    scanf("%d",&n);
    printf("Enter %d elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    head2=(struct Node *)malloc(sizeof(struct Node));
    head2->data=arr[0];
    head2->next=NULL;
    last=head2;
    for(i=1;i<n;i++){
        newNode2 = (struct Node *)malloc(sizeof(struct Node));
        newNode2->data=arr[i];
        newNode2->next=NULL;
        last->next=newNode2;
        last = newNode2;
    }
    // concat list
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
}
// merge
int merge(){
    // check if list 1 is sorted ??
    int srt = ifsorted();
    if(srt==0){
        printf("List is NOT SORTED!\n");
        printf("Cannot procceed further !\n");
        return -1;
    }else if(srt == -1){
        printf("Add elements first!");
        return -1;
    }else{
       // creating second sorted linked list !
        int i,n,arr[10];
        struct Node *head2,*last2;
        struct Node *newNode2 ;
        printf("Enter a second SORTED Linked list!\n");
        printf("enter size(<10):");
        scanf("%d",&n);
        printf("Enter %d elements:",n);
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        head2=(struct Node *)malloc(sizeof(struct Node));
        head2->data=arr[0];
        head2->next=NULL;
        last2=head2;
        for(i=1;i<n;i++){
            newNode2 = (struct Node *)malloc(sizeof(struct Node));
            newNode2->data=arr[i];
            newNode2->next=NULL;
            last2->next=newNode2;
            last2 = newNode2;
        } 
        // check if list 2 is sorted ??
        struct Node *temp2 = head2;
        int x=-31278;
        while(temp2 != NULL){
            if(temp2->data < x){
                printf("Provided List is NOT SORTED!\n");
                return -1;
            }
            x = temp2 ->data;
            temp2 = temp2->next;
        }
        // merge algorithm !
        struct Node *head3=NULL,*last=NULL,*temp=head;
        //check first conflict
        if(temp->data<head2->data){
            head3=last=head;   //bring every pointer to head;
            temp = temp->next;  // move temp
            last->next=NULL;   //last point to NULL;
        }else{
            head3=last=head2;   //bring every pointer to head2;
            head2 = head2->next;  // move temp
            last->next=NULL;   //last point to NULL;
        }
        // rest
        while(temp != NULL && head2 != NULL){
            if(temp->data<head2->data){     // compare value
                last->next = temp;  //last point on temp
                last = temp;        // move last to temp
                temp = temp->next;  // move temp
                last->next=NULL;   //last point to NULL;
            }else if(temp->data>head2->data){   // compare value
                last->next = head2;  //last point on head2
                last = head2;        // move last to head2
                head2 = head2->next;  // move head2
                last->next=NULL;   //last point to NULL;
            } 
        }
        //either one of the node will be left .. so point last->next to that node
        if(temp!=NULL){last->next = temp;}
        else{last->next = head2;}
        head = head3;  // update head
    }
    return 1;
}
// main function
int main(){
    int choice;
    int mrg,res,srt,x,Count,mX,mN,sM,key,del,pos;
    do{
        printf("\n");
        printf("___________MENU_____________\n");
        printf("1. ADD NODE\n");
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
            srt = ifsorted();
            if(srt==0){
                printf("List is NOT SORTED!\n");
            }else if(srt == 1){
                printf("List is SORTED!\n");
            }
            break;
        case 10:
            srt = ifsorted();
            if(srt==0){
                printf("List is NOT SORTED! Cannot Proceed\n");
            }else if(srt == 1){
                res=remDuplicate();
                if(res>0){
                    printf("%d Duplicates removed!\n",res);
                }else{
                    printf("No duplicates !\n");
                }
            }
            break;
        case 11:
            reverse();
            printf("Reversed List :");
            display();
            break;
        case 12:
            concat();
            printf("Concatinated List:");
            display();
            break;   
        case 13:
            mrg= merge();
            if(mrg == 1){
                printf("Merged List:");
                display();
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