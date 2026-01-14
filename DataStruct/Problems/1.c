// Student Challenge : Finding Single or Multiple Missing Elements in an Sorted Array.
#include<stdio.h>

int main(){
    int i,low,high,diff;
    int arr[] = {1,4,5,6,7,9,10,11,14,15,20};
    int length = sizeof(arr) / sizeof(arr[0]);
    low = arr[0];
    high = arr[length-1];
    diff = arr[0] - 0;
    printf("Missing elements are : ");
    for(i=0;i<length;i++){
        if(arr[i]-i != diff){
            while(diff < arr[i]-i){
                printf("%d ",diff+i);
                diff++;
            }
        }
    }
    return 0;
}