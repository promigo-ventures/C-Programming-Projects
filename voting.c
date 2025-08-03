#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_PASS_LENGTH 20

struct User {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
    int voted;
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", users[userCount].username);

    printf("Enter password: ");
    scanf("%s", users[userCount].password);

    users[userCount].voted = 0;
    userCount++;

    printf("User registered successfully.\n");
}

int loginUser() {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return i; // return index of the logged-in user
        }
    }

    printf("Invalid username or password.\n");
    return -1; // return -1 if login fails
}

void vote(int userIndex) {
    if (users[userIndex].voted == 1) {
        printf("You have already voted.\n");
        return;
    }

    printf("Cast your vote:\n");
    // Add your voting mechanism here

    users[userIndex].voted = 1;
    printf("Vote cast successfully.\n");
}

int main() {
    int choice;
    int currentUserIndex = -1;

    while (1) {
        printf("\nVOTING SYSTEM\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                currentUserIndex = loginUser();
                break;
            case 3:
                if (currentUserIndex != -1) {
                    vote(currentUserIndex);
                } else {
                    printf("Please login first.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
