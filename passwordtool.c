#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a password meets complexity rules
bool checkPasswordStrength(char password[]) {
    // Rule 1: Minimum length
    if (strlen(password) < 8) {
        printf("Password should be at least 8 characters long.\n");
        return false;
    }

    // Rule 2: Mix of characters (at least one uppercase, one lowercase)
    bool hasUpperCase = false;
    bool hasLowerCase = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            hasUpperCase = true;
        } else if (islower(password[i])) {
            hasLowerCase = true;
        }
    }

    if (!hasUpperCase || !hasLowerCase) {
        printf("Password should include a mix of uppercase and lowercase letters.\n");
        return false;
    }

    // Rule 3: Presence of special symbols
    const char *specialSymbols = "!@#$%^&*()-=_+[]{}|;:'\",.<>/?";
    bool hasSpecialSymbol = false;

    for (int i = 0; password[i] != '\0'; i++) {
        if (strchr(specialSymbols, password[i]) != NULL) {
            hasSpecialSymbol = true;
            break;
        }
    }

    if (!hasSpecialSymbol) {
        printf("Password should include at least one special symbol.\n");
        return false;
    }

    // All rules passed
    return true;
}

int main() {
    char password[50];

    // Input password from the user
    printf("Enter your password: ");
    scanf("%s", &password);

    // Check password strength
    if (checkPasswordStrength(password)) {
        printf("Password is strong. Good job!\n");
    } else {
        printf("Password does not meet the complexity rules. Please try again.\n");
    }

    return 0;
}
