#ifndef _PLAYER_H
#define _PLAYER_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

int nameTest, cityTest;
char buffer[BUFFER_SIZE];

struct _PLAYER {
    char *firstName; //player firstname
    size_t firstNamelen;
    unsigned int birthYear; //player YoB
    char *cityName; //player city name
    size_t cityNamelen;
};
typedef struct _PLAYER Player;

void playerName(Player *p);
void cityName(Player *p);
void Age(Player *p);
void showRoster(Player *team, int teamSize, FILE* fOut);
void loadRoster(Player *team, int *teamSize, FILE* fPtr);

#endif /* _PLAYER_H */
