#include<stdio.h>
#include<stdlib.h>
//HELPER FUNCTIONS
//swap function
static void swap(int *x , int *y){
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
};
//print_arr function
static void print_arr(const int arr[], int n){
    int i ;
    for (i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
};
// SORTING ALGORITHMS
// 1. bubble sort
void bubble_sort(int arr[],int n){
    int swapped;
    for(int pass = 0; pass < n-1;pass++){
        swapped = 0;
        for(int i = 0 ; i < n-1-pass ;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i],&arr[i+1]);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
}
// 2. insertion sort
void insertion_sort(int arr[],int n){
    for(int i = 1;i<n ;i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j]> temp){
            arr[j+1] = arr[j];
            j-- ;
        }
        arr[j+1] = temp;
    }
};
// 3. selection sort
void selection_sort(int arr[],int n){
    for(int i = 0 ; i< n-1 ; i++){
        int min_idx = i;
        for(int j= i+1 ; j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx != i){
            swap(&arr[i],&arr[min_idx]);
        }
    }
};
// 4. merg sort
// 5. quick sort
// main function
int main (){
    int choice ;
    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Bubble sort\n");
        printf("2. insertion sort\n");
        printf("3. selection sort\n");
        printf("4. merg sort\n");
        printf("5. quick sort\n");
        printf("6. quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int n;
        int arr[200];
        printf("enter the number of elements : ");
        scanf("%d",&n);
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        } 
        switch (choice) {
            case 1:
                bubble_sort(arr, n);
                printf("Sorted (Bubble): ");
                print_arr(arr, n);
                break;
            case 2:
                insertion_sort(arr, n);
                printf("Sorted (Insertion): ");
                print_arr(arr, n);
                break;
            case 3:
                selection_sort(arr, n);
                printf("Sorted (Selection): ");
                print_arr(arr, n);
                break;
            case 4:
                printf("merg sort ! cant execute !");
                break ;
            case 5:
                printf("quick sort ! cant execute !");
                break ;
            case 6:
                printf("quitting ....");
                break ;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice !=5);
    return 0;
}