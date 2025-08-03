#include <stdio.h>
#include <string.h>

void removeCharacter(char *str, int position) {
    int len = strlen(str);

    // Check if the position is valid
    if (position < 0 || position >= len) {
        printf("Invalid position. Please enter a position in the range 0 to %d.\n", len - 1);
        return;
    }

    // Shift characters to the left starting from the specified position
    for (int i = position; i < len - 1; ++i) {
        str[i] = str[i + 1];
    }

    // Null-terminate the string at the new length
    str[len - 1] = '\0';
}

int main() {
    // Declare variables
    char inputString[100];
    int position;

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    
    // Remove the trailing newline character
    inputString[strcspn(inputString, "\n")] = '\0';

    // Prompt user for position
    printf("Enter the position to remove (0 to %lu): ", strlen(inputString) - 1);
    scanf("%d", &position);

    // Remove the character at the specified position
    removeCharacter(inputString, position);

    // Display the modified string
    printf("Modified string: %s\n", inputString);

    return 0;
}