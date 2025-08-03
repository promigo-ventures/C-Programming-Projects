#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ACCOUNTS 10

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char ownerName[50];
    double balance;
};

// Function prototypes
void createAccount(struct BankAccount accounts[], int *numAccounts);
void deposit(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount);
void withdraw(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount);
void checkBalance(struct BankAccount accounts[], int numAccounts, int accountNumber);

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;
    int accountNumber;
    double amount;

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Amount to Deposit: ");
                scanf("%lf", &amount);
                deposit(accounts, numAccounts, accountNumber, amount);
                break;
            case 3:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Amount to Withdraw: ");
                scanf("%lf", &amount);
                withdraw(accounts, numAccounts, accountNumber, amount);
                break;
            case 4:
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                checkBalance(accounts, numAccounts, accountNumber);
                break;
            case 5:
                printf("Exiting the Banking System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to create a new bank account
void createAccount(struct BankAccount accounts[], int *numAccounts) {
    if (*numAccounts < MAX_ACCOUNTS) {
        printf("Enter Account Owner's Name: ");
        scanf("%s", accounts[*numAccounts].ownerName);
        accounts[*numAccounts].accountNumber = *numAccounts + 1;
        accounts[*numAccounts].balance = 0.0;
        (*numAccounts)++;
        printf("Account created successfully. Account Number: %d\n", *numAccounts);
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

// Function to deposit money into an account
void deposit(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. Updated balance: %.2lf\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        if (accounts[accountNumber - 1].balance >= amount) {
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. Updated balance: %.2lf\n", accounts[accountNumber - 1].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to check the balance of an account
void checkBalance(struct BankAccount accounts[], int numAccounts, int accountNumber) {
    if (accountNumber >= 1 && accountNumber <= numAccounts) {
        printf("Account Holder: %s\n", accounts[accountNumber - 1].ownerName);
        printf("Account Balance: %.2lf\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}
