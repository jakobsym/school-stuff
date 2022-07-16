#include "Player.h"
#include "../assign9/Check.h" 
//PLAYER NAME
void playerName(Player *p){
    do{
        printf("\nWhat is player name? \n");
        scanf(" %[^\n]s", buffer);
        getchar();
        nameTest = CheckString(buffer, MAX_NAME_LEN);
    }while(0 != nameTest);

    size_t bufl = strlen(buffer) +1;
    p->firstName = (char*)malloc(bufl * sizeof(char));
    strcpy(p->firstName, buffer);
    p->firstNamelen = bufl;
    memset(buffer, '\0', BUFFER_SIZE);
}
//CITY
void cityName(Player *p){
    do{
        printf("What is player city name? \n");
        scanf(" %[^\n]s", buffer);
        getchar();
        cityTest = CheckString(buffer, MAX_CITY_LEN);
    }while(0 != cityTest);
    size_t bufl = strlen(buffer)+1;
    p->cityName = (char*)malloc(bufl * sizeof(char));
    strcpy(p->cityName, buffer);
    p->cityNamelen = bufl;
    memset(buffer, '\0', BUFFER_SIZE);

}

void Age(Player *p){
    unsigned short val = 0;
    unsigned short checkedYear;
    unsigned short currYear = 2022;
    unsigned short minyear = 9, maxyear = 12;
    do{
        printf("What is players birth year? \n");
        scanf("%hu", &val);
        checkedYear = (currYear - val);
        getchar();

        if (checkedYear < minyear || checkedYear > maxyear) {
            printf("Sorry. You must be between the ages of 9 and 12.\n\n");
        } 
        else {
            printf("You are old enough to play!\n\n");
            break;
        }

    }while(1);
    p->birthYear = val;

}

void showRoster(Player *team, int teamSize, FILE* fOut){
    int i = 0;
    fprintf(fOut, "\nTotal number of players on roster: %d\n", teamSize);
    for(;i < teamSize; ++i){
        fprintf(fOut, "\nPlayer %d Information:\nName: %s | City: %s | YoB: %u\n", i, team[i].firstName, team[i].cityName, team[i].birthYear);

    }
}

void loadRoster(Player *team, int *teamSize, FILE* fPtr) {
    int i = 0;
    fscanf(fPtr, "%d", teamSize);
    do{
        fscanf(fPtr, "%s", team->firstName);
        fscanf(fPtr, "%s", team->cityName);
        fscanf(fPtr, "%u", &team->birthYear);

    }while(!feof(fPtr));
}