#include <stdio.h>

int main() {
    // Declare variables
    int count, number;

    // Prompt user for the number of values to check
    printf("Enter the number of values to check: ");
    scanf("%d", &count);

    // Check each number
    for (int i = 1; i <= count; ++i) {
        // Prompt user for input
        printf("Enter positive number #%d: ", i);
        scanf("%d", &number);

        // Check if the number is a multiple of 3 or 7
        if (number > 0) {
            if (number % 3 == 0) {
                printf("%d is a multiple of 3.\n", number);
            } 
            else if (number % 7 == 0) {
                printf("%d is a multiple of 7.\n", number);
            } 
            else {
                printf("%d is neither a multiple of 3 nor 7.\n", number);
            }
        } 
        else {
            printf("Please enter a positive number.\n");
            // Decrement the loop counter to repeat the current iteration
            --i;
        }
    }

    return 0;
}
