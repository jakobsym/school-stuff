#ifndef _TEAM_H
#define _TEAM_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_TEAMS 4
#define MIN_PLAYERS 9
#define MAX_PLAYERS 12
#define BUFFER_SIZE 1024
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64

int nameTest, cityTest;
char buffer[BUFFER_SIZE];


struct _PLAYER {
	//Team Name
	char *teamName;
	size_t teamNamelen;
	//First name
	char *firstName;
	size_t firstNamelen;
	//Last name
	char *lastName;
	size_t lastNamelen;
	//Streetname
	char *streetName;
	size_t streetNamelen;
	//Streetnum
	char *streetNum;
	size_t streetNumlen;
	//Cityname
	char *cityName;
	size_t cityNamelen;
	//Guardian First
	char* guardianFirst;
	size_t guardianFirstlen;
	//Guardian last
	char *guardianLast;
	size_t guardianLastlen;
	//Phone num
	char *phoneNum;
	size_t phoneNumlen;

	enum RELATIONSHIP {
        mother,
        father,
        grandmother,
      	grandfather,
        other,
    } guardianType;

    enum PHONETYPE {
    	home,
    	work,
    	cell,
    } contactType;

	//Birthyear
	unsigned int birthYear;

};
typedef struct _PLAYER Player;

void playerName(Team *t); //first & last name
void cityName(Team *t); //street name, num, and city name
void guardianName(Team *t); //guardian first, last, and type
void Age(Team *t); //get age
void phoneType(Team *t); //what is phone num, and phone type

#endif /* _TEAM_H */
