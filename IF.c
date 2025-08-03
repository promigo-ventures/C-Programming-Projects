#include<stdio.h>
#include<stdlib.h>


int max(int num1, int num2){
int result;

if(num1 > num2){
    result = num1;
}
else{
    result = num2;
}
return result;
}

int main(){

int num1, num2;

printf("Enter your first number: ");
scanf("%d", &num1);

printf("Enter your second number: ");
scanf("%d", &num2);

if(num1 == num2){
    printf("Both Numbers are the same");
}
else{

    printf("Answer: %d", max(num1, num2));
}
return 0;
 
}

