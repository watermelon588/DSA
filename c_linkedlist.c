// CIRCULAR LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head; // circular link
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Insert at specific position
void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertFront(value);
        return;
    }
    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
}

// Delete from position
void deleteAtPosition(int pos) {
    if (pos == 1) {
        deleteFront();
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    int i;
    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (i != pos) {
        printf("Invalid position!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Search element
void search(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found!\n", value);
}

// Reverse circular linked list
void reverse() {
    if (head == NULL || head->next == head) return;

    struct Node *prev = NULL, *curr = head, *nextNode;
    struct Node *last = head;

    // Find last node
    while (last->next != head) {
        last = last->next;
    }

    do {
        nextNode = curr->next;
        curr->next = prev ? prev : head; // link reversal
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    head->next = prev;  // last node points to new head
    head = prev;        // update head
}

// Menu-driven main
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n---- Circular Singly Linked List ----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Reverse\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 9:
                reverse();
                printf("List reversed!\n");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}