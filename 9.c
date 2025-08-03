#include<stdio.h>
#include<stdlib.h>

int main() 
{                 
    char characterName[]= "Promise";
    int CharacterAge = 25;
    printf("\n");
    printf("Your name is %s\n", characterName);
    printf("she is %d years old\n", CharacterAge);

    CharacterAge= 35;
    printf(" %s goes to ronik school\n", characterName);
    printf(" %s just clocked %d years old \n", characterName, CharacterAge);

    return 0;
}