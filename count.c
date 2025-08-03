#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to convert a word to lowercase
void toLowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to update the word count in the array of WordCount structures
void updateWordCount(WordCount *wordCounts, int *totalWords, char *word) {
    for (int i = 0; i < *totalWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            // Word found, increment count
            wordCounts[i].count++;
            return;
        }
    }

    // Word not found, add it to the array
    strcpy(wordCounts[*totalWords].word, word);
    wordCounts[*totalWords].count = 1;
    (*totalWords)++;
}

int main() {
    FILE *file;
    char filename[100];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening file. Make sure the file exists.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORD_LENGTH];
    int totalWords = 0;

    // Read words from the file
    while (fscanf(file, "%s", word) == 1) {
        // Convert the word to lowercase
        toLowercase(word);

        // Update the word count
        updateWordCount(wordCounts, &totalWords, word);
    }

    // Close the file
    fclose(file);

    // Find the most frequently occurring word
    int maxCount = 0;
    char mostFrequentWord[MAX_WORD_LENGTH];

    for (int i = 0; i < totalWords; i++) {
        if (wordCounts[i].count > maxCount) {
            maxCount = wordCounts[i].count;
            strcpy(mostFrequentWord, wordCounts[i].word);
        }
    }

    // Display the word count and most frequently occurring word
    printf("\nWord Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    printf("\nMost Frequently Occurring Word: %s\n", mostFrequentWord);
    
    return 0;
}
