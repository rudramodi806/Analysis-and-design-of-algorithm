#include <stdio.h>

void displayArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int size = end - start + 1;
    int temp[size];

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];

    for(i = 0; i < size; i++)
        arr[start + i] = temp[i];
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal Array:\n");
    displayArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted Array (Merge Sort):\n");
    displayArray(arr, n);

    return 0;
}
