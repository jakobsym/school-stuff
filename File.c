#include <string.h>
#include <ctype.h>
#include "Player.h"

#define ROSTER_FILE "roster.txt"

int main(){
    int j,count,i = 0;
    char choice[BUFFER_SIZE];
    Player roster[MAX_PLAYERS];
    printf("\n --- Little League Roster --- \n");
    printf(" - Only 10 players per roster.\n - Players must be between the age 9 - 12.\n");

    printf("\nWould you like to load a previously created roster? 'Y' or 'N'\n");
    scanf(" %[^\n]s", buffer);
    if(toupper(buffer[0]) == 'Y'){
        FILE* teamList = fopen(ROSTER_FILE, "r");
        if(teamList != NULL) {
            Player team[MAX_PLAYERS];
            fscanf(teamList, "%d", &count);
            for(;i < count; ++i){
                fscanf(teamList, "%s %s %u", team[i].firstName, team[i].cityName, &team[i].birthYear);
            }
            fclose(teamList);
        }
        else {
            printf("The file \"%s\" is not available.\n", ROSTER_FILE);
        }
    } 

    for(j= 0; j < MAX_PLAYERS; ++j){
        printf("\nWould you like to add a player? 'Y' or 'N'\n");
        scanf(" %[^\n]", &buffer[j]);

        if(toupper(buffer[j])== 'Y'){
            playerName(&roster[count]);
            cityName(&roster[count]);
            Age(&roster[count]);
            ++count;
        }
        else {
            break;
        }
    }
   
    if(count == MAX_PLAYERS){
        printf("Maxmimum number of players per roster has been reached.\n");
    }

    showRoster(roster, count, stdout);

    do{
        printf("\nWould you like to save the roster? 'Y' or 'N'\n");
        scanf("%s", buffer);
        if((toupper(buffer[0]) == 'Y') || (toupper(buffer[0]) == 'N')) {
                break;
            }
            else{
                printf("Accepting \"Y\" or \"N\" only.\n");
            }


    }while(1);

    if(toupper(buffer[0]) == 'Y'){
        FILE* teamList = fopen(ROSTER_FILE, "w");
        if(teamList != NULL){
            showRoster(roster, count, teamList);
            fclose(teamList);
        }
        else {
            printf("Failed to open file to write into.\n");
        }
    }

    return 0;
}