// Array ADT
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
            if(i!=0){
                swap (&arr->A[i],&arr->A[i-1]);
            }
            found = i;
        }
    }
    return found;
}
//Binary search
int binarySearch(struct Array arr, int key){
    int low,high,mid;
    low = 0;
    high = arr.length-1;
    while(low <= high){
        mid = (low+high)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if (key < arr.A[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
//Binary search (recursion)
int RbinarySearch(struct Array arr,int l,int h, int key){
    int mid ;
    if(l <= h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if (key < arr.A[mid]){
            return RbinarySearch(arr,l,mid-1,key);
        }
        else{
            return RbinarySearch(arr,mid+1,h,key);
        }
    }
    return -1;
}
// Get , Set , Min , Max 
int get (struct Array arr, int pos){
    if(pos>=0 && pos < arr.length){
        return arr.A[pos];
    }
    return -1;
}
int set (struct Array *arr, int pos, int val){
    if(pos>=0 && pos < arr->length){
        arr->A[pos] = val;
        return 1;
    }else{
        return -1;
    }
}
int minimum (struct Array arr){
    int i,min;
    min = arr.A[0];
    if(arr.length >= 0){
        for(i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
        }
        return min;
    }else{
        return 0;
    }
}
int maximum (struct Array arr){
    int i,max;
    max = arr.A[0];
    if(arr.length >= 0){
        for(i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
        }
        return max;
    }else{
        return 0;
    }
}
// Sum , Avg
int Sum (struct Array arr){
    int i,sum;
    sum = 0;
    for(i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    return sum;
}
double Avg (struct Array arr){
    int i ;
    double sum = 0.0000;
    for(i=0;i<arr.length;i++){
        sum += arr.A[i];
    }
    double avg = (sum/arr.length);
    return avg;
}
void Reverse(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
int handleShift(char shiftcase){
    if(toupper(shiftcase) == 'L'){return 1;}
    else if(toupper(shiftcase) == 'R'){return 2;}
    else{return 0;}
}
void LShift(struct Array *arr){
    int i,temp;
    temp = arr->A[0];
    for(i=0;i<arr->length-1;i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}
void RShift(struct Array *arr){
    int i,temp;
    temp = arr->A[arr->length-1];
    for(i=arr->length-1;i>=0;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}
// Merge
struct Array* Merge(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->length + arr2->length +1;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    return arr3;
}
// Union
struct Array* Union(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->length + arr2->length +1;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){    
            arr3->A[k++]=arr1->A[i++];
        }
        else if(arr1->A[i]>arr2->A[j]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{         // if -> arr1->A[i] == arr2->A[j]  --> skip !
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    return arr3;
}
// Intersection
struct Array* Intersection(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->length + arr2->length +1;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }else if(arr1->A[i]>arr2->A[j]){             
            j++;
        }
        else{            // if -> arr1->A[i] == arr2->A[j]  --> keep !
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    return arr3;
}
// Difference
struct Array* Difference(struct Array *arr1,struct Array *arr2) {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->length + arr2->length +1;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }else if(arr1->A[i]>arr2->A[j]){    // Don't copy second array  --> skip !
            j++;
        }else{
            i++;
            j++;        // if -> arr1->A[i] == arr2->A[j]  --> skip !
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr3->A[k++]=arr2->A[j];
    }
    arr3->length=k;
    return arr3;
}
int main()
{
    struct Array arr, arr1 , arr2 , *mergedArr ,*UnionArr, *IntersectionArr, *DiffArr;
    int i, n, choice, x, pos,key,ele,S;
    char y,shiftcase;
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
        printf("4. Display array\n");
        printf("5. Linear search(Transposed) \n");
        printf("6. Binary search (sorted list) \n");
        printf("7. Reverse \n");
        printf("8. Get \n");
        printf("9. Set \n");
        printf("10. Minimum \n");
        printf("11. Maximum \n");
        printf("12. Sum \n");
        printf("13. Average \n");
        printf("14. Shift/Rotate \n");
        printf("_______ 2 Arrays _______\n");
        printf("15. Merge (2 sorted Arr) \n");
        printf("16. Union (2 sorted Arr) \n");
        printf("17. Intersection (2 sorted Arr) \n");
        printf("18. Difference (2 sorted Arr) \n");
        printf("19. exit \n");
        printf("\n_________________________________________________________________________\n");
        printf("\nEnter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &x);
            append(&arr, x);
            printf("\n_________________________________________________________________________\n");
            break;
        case 2:
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter element : ");
            scanf("%d", &x);
            insert(&arr, pos, x);
            printf("\n_________________________________________________________________________\n");
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
            printf("\n_________________________________________________________________________\n");
            break;
        case 4:
            printf("Array : \n");
            display(arr);
            printf("\n_________________________________________________________________________\n");
            break;
        case 5:
            printf("Enter key value : ");
            scanf("%d", &key);
            int searched = linearSearch(&arr,key);
            if(searched == -1){
                printf("%d not found !",key);
            }else{
                printf("%d found at position %d",key,searched);
            }
            printf("\n_________________________________________________________________________\n");
            break;
        case 6:
            printf("Enter key value : ");
            scanf("%d", &key);
            int Bsearched = binarySearch(arr,key);
            if(Bsearched == -1){
                printf("%d not found !",key);
            }else{
                printf("%d found at position %d",key,Bsearched);
            }
            printf("\n_________________________________________________________________________\n");
            break;
        case 7:
            Reverse(&arr);
            printf("Reversed array : ");
            display(arr);
            printf("\n_________________________________________________________________________\n");
            break;
        case 8:
            printf("Enter position : ");
            scanf("%d", &pos);
            ele = get(arr,pos);
            if(ele == -1){
                printf("Invalid position !",key);
            }else{
                printf("Element on index %d is : %d",pos,ele);
            }
            printf("\n_________________________________________________________________________\n");
            break;
        case 9:
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("Enter new value : ");
            scanf("%d", &key);
            int setele = set(&arr,pos,key);
            if(setele == -1){
                printf("Invalid position !",key);
            }else{
                printf("New element %d is set on index %d",key,pos);
            }
            printf("\n_________________________________________________________________________\n");
            break;
        case 10:
            printf("Minimun value of array is : %d", minimum(arr));
            printf("\n_________________________________________________________________________\n");
            break;
        case 11:
            printf("Maximun value of array is : %d", maximum(arr));
            printf("\n_________________________________________________________________________\n");
            break;
        case 12:
            printf("Sum of elements in array is : %d", Sum(arr));
            printf("\n_________________________________________________________________________\n");
            break;
        case 13:
            printf("Average value in array is : %.2lf", Avg(arr));
            printf("\n_________________________________________________________________________\n");
            break;
        case 14:
            do{
                printf("Left shift <- or Right Shift -> ?\n");
                printf("L/R ? :");
                scanf(" %c", &shiftcase);
                S = handleShift(shiftcase);
                if(S == 1){
                    LShift(&arr);
                    printf("Elements shifted by unit 1: \n");
                    display(arr);
                }else if(S == 2){
                    RShift(&arr);
                    printf("Elements shifted by unit 1: \n");
                    display(arr);
                }else{
                    printf("Enter valid character !\n");
                }
            }while(S == 0);
            printf("\n_________________________________________________________________________\n");
            break;
        case 15:
            printf("Provide 2 SORTED arrays !\n");
            printf("Enter the size of the array 1 : ");
            scanf("%d", &arr1.size);
            arr1.A = (int *)malloc(arr1.size * sizeof(int));
            arr1.length = arr1.size;
            printf("Enter elements Arr 1: \n");
            for (i = 0; i < arr1.length; i++)
            {
                scanf("%d", &arr1.A[i]);
            };
            printf("Enter the size of the array 2 : ");
            scanf("%d", &arr2.size);
            arr2.A = (int *)malloc(arr2.size * sizeof(int));
            arr2.length = arr2.size;
            printf("Enter elements Arr 2: \n");
            for (i = 0; i < arr2.length; i++)
            {
                scanf("%d", &arr2.A[i]);
            };
            mergedArr = Merge(&arr1,&arr2);  // pointer
            printf("New merged array :  ");
            display(*mergedArr);  // call by value
            printf("\n_________________________________________________________________________\n");
            break;
        case 16:
            printf("Provide 2 SORTED arrays !\n");
            printf("Enter the size of the array 1 : ");
            scanf("%d", &arr1.size);
            arr1.A = (int *)malloc(arr1.size * sizeof(int));
            arr1.length = arr1.size;
            printf("Enter elements Arr 1: \n");
            for (i = 0; i < arr1.length; i++)
            {
                scanf("%d", &arr1.A[i]);
            };
            printf("Enter the size of the array 2 : ");
            scanf("%d", &arr2.size);
            arr2.A = (int *)malloc(arr2.size * sizeof(int));
            arr2.length = arr2.size;
            printf("Enter elements Arr 2: \n");
            for (i = 0; i < arr2.length; i++)
            {
                scanf("%d", &arr2.A[i]);
            };
            UnionArr = Union(&arr1,&arr2);  // pointer
            printf("Union of both the arrays :  ");
            display(*UnionArr);  // call by value
            printf("\n_________________________________________________________________________\n");
            break;
        case 17:
            printf("Provide 2 SORTED arrays !\n");
            printf("Enter the size of the array 1 : ");
            scanf("%d", &arr1.size);
            arr1.A = (int *)malloc(arr1.size * sizeof(int));
            arr1.length = arr1.size;
            printf("Enter elements Arr 1: \n");
            for (i = 0; i < arr1.length; i++)
            {
                scanf("%d", &arr1.A[i]);
            };
            printf("Enter the size of the array 2 : ");
            scanf("%d", &arr2.size);
            arr2.A = (int *)malloc(arr2.size * sizeof(int));
            arr2.length = arr2.size;
            printf("Enter elements Arr 2: \n");
            for (i = 0; i < arr2.length; i++)
            {
                scanf("%d", &arr2.A[i]);
            };
            IntersectionArr = Intersection(&arr1,&arr2);  // pointer
            printf("Intersection of both the arrays :  ");
            display(*IntersectionArr);  // call by value
            printf("\n_________________________________________________________________________\n");
            break;
        case 18:
            printf("Provide 2 SORTED arrays !\n");
            printf("Enter the size of the array 1 : ");
            scanf("%d", &arr1.size);
            arr1.A = (int *)malloc(arr1.size * sizeof(int));
            arr1.length = arr1.size;
            printf("Enter elements Arr 1: \n");
            for (i = 0; i < arr1.length; i++)
            {
                scanf("%d", &arr1.A[i]);
            };
            printf("Enter the size of the array 2 : ");
            scanf("%d", &arr2.size);
            arr2.A = (int *)malloc(arr2.size * sizeof(int));
            arr2.length = arr2.size;
            printf("Enter elements Arr 2: \n");
            for (i = 0; i < arr2.length; i++)
            {
                scanf("%d", &arr2.A[i]);
            };
            DiffArr = Difference(&arr1,&arr2);  // pointer
            printf("Difference of both the arrays :  ");
            display(*DiffArr);  // call by value
            printf("\n_________________________________________________________________________\n");
            break;
        case 19:
            printf("Exitting ...");
            printf("\n_________________________________________________________________________\n");
            break;
        default:
            printf("Invalid choice !");
            printf("\n_________________________________________________________________________\n");
            break;
        }
    } while (choice != 19);
    return 0;
}