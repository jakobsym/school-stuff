/* CS-1714 Spring 2022 Programming Recitation 2 */
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
    } else {
        printf("You are old enough to play!\n\n");

    }
}

int CheckString(char buffer[1024], int size) {
    int buf_len = (int) strlen(buffer);

    //NAME CHECK
    if (size == MAX_NAME_LEN) {
        if (buf_len <= size) {
            return 0;
        } else {
            printf("\n-- ERROR -- \n");
            printf("Sorry your name is too long. It cannot exceed 32 characters.\n");
            return (buf_len - size);
        }
    }
    //CITY CHECK
    if (size == MAX_CITY_LEN) {
        if (buf_len <= size) {
            return 0;
        } else {
            printf("\n-- ERROR -- \n");
            printf("Sorry your city name is too long. It cannot exceed 64 characters.\n");
            return (buf_len - size);
        }
    }

    return -1; //if conditionals are not satisifed output -1
}

void myFunc(char ** pfName, char ** plName, char ** pCity, char ** streetName, char ** streetNum, unsigned short * BirthYear, char ** gfname, char ** glname, char ** gphonenum){
    int i, j;
    printf("\n-- Players --\n");
    for (i = 0; i < 2; ++i) {
        printf("Player %d: %s %s | YoB: %hu | Residence: %s %s, %s\n", i, pfName[i], plName[i], BirthYear[i], streetNum[i], streetName[i], pCity[i]);
    }
    printf("\n-- Guardian Information --\n");
    for(j = 0; j< 2; ++j){
        printf("Player %d Guardian name: %s %s | Guardian phone number: %s\n", j, gfname[j], glname[j], gphonenum[j]);
    }

}

void myFile(char ** pfName, char ** plName, char ** pCity, char ** streetName, char ** streetNum, unsigned short * BirthYear, char ** gfname, char ** glname, char ** gphonenum) {
    FILE *fptr;
    int i, j;
    fptr = fopen("roster.txt", "w");
    if(fptr == NULL) {
        printf("Error creating file.\n");
    }

    fprintf(fptr, "-- Players --\n");
    for (i = 0; i < 2; ++i) {
        fprintf(fptr, "Player %d: %s %s | YoB: %hu | Residence: %s %s, %s\n", i, pfName[i], plName[i], BirthYear[i], streetNum[i], streetName[i], pCity[i]);
    }
    fprintf(fptr, "\n-- Guardian Information --\n");
    for(j = 0; j< 2; ++j){
        fprintf(fptr, "Player %d Guardian name: %s %s | Guardian phone number: %s\n", j, gfname[j], glname[j], gphonenum[j]);
    }
    fclose(fptr);

}



