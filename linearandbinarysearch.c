#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[256];

int linearSearch(int n, int num) {
    int no_of_Comparison = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("In Linear Search: Number %d found at index %d\n", num, i);
            return no_of_Comparison;
        }
        no_of_Comparison++;
    }
    printf("Number %d not found in the array.\n", num);
    return no_of_Comparison;
}

int binarySearch(int n, int num) {
    int left = 0, right = n - 1;
    int no_of_Comparison = 0;
    while (left <= right) {
        no_of_Comparison++;
        int mid = (left + right) / 2;
        if (arr[mid] == num) {
            printf("In Binary Search: Number %d found at index %d\n", num, mid);
            return no_of_Comparison;
        }
        else if (arr[mid] < num) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Number %d not found in the array.\n", num);
    return no_of_Comparison;
}

int generateArray(int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

void benchmark(int size) {
    clock_t start, end;
    double time_taken;

    printf("\n--- LINEAR SEARCH ---\n");

    // Best Case (First element)
    start = clock();
    int linearBest = linearSearch(size, arr[0]);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Best Case: Comparisons = %d, Time = %.6f sec\n", linearBest, time_taken);

    // Worst Case (Not present)
    start = clock();
    int linearWorst = linearSearch(size, -1);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Worst Case: Comparisons = %d, Time = %.6f sec\n", linearWorst, time_taken);

    // Average Case (Middle element)
    start = clock();
    int linearAvg = linearSearch(size, arr[size / 2]);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Average Case: Comparisons = %d, Time = %.6f sec\n", linearAvg, time_taken);

    printf("\n--- BINARY SEARCH ---\n");

    // Best Case (Middle)
    start = clock();
    int binaryBest = binarySearch(size, arr[size / 2]);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Best Case: Comparisons = %d, Time = %.6f sec\n", binaryBest, time_taken);

    // Worst Case (Not present)
    start = clock();
    int binaryWorst = binarySearch(size, -1);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Worst Case: Comparisons = %d, Time = %.6f sec\n", binaryWorst, time_taken);

    // Average Case (Random middle element)
    start = clock();
    int binaryAvg = binarySearch(size, arr[size / 4]); // Element at 25% index
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Average Case: Comparisons = %d, Time = %.6f sec\n", binaryAvg, time_taken);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 256) {
        printf("Size exceeds maximum limit of 256. Setting size to 256.\n");
        size = 256;
    }

    generateArray(size);
    benchmark(size);

    return 0;
}
