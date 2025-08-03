#include <stdio.h>

int main() {
    // Declare variables to store base, height, and area
    double base, height, area;

    // Prompt the user to enter the base of the triangle
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);

    // Prompt the user to enter the height of the triangle
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);

    // Calculate the area of the triangle
    area = 0.5 * base * height;

    // Display the area of the triangle
    printf("The area of the triangle is: %lf\n", area);

    return 0;
}