int main() {
    int i, j, k=0;
    char buffer[BUFFER_SIZE], roster;
    //First name
    char ** PlayerFirstName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        PlayerFirstName[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //Last name
    char ** PlayerLastName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        PlayerLastName[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //Street name
    char ** StreetName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        StreetName[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //Street number
    char ** StreetNumber = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        StreetNumber[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //City name
    char ** CityName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * )); //10 players cities, upto 64 characters e/a
    for (j = 0; j < MAX_PLAYERS; ++j) {
        CityName[j] = (char * ) malloc(MAX_CITY_LEN * sizeof(char));
    }
    //Year of birth (BirthYear[10])
    unsigned short * BirthYear = (unsigned short * ) malloc(MAX_PLAYERS * sizeof(unsigned short));
    //Guardian first name
    char ** GuardianfName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        GuardianfName[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //Guardian last name
    char ** GuardianlName = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        GuardianlName[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    //Guardian phone number
    char ** GuardianPhone = (char ** ) malloc(MAX_PLAYERS * sizeof(char * ));
    for (j = 0; j < MAX_PLAYERS; ++j) {
        GuardianPhone[j] = (char * ) malloc(MAX_NAME_LEN * sizeof(char));
    }
    int nameTest, cityTest;
    char choice[MAX_PLAYERS];

    printf("\n --- Little League Roster --- \n");
    printf("- Maximum of 10 players per roster\n- Players must be between the age 9 - 12\n");

    for (i = 0; i < 2; ++i) {
        printf("\nAdding players? 'y' for yes / 'n' for no\n");
        scanf(" %c", & choice[i]);
        enum RELATIONSHIP {
            mother,
            father,
            grandmother,
            grandfather,
            other,
        }
        guardian[i];

        enum PHONETYPE {
            home,
            work,
            cell
        }
        contact[i];

        if (choice[i] == 'y' || choice[i] == 'Y') {
            // player first name
            printf("What is your first name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);

            if (nameTest != 0) {
                --i;
                continue;
            }
            PlayerFirstName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(PlayerFirstName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // player last name
            printf("What is your last name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);
            if (nameTest != 0) {
                --i;
                continue;
            }
            PlayerLastName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(PlayerLastName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // Steet name
            printf("What is your street name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);
            if (nameTest != 0) {
                --i;
                continue;
            }
            StreetName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(StreetName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // street number
            printf("What is your street number?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);
            if (nameTest != 0) {
                --i;
                continue;
            }
            StreetNumber[i] = (char * ) malloc(strlen((buffer) + 1) * sizeof(char));
            strcpy(StreetNumber[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // city name
            printf("What is your city name?\n");
            scanf(" %[^\n]", buffer);
            cityTest = CheckString(buffer, MAX_CITY_LEN);

            if (cityTest != 0) {
                --i;
                continue;
            }
            CityName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(CityName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // birth year
            printf("What year was player born?\n");
            scanf("%hu", & BirthYear[i]);
            Age(BirthYear[i]);

            // Guardian first name
            printf("What is your parent/guardians first name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);

            if (nameTest != 0) {
                --i;
                continue;
            }
            GuardianfName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(GuardianfName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            // Guardian Last Name
            printf("What is your parent/guardian last name?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);

            if (nameTest != 0) {
                --i;
                continue;
            }
            GuardianlName[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(GuardianlName[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

             //Parent/Guardian Type
            printf("Press the digit that corresponds with your parent/guardian:\n\n");
            printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
            scanf("%u", &guardian[i]);

            // Guardian phone number
            printf("What is your parent/guardian phone number?\n");
            scanf(" %[^\n]", buffer);
            nameTest = CheckString(buffer, MAX_NAME_LEN);
            if (nameTest != 0) {
                --i;
                continue;
            }
            GuardianPhone[i] = (char * ) malloc((strlen(buffer) + 1) * sizeof(char));
            strcpy(GuardianPhone[i], buffer);
            memset(buffer, 0, BUFFER_SIZE);

            printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
            printf("Home: 0\nWork: 1\nCell: 2\n\n");
            scanf("%u", &contact[i]);
            ++k;

            if(k == 2) {
                printf("Would you like to save the roster you created?\nPress 'Y' or 'N'.\n");
                scanf(" %c", &roster);
                if(roster == 'y' || roster == 'Y') {
                    printf("Saving roster...\n");
                    myFile(PlayerFirstName, PlayerLastName, CityName, StreetName, StreetNumber, BirthYear, GuardianfName, GuardianlName, GuardianPhone);
                }
                else if(roster == 'n' || roster == 'N'){
                    printf("Roster will not be saved. Displaying roster to the screen...");
                    myFunc(PlayerFirstName, PlayerLastName, CityName, StreetName, StreetNumber, BirthYear, GuardianfName, GuardianlName, GuardianPhone);
                }
            }

        }

        else if (choice[i] == 'n' || choice[i] == 'N') {
            printf("Would you like to save the roster you created? Press 'Y' or 'N'.\n");
            scanf(" %c", &roster);
            if(roster == 'y' || roster == 'Y'){
                printf("Saving roster...\n");
                myFile(PlayerFirstName, PlayerLastName, CityName, StreetName, StreetNumber, BirthYear, GuardianfName, GuardianlName, GuardianPhone);
                break;
            }
            else if(roster == 'n' || roster == 'N'){
                printf("Roster will not be saved. Displaying roster to the screen...\n");
                myFunc(PlayerFirstName, PlayerLastName, CityName, StreetName, StreetNumber, BirthYear, GuardianfName, GuardianlName, GuardianPhone);
                break;
            }
            }
        }
    
    
    /* freeing memory from heap */

    // First name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(PlayerFirstName[i]);
    }
    free(PlayerFirstName);
    // street number
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(StreetNumber[i]);
    }
    free(StreetNumber);

    // street name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(StreetName[i]);
    }
    free(StreetName);

    // City name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(CityName[i]);
    }
    free(CityName);

    // Last name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(PlayerLastName[i]);
    }
    free(PlayerLastName);

    // Guardian first name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(GuardianfName[i]);
    }
    free(GuardianfName);

    // guardian last name
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(GuardianlName[i]);
    }
    free(GuardianlName);

    // Guardian Phone
    for (i = 0; i < MAX_PLAYERS; ++i) {
        free(GuardianPhone[i]);
    }
    free(GuardianPhone);
    free(BirthYear);

    return 0;
}