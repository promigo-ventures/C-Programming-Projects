#include<stdio.h>
#include<stdlib.h>

int main()
{
    void sayHi(char name[]);
    sayHi ("mike");
    sayHi ("Tom");
    sayHi ("oscar");

    return 0;
    
    
}
    void sayHi(char name[]){

    printf("Hello %s\n", name);
   
} 