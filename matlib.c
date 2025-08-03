#include<stdio.h>
#include<stdlib.h>

int main()
{
    char color[25];
    char object[25];
    char namel[25];
    char nameR[25];

    printf("Enter a color:");
    scanf("%s", color);
    printf("Enter a object:");
    scanf("%s", object);
    printf("Enter a Name:");
    scanf("%s%s", namel, nameR);

    printf("Roses are %s\n", color);
    printf("voilets are %s\n", object);
    printf("i love %s %s\n", namel, nameR);

    return 0;

}