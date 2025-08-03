#include<stdio.h>
#include<stdlib.h>

int main()
{
    int luckynumbers[]= { 4, 8, 16, 22, 64, 78};
    luckynumbers[1] = 200;
    luckynumbers[3] = 100;
    printf("%d", luckynumbers[4]);

    return 0;

}