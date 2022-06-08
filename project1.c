/* CS 1714 Spring 2022 Programming Recitation 1 */
// Jakob Symchych (nrz473)
// Create a program that allows a user to input an entire little league team. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ParentName(char *pfirst_n, char *plast_n) //parent first, and last name check
{ 
    strcat(pfirst_n, plast_n);
    if(strlen(strcat(pfirst_n, plast_n)) >32)
    {
        printf("Sorry your parent/guardian name cannot exceed 32 characters. Please try again starting with the first name, then last name.\n");
        scanf("%s", pfirst_n);
        scanf("%s", plast_n);
    }

} 


void Age(unsigned short birth_y)
{
    unsigned short currYear = 2022;
    unsigned short checkedYear;
    checkedYear = (currYear - birth_y);

    if(checkedYear < 9 || checkedYear > 12)
    {
        printf("Sorry. You are not between the age of 9 and 12.\n\n");
    }
    else
    {
        printf("You are old enough to play! Welcome to the team!\n\n");

    }

}

void Name(char *first_n, char *last_n)
{
    strcat(first_n, last_n);
   
    if (strlen(strcat(first_n, last_n)) > 32)
     {
        printf("Sorry your name cannot exceed 32 characters. Please try again starting with your first name.\n");
        scanf("%s", first_n);
        scanf("%s", last_n);
         
     }
}

void City(char *city, char *street)
{
    if (strlen(strcat(city, street)) > 64)
    {
        printf("Sorry city and street address cannot exceed 64 characters.\n");
        printf("Please try again. Starting with your city then your address.\n\n");
        scanf(" %[^\n]", city);
        scanf(" %[^\n]", street);
    }
}


int main() {
    char plFirst[32], plLast[32], parent_first[32], parent_last[32];
    char first_n[32], choice;
    unsigned short birth_y;
    char city[64], street[64], phone_num[32];
    int i;

    enum PhoneType {home, work, cell};
    enum PhoneType contact;

    enum Relationship {mother, father, grandmother, grandfather, other} guardian;

   
    do
    {  
        printf("\nEnter 'n' to quit, or 'c' to add players.\n");
        scanf(" %c", &choice);

        if (choice == 'n'){
            printf("You have quit the program.\n\n");
            break;

        }
        else if (choice == 'c'){
            printf("What is the name of your city?\n");
            scanf(" %[^\n]", city);
           
            printf("What is your street address?\n");
            scanf(" %[^\n]", street);
            City(city, street);

            printf("What is your parent/guardians first name?\n");
            scanf("%s", parent_first);
            printf("What is your parent/guardians last name?\n");
            scanf("%s", parent_last);
            ParentName(parent_first, parent_last);

            printf("Press the digit that corresponds with your parent/guardian:\n\n");
            printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
            scanf("%u", &guardian);
    
            switch(guardian){
                case 0:
                printf("Mother was selected.\n");
                break;

                case 1:
                printf("Father was selected.\n");
                break;

                case 2:
                printf("Grandmother was selected.\n");
                break;
        
                case 3:
                printf("Grandfather was selected.\n");
                break;

                case 4:
                printf("Other was selected.\n");
                break;
            }

            printf("What is parent/guardian phone number? ('555-555-5555')\n");
            scanf("%s", phone_num);

            printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
            printf("Home: 0\nWork: 1\nCell: 2\n\n");
            scanf("%u", &contact);

            switch(contact){
                case 0:
                printf("Home was selected.\n");
                break;

                case 1:
                printf("Work was selected.\n");
                break;

                case 2:
                printf("Cell was selected.\n");
                break;
                }

            printf("What is your first name?\n");
            scanf("%s", plFirst);
           
            printf("What is your last name?\n");
            scanf("%s", plLast);

            Name(plFirst, plLast);

            printf("What year were you born?\n");
            scanf("%hu", &birth_y);
            Age(birth_y);
       
   
            i++;
        }
    } while (i < 10);

    if (i == 10){
        printf("You have entered the maxmium number of people that can be on a team.");
    }

return 0;
}
