#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort function
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        // Move arr[j] to its correct position in the sorted part
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    printf("Sorted Array : ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements in an array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in the array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array : ");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");

    InsertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
