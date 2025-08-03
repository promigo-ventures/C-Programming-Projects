#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>

#define MAX_NAME_LENGTH 2000
#define MAX_PASSWORD_LENGTH 20
#define FILENAME "voter_data.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char second_name[MAX_NAME_LENGTH];
    int age;
    long voters_number;
    char password[MAX_PASSWORD_LENGTH];
    int selected_options[3];
} Voter;

typedef struct OPT
{
    int options;
    int options_1;
    int options_2;
    int options_3;
    int options_4;
}opt;

typedef char str[150];
typedef char ARRAY[100][100];

// typedef char arry[100][100] ;

ARRAY president ;
ARRAY Government ;
ARRAY Local ;

long generateRandomNumber() {
    return rand() % 100000000;
}

int isNumberUnique(FILE *file, long number) {
    rewind(file);
    Voter voter;

    while (fscanf(file, "%s %s %d %ld %s", voter.name, voter.second_name, &voter.age, &voter.voters_number, voter.password) == 5) {
        if (voter.voters_number == number) {
            return 0;  // Number is not unique
        }
    }
    return 1;  // Number is unique
}

void writeToFile(FILE *file, Voter *voter) {
    fprintf(file, "%s %s %d %ld %s %d %d %d\n", voter->name, voter->second_name, voter->age, voter->voters_number, voter->password, voter->selected_options[0], voter->selected_options[1], voter->selected_options[2]);
}

void readFromFile(FILE *file) {
    rewind(file);
    Voter voter;

    printf("\nList of all registered voters:\n\n");
    while (fscanf(file, "%s %s %d %ld %s %d %d %d", voter.name, voter.second_name,  &voter.age, &voter.voters_number, voter.password, &voter.selected_options[0], &voter.selected_options[1], &voter.selected_options[2]) == 8) {
        printf("SurName: %s\n FirstName: %s\nAge: %d\nVoter's ID: %ld\nSelected Options: %d %d %d\n\n", voter.name, voter.second_name, voter.age, voter.voters_number, voter.selected_options[0], voter.selected_options[1], voter.selected_options[2]);
    }
}

int signUp(FILE *file) {
    Voter newVoter;


    printf("Enter your Surname:\n");
    scanf("%s", newVoter.name);

    printf("Enter your Firstname:\n");
    scanf("%s", newVoter.second_name);

    printf("Enter your age:\n");
    scanf("%d", &newVoter.age);

    do {
        newVoter.voters_number = generateRandomNumber();
    } while (!isNumberUnique(file, newVoter.voters_number));

    printf("Create a password to protect your account:\n");
    scanf("%s", newVoter.password);

    newVoter.selected_options[0] = -1;
    newVoter.selected_options[1] = -1;
    newVoter.selected_options[2] = -1;

    // Write the provided information to the file
    writeToFile(file, &newVoter);

    printf("\nYou have successfully signed up.\nYour details are:\n");
    printf("SurName: %s\nFirstName: %s\nAge: %d\nVoter's ID: %ld\n", newVoter.name, newVoter.second_name, newVoter.age, newVoter.voters_number);

    return 0;
}

