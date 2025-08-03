#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 20
#define FILENAME "voter_data.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    long voters_number;
    char password[MAX_PASSWORD_LENGTH];
} Voter;

long generateRandomNumber() {
    return rand() % 10000000000;
}

int isNumberUnique(FILE *file, long number) {
    rewind(file);
    Voter voter;

    while (fscanf(file, "%s %d %ld %s", voter.name, &voter.age, &voter.voters_number, voter.password) == 4) {
        if (voter.voters_number == number) {
            return 0;  // Number is not unique
        }
    }
    return 1;  // Number is unique
}

void writeToFile(FILE *file, Voter *voter) {
    fprintf(file, "%s %d %ld %s\n", voter->name, voter->age, voter->voters_number, voter->password);
}

void readFromFile(FILE *file) {
    rewind(file);
    Voter voter;

    printf("\nList of all registered voters:\n\n");
    while (fscanf(file, "%s %d %ld %s", voter.name, &voter.age, &voter.voters_number, voter.password) == 4) {
        printf("Name: %s\nAge: %d\nVoter's ID: %ld\n\n", voter.name, voter.age, voter.voters_number);
    }
}

int signUp(FILE *file) {
    Voter newVoter1;
    Voter newVoter2;
    Voter newVoter;


    printf("Enter your name:\n");
    scanf("%s %s", newVoter1.name, newVoter2.name);

    printf("Enter your age:\n");
    scanf("%d", &newVoter.age);

    do {
        newVoter.voters_number = generateRandomNumber();
    } while (!isNumberUnique(file, newVoter.voters_number));

    printf("Create a password to protect your account:\n");
    scanf("%s", newVoter.password);

    // Write the provided information to the file
    writeToFile(file, &newVoter);

    printf("\nYou have successfully signed up.\nYour details are:\n");
    printf("Name: %s %s\nAge: %d\nVoter's ID: %ld\n", newVoter1.name, newVoter2.name, newVoter.age, newVoter.voters_number);

    return 0;
}

int login(FILE *file) {
    long voterID;
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    printf("Enter your voter's ID:\n");
    scanf("%ld", &voterID);

    printf("Enter your password:\n");
    scanf("%s", password);

    rewind(file);
    Voter voter;

    while (fscanf(file, "%s %d %ld %s", voter.name, &voter.age, &voter.voters_number, voter.password) == 4) {
        if (voter.voters_number == voterID) {
            found = 1;
            if (strcmp(voter.password, password) == 0) {
                printf("Login Successful!!!\n");
                return 1;
            } else {
                printf("Login unsuccessful!\nIncorrect password\n");
                return 0;
            }
        }
    }

    if (found == 0) {
        printf("Login denied!\nUnrecognized Voter's ID\n");
    }

    return 0;
}

int main() {
    srand((unsigned int)time(NULL));

    FILE *file = fopen(FILENAME, "a+");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int choice;

    do {
        printf("\nWelcome to the Aptech Voting System!!!\n");
        printf("Please choose one of the following:\n1. Sign Up\n2. Login\n3. Show all registered voters\n4. Exit\n\nInput your selection (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp(file);
                break;
            case 2:
                login(file);
                break;
            case 3:
                readFromFile(file);
                break;
            case 4:
                break;
            default:
                printf("Wrong input\nPlease enter a number between 1 and 4");
        }
    } while (choice != 4);

    fclose(file);

    return 0;
}
