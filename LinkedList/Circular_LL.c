#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// STRUCTURE NODE
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
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