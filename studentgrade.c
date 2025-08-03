#include <stdio.h>

// Function to calculate overall grade percentage
float calculateOverallGrade(float scores[], float weightages[], int numSubjects) {
    float totalScore = 0.0, totalWeightage = 0.0;

    for (int i = 0; i < numSubjects; i++) {
        totalScore += scores[i] * weightages[i];
        totalWeightage += weightages[i];
    }

    if (totalWeightage > 0) {
        return (totalScore / totalWeightage) * 100.0;
    } else {
        // Handling the case where totalWeightage is 0 to avoid division by zero
        return 0.0;
    }
}

int main() {
    const int numSubjects = 6;
    float scores[numSubjects];
    float weightages[numSubjects];

    // Input scores and weightages from the user
    printf("Enter scores for each subject:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: ", i + 1);        scanf("%f", &scores[i]);
    }

    printf("\nEnter weightages for each subject:\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &weightages[i]);
    }

    // Calculate overall grade percentage
    float overallGrade = calculateOverallGrade(scores, weightages, numSubjects);

    // Display the overall grade percentage
    printf("\nOverall Grade Percentage: %.2f%%\n", overallGrade);

    return 0;
}
