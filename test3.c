#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    double num1;
    double num2;
    int selected_operation;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("Type 1 to add:\n" );
    printf("Type 2 to subtract:\n" );
    printf("Type 3 to multiply:\n");
    printf("Type 4 to divide:\n");

     
     printf("Enter Number:");
     scanf("%f", &selected_operation);

    
    switch (selected_operation)
    {
    case 1:
        printf("Answer: %f", num1 + num2);
        break;

    case 2:
        printf("Answer: %f", num1 - num2);
        break;
        
    case 3:
        printf("Answer: %f", num1 * num2);
        break;

    case 4:
        printf("Answer: %f", num1 / num2);
        break;

    default:
       printf("Invalid");
        break;
    }
    


    

    
    
    return 0;
}