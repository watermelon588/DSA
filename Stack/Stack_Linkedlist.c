#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node top = NULL;


int main(){
    int choice,x,y,check,pos;
    do{
        printf("___________MENU_____________\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY \n");
        printf("5. STACK TOP\n");
        printf("6. IS EMPTY\n");
        printf("7. IS FULL\n");
        printf("8. EXIT\n");
        printf("\n_________________________________________________________________________\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            printf("Exitting ...\n");
            break;    
        default:
            printf("Invalid choice!\n");
            break;
        }

    }while(choice != 8);
    return 0;
}