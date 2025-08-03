[#include<stdio.h>
#include<stdlib.h>

int max(int num1, int num2, int num3){
    int result;
    if(num1 >= num2 && num1 >= num3){
        result = num1;
    }
    else if(num2 >= num1 && num2 >= num3){
        result = num2;
    }
    else {
        result = num3;
    }
 
    return result;
}

int main(){
]
    int num1, num2, num3;

    printf("Enter your first number:");
    scanf("%d", &num1);

    printf("Enter your second number:");
    scanf("%d", &num2);   

    printf("Enter your third number:");
    scanf("%d", &num3);   

    if(num1 == num2 && num1 == num3){
            printf("Both Numbers are the same");
    }
    else if(num2 == num1 && num2 == num3){
            printf("All Numbers are the same");
    }
     else{
    printf("Answer: %d", max(num1, num2, num3));
     }

    return 0;


}

