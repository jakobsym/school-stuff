#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>


int main(){
   /*  char plFirst[32], plLast[32]; //name variables
    printf("--- Baseball Team Registration ---\n");
    printf("\n");
    printf("Enter your first name: \n");
    scanf("%s", plFirst);
    printf("Enter your last name: \n");
    scanf("%s", plLast); */

    enum Relationship {mother, father, grandmother, grandfather, other} guardian; 

    
    printf("Press the digit that corresponds with your caregiver:\n\n");
    printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
    scanf("%u", &guardian);
    
    switch(guardian){
        case 0:
        printf("Mother was selected.");
        break;

        case 1:
        printf("Father was selected.");
        break;

        case 2:
        printf("Grandmother was selected.");
        break;
        
        case 3:
        printf("Grandfather was selected.");
        break;

        case 4:
        printf("Other was selected.");
        break;

        //add default case
    }

    return 0;
    
    }