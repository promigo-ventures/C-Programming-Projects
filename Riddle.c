#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_PASSWORD_LENGTH 1000 
#define MAX_NAME_LENGTH 50
#define FILENAME "Riddle_txt"

typedef struct{
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int age;
    char password[50];
    long riddler_number;
   
}Riddle;

typedef char ARRAY[100][100];
typedef char string[100];



long generateRandomNumber() {
    return rand() % 100000;
}

int isNumberUnique(FILE *file, long number) {
    rewind(file);
    Riddle riddle;

    while (fscanf(file, "%s %s %d %ld %s", riddle.name, riddle.surname, &riddle.age, &riddle.riddler_number, riddle.password) == 5) {
        if (riddle.riddler_number == number) {
            return 0;  // Number is not unique
        }
    }
    return 1;  // Number is unique
}

void writeToFile(FILE *file, Riddle *riddle) {
    fprintf(file, "%s %s %d %ld %s\n", riddle->name, riddle->surname, riddle->age, riddle->riddler_number, riddle->password);
}

int signup(FILE *file){

    Riddle riddle;

    printf("Enter your Firstname:");
    scanf("%s", riddle.name);

    printf("Enter your Surname:");
    scanf("%s", riddle.surname);

    printf("Enter your age:");
    scanf("%d", &riddle.age);

    do {
        riddle.riddler_number = generateRandomNumber();
    } while (!isNumberUnique(file, riddle.riddler_number));

    printf("Create a password to protect your account:\n");
    scanf("%s", riddle.password);

    writeToFile(file, &riddle);

    printf("\nYou have successfully signed up.\nYour details are:\n");
    printf("Firstname: %s\nSurname: %s\nAge: %d\nRiddler's ID: %ld\n", riddle.name, riddle.surname, riddle.age, riddle.riddler_number);


}

int login(FILE *file){

return 0;
}


 int main (){


 }
