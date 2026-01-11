#include<stdio.h>
#include<stdlib.h>
//declaration of structure node
struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
//newNode creation function
struct Node* createNode(int data){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
//node insertion function
struct Node* insertNode(struct Node* root,int data){
    //root == NULL
    if(root == NULL){
        root = createNode(data);
        printf("Inserted %d successfully!\n",data);
        return root;
    };
    //data < root-> data
    if(data < root-> data){
        root -> lchild = insertNode(root -> lchild,data);
    }//data > root-> data
    else if(data > root-> data){
        root -> rchild = insertNode(root -> rchild,data);
    }//data == root-> data
    else{
        printf("Duplicate data! %d already exist in the tree!\n",data);
    }
    return root;
}   
//inorder Traversal function(left,root,right)
void inorderTraversal(struct Node* root){
    if(root != NULL){
        inorderTraversal(root -> lchild);
        printf("%d\t",root -> data);
        inorderTraversal(root -> rchild);
    }
}
//preorder Traversal function(root,left,right)
void preorderTraversal(struct Node* root){
    if(root != NULL){
        printf("%d\t",root -> data);
        preorderTraversal(root -> lchild);
        preorderTraversal(root -> rchild);
    }
}
//postorder Traversal function(left,right,root)
void postorderTraversal(struct Node* root){
    if(root != NULL){
        postorderTraversal(root -> lchild);
        postorderTraversal(root -> rchild);
        printf("%d\t",root -> data);
    }
}
//main function
int main(){
    struct Node* root = NULL;
    int choice , data;

       printf("===== Binary Search Tree (BST) Operations =====\n");

    do {
        printf("\n1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program. Thank you!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
