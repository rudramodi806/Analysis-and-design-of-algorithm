#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;  
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void printArray(int arr[], int n) {
    printf("Sorted Array : ");
    for(int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in an array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements in the array : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array : ");
    for(int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    SelectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
