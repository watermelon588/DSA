#include <stdio.h>
#include <stdlib.h>

/* node creation */
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* get length of circular list */
int length() {
    if (head == NULL) return 0;
    int cnt = 1;
    struct node *temp = head->next;
    while (temp != head) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

/* insert node at any given position (1-based) */
void insert() {
    int pos, val, i;
    struct node *newNode, *temp, *last;

    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data to insert: ");
    if (scanf("%d", &val) != 1) { printf("Invalid input.\n"); free(newNode); return; }
    newNode->data = val;
    newNode->next = NULL;

    printf("Enter the position (1 to insert at beginning): ");
    if (scanf("%d", &pos) != 1) { printf("Invalid input.\n"); free(newNode); return; }

    int len = length();
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position. Current length = %d\n", len);
        free(newNode);
        return;
    }

    /* insert into empty list */
    if (head == NULL) {
        newNode->next = newNode; // circular
        head = newNode;
        printf("Node inserted successfully!\n");
        return;
    }

    /* insert at beginning (pos == 1) */
    if (pos == 1) {
        last = head;
        while (last->next != head) last = last->next;
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        printf("Node inserted successfully at position 1!\n");
        return;
    }

    /* insert at other positions */
    temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted successfully!\n");
}

/* delete node from any given position (1-based) */
void deleteNode() {
    int pos, i;
    struct node *temp, *prev, *last;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    if (scanf("%d", &pos) != 1) { printf("Invalid input.\n"); return; }

    int len = length();
    if (pos < 1 || pos > len) {
        printf("Invalid position. Current length = %d\n", len);
        return;
    }

    /* delete only node */
    if (head->next == head && pos == 1) {
        printf("%d is deleted!\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    /* delete first node (pos == 1) with multiple nodes */
    if (pos == 1) {
        last = head;
        while (last->next != head) last = last->next;
        temp = head;
        head = head->next;
        last->next = head;
        printf("%d is deleted!\n", temp->data);
        free(temp);
        return;
    }

    /* delete at other positions */
    prev = NULL;
    temp = head;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

/* display circular list */
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) printf(" -> ");
    } while (temp != head);
    printf("\n");
}

/* search value in circular list */
void search() {
    struct node *temp;
    int val, pos = 1, found = 0;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Enter value to search: ");
    if (scanf("%d", &val) != 1) { printf("Invalid input.\n"); return; }

    temp = head;
    do {
        if (temp->data == val) {
            printf("Element %d found at position %d\n", val, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found) printf("Element not found!\n");
}

/* reverse circular list */
void reverse() {
    struct node *temp, *prev, *next, *last;
    if (head == NULL || head->next == head) {
        printf("List reversed successfully!\n"); // empty or single node
        return;
    }

    /* break circularity: make list linear */
    last = head;
    while (last->next != head) last = last->next;
    last->next = NULL;

    /* reverse linear list */
    prev = NULL;
    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    /* prev is new head */
    head = prev;

    /* restore circularity */
    last = head;
    while (last->next != NULL) last = last->next;
    last->next = head;

    printf("List reversed successfully!\n");
}

/* free whole circular list */
void free_list() {
    if (head == NULL) return;
    struct node *temp = head->next, *next;
    while (temp != head) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(head);
    head = NULL;
}

/* main */
int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteNode(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: reverse(); break;
            case 6:
                free_list();
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    free_list();
    return 0;
}
