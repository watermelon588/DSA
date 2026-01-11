#include <stdio.h>
#include <stdlib.h>

// node creation
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

//function to insert node at any given position
void insert(){
    //memory allocation
    int i , pos ,val;
    struct node *newNode,*temp;
    newNode = (struct node*)malloc(sizeof(struct node));

    // ask for the input
    printf("Enter data to insert: ");
    scanf("%d", &val);
    newNode->data=val;
    newNode->next = NULL ;

    printf("enter the position(1 to insert at begining) : ");
    scanf("%d",&pos);

    //insert at begining
    if(pos == 1){
        newNode -> next = head;
        head = newNode;
    }// at any other position
    else{
        temp = head;
        for(i=1;i<pos-1 && temp != NULL;i++){
            temp = temp->next;
        }
        //overflow condn.
        if(temp == NULL){
            printf("Position not found!\n");
            free(newNode);
            return;
        }
        newNode-> next = temp->next;
        temp -> next = newNode;
    }
    printf("Node inserted successfully!\n");
}
//function to delete node from any given position
void delete(){
    int pos, i;
    struct node *temp, *prev ;
    if(head == NULL){
        printf("list is empty!");
        return;
    }
    //input for position
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    temp = head;
    // pos == 1 (begining)
    if(pos == 1){
        head = head ->next;
        printf("%d is deleted !",temp->data);
        free(temp);
    }
    // pos != 1 (others)
    else{
        for(i = 1;i<pos && temp != NULL;i++){
            prev = temp;
            temp = temp -> next;
        }
        //overflow condn.
        if(temp == NULL){
            printf("Position not found!\n");
            return;
        }
        prev->next=temp->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
};
//display
void display(){
    struct node *temp;
    int pos;
    temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
//search
void search(){
    struct node *temp;
    int val ,pos=1,found = 0;
    temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &val);

    while (temp != NULL){
        if(temp->data == val){
            printf("Element %d found at position %d\n", val, pos);
            found = 1;
        }
        temp = temp->next;
        pos ++;
    }
    if (!found)
        printf("Element not found!\n");
}
//reverse
void reverse(){
    struct node *temp,*prev,*next;
    temp = head ;
    prev = NULL;
    next = NULL;

    while (temp != NULL){
        next = temp ->next;
        temp -> next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    printf("List reversed successfully!\n");
}
//main
int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                reverse();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
