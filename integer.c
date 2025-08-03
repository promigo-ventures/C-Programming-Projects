#include <stdio.h>

// Function prototypes
void generateFibonacciIterative(int n);
int fibonacciRecursive(int n);

int main() {
    int n, choice;

    // Input the value of n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Choose whether to display the sequence iteratively or recursively
    printf("Choose method:\n");
    printf("1. Iterative\n");
    printf("2. Recursive\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Display the Fibonacci sequence iteratively
            generateFibonacciIterative(n);
            break;

        case 2:
            // Display the Fibonacci sequence recursively
            printf("Fibonacci sequence (recursive): ");
            for (int i = 0; i < n; i++) {
                printf("%d ", fibonacciRecursive(i));
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function to generate and display Fibonacci sequence iteratively
void generateFibonacciIterative(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci sequence (iterative): ");

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

// Function to calculate Fibonacci sequence recursively
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
