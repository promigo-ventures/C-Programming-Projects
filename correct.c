#include<stdio.h>
#include<conio.h>

int main()
{
    float num1, num2;
    char ch;


    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Enter the operator:(+, -, *, /)");
    scanf("%c", &ch);
    
    if(ch=='+')
    printf("Answer = %0.2f", num1 + num2);
    else if(ch=='-')
    printf("Answer = %0.2f", num1 - num2);
    else if(ch=='*')
    printf("Answer =  %0.2f", num1 * num2);
    else if(ch=='/')
    printf("Result = %0.2f", num1 / num2);


    getch();

    return 0;
}