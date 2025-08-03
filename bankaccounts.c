#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a bank account
struct BankAccount {
    long long accountNumber; // Using long long to store 10-digit account numbers
};

// Function to generate a random 10-digit account number
long long generateAccountNumber() {
    return rand() % 9000000000LL + 1000000000LL;  // Generates a random 10-digit account number
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Define the number of bank accounts
    const int numAccounts = 5;

    // Array of structures to store bank accounts
    struct BankAccount accounts[numAccounts];

    // Generate account numbers and store them in the array
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].accountNumber = generateAccountNumber();
    }

    // Display the generated account numbers
    printf("Generated Bank Account Numbers:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("Account %d: %lld\n", i + 1, accounts[i].accountNumber);
    }

    return 0;
}