int login(FILE *file) {
    long voterID;
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

opt option;
int level = 0;
int level2 = 0;
int level3 = 0;
bool iter = true;
strcpy(president[0],"Shallipoppi");
strcpy(president[1],"Mommy Gozo");
strcpy(president[2],"Brother Sope");
strcpy(Government[0],"Uncle Miracle");
strcpy(Government[1],"Daddy Gozo");
strcpy(Government[2],"Regaleaon");
strcpy(Local[0],"MR Fred");
strcpy(Local[1],"Ekiti");
strcpy(Local[2],"MR Chiuba");


    printf("Enter your voter's ID:\n");
    scanf("%ld", &voterID);

    printf("Enter your password:\n");
    scanf("%s", password);

    rewind(file);
    Voter voter;

    while (fscanf(file, "%s %s %d %ld %s %d %d %d", voter.name, voter.second_name, &voter.age, &voter.voters_number, voter.password, &voter.selected_options[0], &voter.selected_options[1], &voter.selected_options[2]) == 8) {
        if (voter.voters_number == voterID) {
            found = 1;
            if (strcmp(voter.password, password) == 0) {
                printf("Login Successful!!!\n");
                printf("\nSelect one Election your voting for below:\n\n");

while (iter)
    { 
    printf("1- Presidential Election\n");
    printf("2- Governorship Election\n");
    printf("3- Local Government Chairman Election\n");
    printf("4- Submit vote\n");
    printf("\nInput your selection (1/2/3/4): ");
    scanf("%d",&option.options);

       switch(option.options){
            case 1:
            if (level != 0)
            {
                printf("don't repeat the same value\n");
            }else
            {    printf("\nYou have choosen Presidential Election\n");
                printf("Vote for Any President in any party of your choice\n");
                printf("Options\n");
                printf("1 - APC -> Shallipoppi\n");
                printf("2 - PDP -> Mommy Gozo\n");
                printf("3 - LP  -> Brother Sope\n");
                printf("\nInput your selection (1/2/3/4): ");
                scanf("%d",&option.options_1);
                printf("Your Vote for the President has been accepted\n\n");
                level = 1;
                }
            break;
        case 2:
        if (level2 != 0)
            {
                printf("don't repeat the same value");
            }else
            {printf("\nYou have choosen State Governorship Election\n");
            printf("Vote for Any Governor in any party of your choice\n");
            printf("Options\n");
            printf("1 - APC -> Uncle Miracle\n");
            printf("2 - PDP -> Daddy Gozo\n");
            printf("3 - LP  -> Regaleaon\n");
            printf("\nInput your selection (1/2/3/4): ");
            scanf("%d",&option.options_2);
            printf("Your Vote for the Governor has been accepted\n\n");
            level2 = 1;
            }
            break;
        case 3:
        if (level3 != 0)
            {
                printf("don't repeat the same value");
            }else
            {printf("\nYou have choosen to vote for A local Government Chairman\n");
            printf("Vote for Any Local Government Chairman in any party of your choice\n");
            printf("Options\n");
            printf("1 - APC -> MR Fred\n");
            printf("2 - PDP -> Ekiti\n");
            printf("3 - LP  -> MR Chiuba\n");
            printf("\nInput your selection (1/2/3/4): ");
            scanf("%d",&option.options_3);
            printf("Your vote for Local Government Chhairman has been accepted\n\n");
            level3 =1;
            }
            break;
        case 4:
            printf("The vote has successfully ended..\n");
            printf("The choosen candidates for each level of Government are ready to be Displayed\n");
            printf("Your Selected candidates are (President/Governor/Local Government Chairman):\n");
            printf("%d %s\n",option.options_1, president[option.options_1-1]);
            printf("%d %s\n",option.options_2, Government[option.options_2-1]);
            printf("%d %s\n",option.options_3, Local[option.options_3-1]);
            iter = false;
            break;
        default:
            printf("Enter a valid input!!\n");
            break;

        
        }
            printf("Your previously selected options:\n");
            printf("Option 1: %s\n", president[voter.selected_options[0]]);
            printf("Option 2: %s\n", Government[voter.selected_options[1]]);
            printf("Option 3: %s\n", Local[voter.selected_options[2]]);

        return 1;
    }
        }
            else {
                printf("Login unsuccessful!\nIncorrect password\n");
                return 0;
            }
        
    }
}

    if (found == 0) {
        printf("Login denied!\nUnrecognized Voter's ID or Incorrect password\n");
    }

    return 0;

}

int main() {
    srand((unsigned int)time(NULL));

    FILE *file = fopen(FILENAME, "a+");

    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    int choice;

    do {
        printf("\nWelcome to the Aptech Voting System!!!\n");
        printf("Please choose one of the following:\n1. Sign Up\n2. Login\n3. Show all registered voters\n4. Exit\n\nInput your selection (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signUp(file);
                break;
            case 2:
                login(file);
                break;
            case 3:
                readFromFile(file);
                break;
            case 4:
                break;
            default:
                printf("Wrong input\nPlease enter a number between 1 and 4");
        }
    } while (choice != 4);

    fclose(file);

    return 0;
}
