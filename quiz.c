#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to represent a quiz question
struct QuizQuestion {
    char question[100];
    char options[4][50];
    int correctAnswer;
};

// Function to display the quiz questions and get user answers
int takeQuiz(struct QuizQuestion questions[], int numQuestions) {
    int score = 0;

    for (int i = 0; i < numQuestions; ++i) {
        // Display question and options
        printf("\nQuestion #%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; ++j) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }

        // Get user answer
        char userAnswer;
        printf("Input your answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);

        // Convert the user's answer to an index (0-3)
        int userIndex = toupper(userAnswer) - 'A';

        // Check if the user's answer is correct
        if (userIndex >= 0 && userIndex < 4 && userIndex == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c. %s\n", 'A' + questions[i].correctAnswer,
                   questions[i].options[questions[i].correctAnswer]);
        }
    }

    return score;
}

// Function to determine the grade based on the score
const char* determineGrade(int score) {
    if (score >= 9 && score <= 10) {
        return "Excellent";
    } else if (score >= 7 && score <= 8) {
        return "Good effort";
    } else if (score == 6) {
        return "Average";
    } else if (score >= 3 && score <= 5) {
        return "Lazy";
    } else if (score >= 0 && score <= 2) {
        return "Very lazy";
    } else {
        return "Invalid score";
    }
}

int main() {
    // Declare variables
    char userName[50];
    int score;
    const int numQuestions = 10;

    // Get user's name
    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = '\0'; // Remove the newline character

    // Define quiz questions
    struct QuizQuestion questions[numQuestions] = {
        {"Who is the first president of Nigeria?", {"Tafawa Balewa", "Johnson Aguiyi-ironsi", "Nnamdi Azikiwe", "Mohammadu Buhari"}, 2},
        {"The hottest region in the world is called?", {"Sahara Desert", "Amazon rainforest", "Samibiza Forest", "California"}, 0},
        {"Who invented computer?", {"Carrick bale", "IBM", "Charles Darwins", "Charles Babbage"}, 3},
        {"Who wrote 'Rich Dad Poor Dad'?", {"Robert Kiyosaki", "Chimamanda Adichie", "Alex Ekwueme", "Mark Twain"}, 0},
        {"Who is the founder of Apple?", {"Jeff Bezos", "Steve Jobs", "Bill Gate", "Aliko Dangote"}, 1},
        {"Which programming language is known for its readability?", {"C", "Java", "Python", "JavaScript"}, 2},
        {"What is the currency of United Kingdom is?", {"Dollar", "Euro", "Yen", "Pound"}, 3},
        {"Nigeria's had there first Independence on?", {"5th October 1961", "1st October 1960", "1st November 1969", "2nd October 1960"}, 1},
        {"Which ocean is the largest?", {"Atlantic Ocean", "Indian Ocean", "Southern Ocean", "Pacific Ocean"}, 3},
        {"what is the name of the current president of Nigeria?", {"Peter Obi", "Bola Ahmed Tinubu", "Goodluck Jonathan", "MC Oluomo"}, 1},
    };

    // Display welcome message
    printf("\nWelcome, %s! Let's start the quiz!\n", userName);

    // Take the quiz and get the score
    score = takeQuiz(questions, numQuestions);

    // Display the user's score and grade
    printf("\n%s, your score is: %d\n", userName, score);
    printf("Grade: %s\n", determineGrade(score));

    return 0;
}
