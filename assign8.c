/* CS-1714 Spring 2022 Assignment 8 */
// Jakob Symchych (nrz473)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

int CheckString(char buffer[1024], int size){
    int buf_len = (int)strlen(buffer);

    //NAME CHECK
    if(size == MAX_NAME_LEN) {
        if(buf_len <= size){
            return 0;
        }
        else {
            printf("\n-- ERROR -- \n");
            printf("Sorry your name is too long. It cannot exceed 32 characters.\n");
            return (buf_len - size);
        }
    }
    //CITY CHECK
    if(size == MAX_CITY_LEN){
        if(buf_len <= size){
            return 0;
        }
        else {
            printf("\n-- ERROR -- \n");
            printf("Sorry your city name is too long. It cannot exceed 64 characters.\n");
            return (buf_len - size);
        }
    }

    return -1; //if conditionals are not satisifed output -1
}

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

/* void myFunc(char **pfname, char **pcity){
    int i;
    printf("-- Players --\n");
    for(i = 0; i < MAX_PLAYERS; ++i){
        printf("Player %d name: %s\nCity: %s\n\n",i, pfname[i], pcity[i]);
    }
} */

typedef struct {
    char **firstName; //player firstname
    size_t firstNamelen;
    unsigned int birthYear; //player YoB
    char **cityName; //player city name
    size_t cityNamelen;

} Player;

int main(){
    int i, j, k;
    char choice[MAX_PLAYERS], roster;
    char buffer[BUFFER_SIZE];
    int nameTest, cityTest; //holding value of checkstring
    Player *_player = malloc(sizeof(Player)); //struct allocation

    //allocate memory for firstName
    _player->firstName = (char**)malloc(MAX_PLAYERS * sizeof(char*));
    for(i = 0; i < MAX_PLAYERS; ++i) {
        _player->firstName[i] = (char*)malloc(MAX_NAME_LEN * sizeof(char));
    }
    
    //allocate memory for cityname
    _player->cityName = (char**)malloc(MAX_PLAYERS * sizeof(char*));
    for(i = 0; i < MAX_PLAYERS; ++i){
        _player->cityName[i] = (char*)malloc(MAX_CITY_LEN * sizeof(char));
    }

    printf("\n --- Little League Roster --- \n");
    printf(" - Only 10 players per roster\n - Players must be between the age 9 - 12.\n");
    printf("\nWould you like to load a previously created roster?\n");
    scanf(" %c", &roster);

    for(j = 0; j < MAX_PLAYERS; ++j){
        printf("\nAdding players? 'y' for yes / 'n' for no\n");
        scanf(" %c", & choice[j]);

        if(choice[j] == 'y' || choice[j] == 'Y'){
            printf("\nWhat is your name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);

            if (nameTest != 0) {
                --j;
                continue;
            }
            _player->firstName[j] = (char*)malloc((strlen(buffer)+1)* sizeof(char));
            strcpy(_player->firstName[j], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            printf("What is your city name?\n");
            scanf(" %[^\n]", buffer);
            cityTest = CheckString(buffer, MAX_CITY_LEN);

            if(cityTest != 0){
                --j;
                continue;
            }
            _player->cityName[j] = (char*)malloc((strlen(buffer)+1)* sizeof(char));
            strcpy(_player->cityName[j], buffer);
            memset(buffer, 0, BUFFER_SIZE);
            ++k;

            if(k == MAX_PLAYERS){
                printf("Maximum number of players per roster have been added.\nDisplaying all current player information now.\n\n");
                break;
            }
        }
        else if (choice[j] == 'n' || choice[j] == 'N'){
            printf("You have quit the program.\n");
            break;
        }

    }
    for(j = 0; j < MAX_PLAYERS; ++j){
        free(_player->firstName[j]);
    }
    free(_player->firstName);
    for(j = 0; j < MAX_PLAYERS; ++j){
        free(_player->cityName[j]);
    }
    free(_player->cityName);
    free(_player);

    
    return 0;
}