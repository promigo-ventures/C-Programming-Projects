#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a dice roll (for attacks)
int rollDice() {
    return rand() % 6 + 1;  // Generates a random number between 1 and 6
}

// Function to simulate the game
void playGame() {
    int playerHealth = 100;  // Initial health points for the player
    int enemyHealth = 50;   // Initial health points for the enemy

    printf("Welcome to the Text-Based Game!\n");

    while (playerHealth > 0) {
        printf("\nYour HP: %d\nEnemy HP: %d\n", playerHealth, enemyHealth);
        printf("1. Attack\n2. Defend\n3. Quit\n");

        int choice;
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Player attacks
                printf("You attack the enemy!\n");
                int playerAttack = rollDice();
                printf("You dea %d damage to the enemy.\n", playerAttack);
                enemyHealth -= playerAttack;

                // Enemy attacks back
                printf("The enemy counterattacks!\n");
                int enemyAttack = rollDice();
                printf("The enemy deals %d damage to you.\n", enemyAttack);
                playerHealth -= enemyAttack;
                break;

            case 2:
                // Player defends
                printf("You defend against the enemy's attack.\n");
                int playerDefense = rollDice();
                printf("Your defense value: %d\n", playerDefense);

                // Enemy attacks
                int enemyAttackAfterDefense = rollDice();
                printf("The enemy attacks, but your defense absorbs %d damage.\n", playerDefense);
                int damageTaken = enemyAttackAfterDefense - playerDefense;
                if (damageTaken < 0) {
                    damageTaken = 0;
                }
                printf("You take %d damage.\n", damageTaken);
                playerHealth -= damageTaken;
                break;

            case 3:
                // Quit the game
                printf("You decide to quit the game.\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Check if the enemy is defeated
        if (enemyHealth <= 0) {
            printf("Congratulations! You defeated the enemy.\n");
            return;
        }

        // Check if the player is defeated
        if (playerHealth <= 0) {
            printf("Game Over! You were defeated by the enemy.\n");
            return;
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the game
    playGame();

    return 0;
}
