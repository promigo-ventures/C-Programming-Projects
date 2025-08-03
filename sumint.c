


#include <stdio.h>
#include <stdbool.h>

// Function to check the conditions
bool checkConditions(int num1, int num2) {
    // Check if either one of them is 5 or their difference is 5
    if (num1 == 5 || num2 == 5 || num1 - num2 == 5) {
        return true;
    } else {
        return false;
    }
} 

int main() {
    // Declare variables
    int num1, num2;

    // Prompt user for input
    printf("Enter the first integer: ");
    scanf("%d", &num1);

    printf("Enter the second integer: ");
    scanf("%d", &num2);

    // Check conditions and display result
    if (checkConditions(num1, num2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
