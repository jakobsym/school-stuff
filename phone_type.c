#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>


int main(){

    enum PhoneType {home, work, cell}; //home = 0
    enum PhoneType contact;

    
    printf("\nPress the digit that correpsonds with your phone number type.\n");
    printf("Home: 0\nWork: 1\nCell: 2\n\n");
    scanf("%u", &contact);

    switch(contact){
        case 0:
        printf("Home was selected.");
        break;

        case 1:
        printf("Work was selected.");
        break;

        case 2:
        printf("Cell was selected.");
        break;

        //add default case

    }
    return 0;
    
    }