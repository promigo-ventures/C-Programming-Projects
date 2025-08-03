
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


typedef struct OPT
{
    int options;
    int options_1;
    int options_2;
    int options_3;
    int options_4;
}opt;

typedef char str[100];
typedef char ARRAY[50][50];

// typedef char arry[100][100] ;

ARRAY president ;
ARRAY Government ;
ARRAY Local ;

str name = "\nWelcome to Aptech's voting system\nSelect one Election your voting for below:\n\n";


int main(){
printf("%s", name);
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
strcpy(Local[2],"MR Chiugba");


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
            if (level == 1)
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
        if (level2 == 1)
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
        if (level3 == 1)
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
            iter = false;
            break;
        
        }
        }
}