#include <stdio.h>
#include<stdbool.h>
 //  create a function to check the numbers
 // get your user input 
 // display 1 or 0 if the function is ture/false


bool checkconditions(int num1, int num2){
    if( num1 == 5 || num2 == 5 || num1 + num2 == 5|| num1 - num2 == 5){
        return 1;
    }
    else {
        return 0;
    }

}

int main(){

    int num1;
    int num2;

    printf("Enter your first number:");
    scanf("%d", &num1);

    printf("Enter your second number");
    scanf("%d", &num2);

    if (checkconditions(num1, num2)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
