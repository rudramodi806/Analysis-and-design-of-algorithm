#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Iterative factorial function
unsigned long long factorial_itr(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive factorial function
unsigned long long factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    clock_t start, end;
    double cpu_time_used;

    // Iterative method
    start = clock();
    unsigned long long iter_result = factorial_itr(num);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nIterative Factorial of %d = %llu", num, iter_result);
    printf("\nTime taken (Iterative): %f seconds", cpu_time_used);

    // Recursive method
    start = clock();
    unsigned long long recur_result = factorial_recursive(num);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nRecursive Factorial of %d = %llu", num, recur_result);
    printf("\nTime taken (Recursive): %f seconds\n", cpu_time_used);

    return 0;
}
