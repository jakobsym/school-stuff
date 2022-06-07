//jakob symchych (nrz473)
//Error Trapped Input
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Age(unsigned short birth_y)
{
    if(birth_y < 9 || birth_y > 12)
    {
        printf("Sorry. You are not between the age of 9 and 12.\n");
    }
    else
    {
        printf("You are old enough to play! Welcome to the team!\n");

    }

}

void Name(char *first_n)
{
    if (strlen(first_n) > 32)
     {
         printf("Sorry your name cannot exceed 32 characters. Please try again.\n");
         scanf("%s", first_n);
         
     }
}

void City(char *city)
{
    if (strlen(city) > 64)
    {
        printf("Sorry city name cannot exceed 64 characters. Please try again.\n");
        scanf(" %[^\n]", city);
    }
}


int main() {
    char first_n[32]; 
    unsigned short birth_y;
    char city[64];

    
    printf("What is the name of your city?\n");
    scanf(" %[^\n]", city);
    City(city);

    printf("What is your first name?\n");
    scanf("%s", first_n);
    Name(first_n);

    printf("How old are you?\n");
    scanf("%hu", &birth_y);
    Age(birth_y);

    return 0;
}