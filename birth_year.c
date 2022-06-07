#include <stdio.h>

int main() {
int currYear = 2022;
int birthYear, checkedYear;


printf("What year were you born?\n");
scanf("%d", &birthYear);
checkedYear = (currYear - birthYear);

if (checkedYear < 9 || checkedYear > 12){
    printf("Sorry you are not elibble to play.\n");
    printf("%d", checkedYear);
}
else{
    printf("You are old enough to play.\n");
    printf("%d", checkedYear);
}
    
    return 0;
}