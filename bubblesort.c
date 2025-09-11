#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[],int n){
    for(int i=0 ; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void printArray(int arr[],int n){
    printf("Sorted Array : ");
    for(int i=0; i<n; i++){
        printf(" %d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter the number of elements in an array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements in the array : ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array : ");
    for(int i=0; i<n; i++){
        printf(" %d ",arr[i]);
    }
    BubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}