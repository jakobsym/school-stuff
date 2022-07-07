#include <string.h>
#include <ctype.h>


#include "Player.h"

int main(){
    int count = 0;
    char choice[BUFFER_SIZE];
    Player roster[MAX_PLAYERS];
    printf("\n --- Little League Roster --- \n");
    printf(" - Only 10 players per roster.\n - Players must be between the age 9 - 12.\n");
    /* printf("\nWould you like to load a previously created roster?\n");
    scanf(" %[^\n]s", buffer); */

    
    //getchar();

    do{
        playerName(&roster[count]);
        cityName(&roster[count]);
        Age(&roster[count]);
        ++count;

        do{
            printf("Would you like to enter another player? 'Y' or 'N'\n");
            scanf(" %c", choice);
            //getchar();
            if(toupper(choice[0])== 'N' ||(toupper(choice[0])== 'Y')){
                break;
                showRoster(roster, count, stdout);
            }
        }while((toupper(choice[0]) != 'N')); //HERE 2

    }while(count != MAX_PLAYERS || (toupper(buffer[0]) == 'Y')); //HERE 1

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
        FILE* teamList = fopen("roster.txt", "w");
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
