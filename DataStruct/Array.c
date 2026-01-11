// Array ADT
#include <stdio.h>
#include <stdlib.h>
// Array struct
struct Array
{
    int *A;
    int size;
    int length;
};
//swap 
void swap(int *x , int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}
// Display
void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
// Append
void append(struct Array *arr, int x)
{
    if (arr->length >= arr->size)
    {
        printf("array is full !");
        return;
    }
    arr->A[arr->length++] = x;
}
// Insert
void insert(struct Array *arr, int pos, int x)
{
    int i;
    // Size overflow check
    if (arr->length >= arr->size)
    {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    // insert element
    if (pos >= 0 && pos <= arr->length)
    {
        for (i = arr->length; i > pos; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[pos] = x;
        arr->length++;
    }
    else
    {
        printf("invalid position !");
        printf("Current length : %d\n Try again  !", arr->length);
        return;
    }
}
// Delete
int delete(struct Array *arr, int pos)
{
    int i, x;
    // array empty
    if (arr->length == 0)
    {
        printf("Array is currently empty.\n");
        return -1;
    }
    // position validation
    if (pos >= 0 && pos < arr->length)
    {
        x = arr->A[pos];
        for (i = pos; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return -1;
}
// Linear search
int linearSearch(struct Array *arr, int key){
    int i,found=-1;
    for(i=0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap (&arr->A[i],&arr->A[i-1]);
            found = i;
        }
    }
    return found;
}
int main()
{
    struct Array arr;
    int i, n, choice, x, pos,key;
    char y;
    printf("Enter the size of the array : ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("You want to add elements in the array ?\n");
    printf("y/n ?\n");
    scanf(" %c", &y);
    if (y == 'y')
    {
        printf("Enter the no. of elements in the array : \n");
        scanf("%d", &n);
        if (n > arr.size)
        {
            printf("Too many elements! Limiting to %d\n", arr.size);
            n = arr.size;
        }
        arr.length = n;
        printf("Enter elements: \n");
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr.A[i]);
        };
    }
    do
    {
        printf("\n________________ MENU _________________\n");
        printf("1. Append element \n");
        printf("2. Insert element (0 base indexing )\n");
        printf("3. Delete element (0 base indexing )\n");
        printf("4. Linear search (transposed)\n");
        printf("5. Display array \n");
        printf("6. exit \n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &x);
            append(&arr, x);
            break;
        case 2:
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter element : ");
            scanf("%d", &x);
            insert(&arr, pos, x);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d", &pos);
            int deleted = delete(&arr, pos);

            if (deleted != -1)
            {
                printf("Deleted element is : %d\n", deleted);
            }
            else
            {
                printf("Invalid position!\n");
            }
            break;
        case 4:
            printf("Enter key value : ");
            scanf("%d", &key);
            int searched = linearSearch(&arr,key);
            if(searched == -1){
                printf("%d not found !",key);
            }else{
                printf("%d found at position %d",key,searched);
            }
            break;
        case 5:
            printf("Array : \n");
            display(arr);
            break;
        case 6:
            printf("Exitting ...");
            break;
        default:
            printf("Invalid choice !");
            break;
        }
    } while (choice != 6);
    return 0;
}