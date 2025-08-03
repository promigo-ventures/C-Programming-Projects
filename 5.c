#include<stdio.h>
#include<stdlib.h>

double square(double num) {
    double result = num * num * num ;
    return result;
}
int main()
{
    printf("Answer: %f", square(2));
    return 0;
} 
