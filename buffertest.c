/* CS-1714 Spring 2022 Assignment 5 */
// Jakob Symchych (nrz473)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

void Age(unsigned short birth_y) {
  unsigned short currYear = 2022;
  unsigned short checkedYear;
  checkedYear = (currYear - birth_y);

  if (checkedYear < 9 || checkedYear > 12) {
    printf("Sorry. You must be between the ages of 9 and 12.\n\n");
  } 
  else {
    printf("You are old enough to play!\n\n");

  }
}

// ADD AGE FUNCTION, TEST TO ENSURE IT WORKS AFTER 
int main(){
    char buffer[BUFFER_SIZE]; //using for error trapping
    char PlayerName[MAX_PLAYERS][MAX_NAME_LEN]; //10 player names, upto 32 characters e/a
    unsigned short BirthYear[MAX_PLAYERS]; //10 players birthyears
    char CityName[MAX_PLAYERS][MAX_CITY_LEN]; //10 players cities, upto 64 characters e/a
    char choice[10]; //choice does not start until 2nd player; choice[0] == 2nd player

    printf("\n --- Little League Roster --- \n");
    printf("- Only 10 players per roster\n- Players must be between the age 9 - 12\n");   

    for(int j = 0; j < MAX_PLAYERS; j++){ //will cycle 10 times
            strcpy(buffer, "");
            printf("\nAdding players? 'y' for yes / 'n' for no\n");
            scanf(" %c", &choice[j]);

            if(j == MAX_PLAYERS){
                printf("You have entered the maximum number of players that can be on a roster.\n");
            }

            if(choice[j] == 'y' || choice[j]== 'Y'){
                //NAME USER INPUT
                printf("What is your name?\n");
                scanf(" %[^\n]", buffer);
                if(strlen(buffer) > 32){
                    printf("\n-- ERROR -- \n");
                    printf("Your name cannot exceed 32 characters. Please re-enter your name.\n");
                    scanf(" %[^\n]", buffer);
                    }
                else {
                    strcpy(PlayerName[j], buffer);
                }
                //CITY UESR INPUT
                printf("Name of your city?\n");
                scanf(" %[^\n]", buffer);
                if(strlen(buffer) > 64){
                    printf("\n-- ERROR -- \n");
                    printf("Your city name cannot exceed 64 characters. Please re-enter your city.\n");
                    scanf(" %[^\n]", buffer);
                }
                else {
                    strcpy(CityName[j], buffer);
                }
                //YEAR USER INPUT
                printf("What year were you born?\n");
                scanf("%hu", &BirthYear[j]);
                Age(BirthYear[j]);
            }
            else if(choice[j]=='n' || choice[j]=='N'){
                printf("You have quit the program.\n");
                break;
            }
        }

    return 0;
}