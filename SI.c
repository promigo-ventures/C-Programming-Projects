#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    //Declare the variable that store principal, rate, time and interest
    double principal, rate, time, interest;

    //Request the user to input the principal
    printf("Enter the principal:");
    scanf("%lf", &principal);

    //Request the user to input the rate
    printf("Enter the rate:");
    scanf("%lf", &rate);

    //Request the user to input the time
    printf("Enter the time:");
    scanf("%lf", &time);
   
   //Calculate the Simple Interest
   interest = (principal * rate * time)/100;

   //Display the Simple Interest
   printf("The Simple Interest is: %lf\n", interest);

   return 0;

}