/* CS 1714 Spring 2022 Programming Recitation 1 */
// Jakob Symchych (nrz473)
// Create a program that allows a user to input an entire little league team. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum PHONETYPE {
  home,
  work,
  cell
}
contact;
enum RELATIONSHIP {
  mother,
  father,
  grandmother,
  grandfather,
  other
}
guardian;

void Age(unsigned short birth_y) {
  unsigned short currYear = 2022;
  unsigned short checkedYear;
  checkedYear = (currYear - birth_y);

  if (checkedYear < 9 || checkedYear > 12) {
    printf("Sorry. You are not between the age of 9 and 12.\n\n");
  } else {
    printf("You are old enough to play!\n\n");

  }

}

int main() {
  //represent 10, and their players first name
  char p0f[32], p1f[32], p2f[32], p3f[32], p4f[32], p5f[32], p6f[32], p7f[32], p8f[32], p9f[32];
  //10 players last name
  char p0l[32], p1l[32], p2l[32], p3l[32], p4l[32], p5l[32], p6l[32], p7l[32], p8l[32], p9l[32];
  //10 players street number
  char p0snum[64], p1snum[64], p2snum[64], p3snum[64], p4snum[64], p5snum[64], p6snum[64], p7snum[64], p8snum[64], p9snum[64];
  //10 players street name
  char p0sname[64], p1sname[64], p2sname[64], p3sname[64], p4sname[64], p5sname[64], p6sname[64], p7sname[64], p8sname[64], p9sname[64];
  //10 players city
  char p0c[64], p1c[64], p2c[64], p3c[64], p4c[64], p5c[64], p6c[64], p7c[64], p8c[64], p9c[64];
  //10 playesr year of birth
  unsigned short p0y, p1y, p2y, p3y, p4y, p5y, p6y, p7y, p8y, p9y;
  //10 player guardian first name
  char p0gf[64], p1gf[64], p2gf[64], p3gf[64], p4gf[64], p5gf[64], p6gf[64], p7gf[64], p8gf[64], p9gf[64];
  //10 player guardian last name
  char p0gl[64], p1gl[64], p2gl[64], p3gl[64], p4gl[64], p5gl[64], p6gl[64], p7gl[64], p8gl[64], p9gl[64];
  //10 player guardian phone num
  char p0gphone[32], p1gphone[32], p2gphone[32], p3gphone[32], p4gphone[32], p5gphone[32], p6gphone[32], p7gphone[32], p8gphone[32], p9gphone[32];
  int i = 0; //using for iterations
  int choice, choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9, choice10; //handles user choice

  do //outer DO loop
  {
    /* printf("\nEnter '1' to add players to the roster, or enter '2' to quit.\n");
        scanf(" %d", & choice);
        if (choice == 2) {
            printf("You have quit the program.\n");
            break;
        } */

    do {
      switch (i) {

      case 0: //player 0
        printf("--- Little League Player Roster ---\n\n");
        printf("What is your first name?\n"); //first name
        scanf("%s", p0f);

        printf("What is your last name?\n"); //last name
        scanf("%s", p0l);

        printf("What is your parent/guardians first name?\n"); //guardian first name
        scanf("%s", p0gf);

        printf("What is your parent/guardians last name?\n"); //guardian last name
        scanf("%s", p0gl);

        printf("Press the digit that corresponds with your parent/guardian:\n\n");
        printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
        scanf("%u", & guardian);

        switch (guardian) {
        case 0:
          printf("Mother was selected.\n\n");
          break;

        case 1:
          printf("Father was selected.\n\n");
          break;

        case 2:
          printf("Grandmother was selected.\n\n");
          break;

        case 3:
          printf("Grandfather was selected.\n\n");
          break;

        case 4:
          printf("Other was selected.\n\n");
          break;
        }

        printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
        scanf("%s", p0gphone);

        printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
        printf("Home: 0\nWork: 1\nCell: 2\n\n");
        scanf("%u", & contact);
        switch (contact) {
        case 0:
          printf("Home was selected.\n\n");
          break;

        case 1:
          printf("Work was selected.\n\n");
          break;

        case 2:
          printf("Cell was selected.\n\n");
          break;
        }

        printf("What is the name of your city?\n"); //city
        scanf(" %[^\n]", p0c);

        printf("What is your street number?\n"); //street num
        scanf(" %[^\n]", p0snum);

        printf("What is your street name?\n"); //street name
        scanf(" %[^\n]", p0sname);

        printf("What year were you born?\n"); //year
        scanf("%hu", & p0y);
        Age(p0y);
        ++i;

      case 1:
        printf("Continue adding players? Press '1'. To quit press '2'");
        scanf(" %d", & choice1);
        if (choice1 == 2) {
          i += 10;
          printf("You have quit the program.\n");
          break;
        } else if (choice1 == 1) { //chaging if to while
          printf("What is your first name?\n"); //first name
          scanf("%s", p1f);

          printf("What is your last name?\n"); //last name
          scanf("%s", p1l);

          printf("What is your parent/guardians first name?\n"); //guardian first name
          scanf("%s", p1gf);

          printf("What is your parent/guardians last name?\n"); //guardian last name
          scanf("%s", p1gl);

          printf("Press the digit that corresponds with your parent/guardian:\n\n");
          printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
          scanf("%u", & guardian);

          switch (guardian) {
          case 0:
            printf("Mother was selected.\n\n");
            break;

          case 1:
            printf("Father was selected.\n\n");
            break;

          case 2:
            printf("Grandmother was selected.\n\n");
            break;

          case 3:
            printf("Grandfather was selected.\n\n");
            break;

          case 4:
            printf("Other was selected.\n\n");
            break;
          }

          printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
          scanf("%s", p1gphone);

          printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
          printf("Home: 0\nWork: 1\nCell: 2\n\n");
          scanf("%u", & contact);
          switch (contact) {
          case 0:
            printf("Home was selected.\n\n");
            break;

          case 1:
            printf("Work was selected.\n\n");
            break;

          case 2:
            printf("Cell was selected.\n\n");
            break;
          }

          printf("What is the name of your city?\n"); //city
          scanf(" %[^\n]", p1c);

          printf("What is your street number?\n"); //street num
          scanf(" %[^\n]", p1snum);

          printf("What is your street name?\n"); //street name
          scanf(" %[^\n]", p1sname);

          printf("What year were you born?\n"); //year
          scanf("%hu", & p1y);
          Age(p1y);
          ++i;
        }
        case 2:
          printf("Continue adding players? Press '1'. To quit press '2'");
          scanf(" %d", & choice2);
          if (choice2 == 2) {
            i += 10;
            printf("You have quit the program.\n");
            break;
          } else if (choice2 == 1) {
            printf("What is your first name?\n"); //first name
            scanf("%s", p2f);

            printf("What is your last name?\n"); //last name
            scanf("%s", p2l);

            printf("What is your parent/guardians first name?\n"); //guardian first name
            scanf("%s", p2gf);

            printf("What is your parent/guardians last name?\n"); //guardian last name
            scanf("%s", p2gl);

            printf("Press the digit that corresponds with your parent/guardian:\n\n");
            printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
            scanf("%u", & guardian);

            switch (guardian) {
            case 0:
              printf("Mother was selected.\n\n");
              break;

            case 1:
              printf("Father was selected.\n\n");
              break;

            case 2:
              printf("Grandmother was selected.\n\n");
              break;

            case 3:
              printf("Grandfather was selected.\n\n");
              break;

            case 4:
              printf("Other was selected.\n\n");
              break;
            }

            printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
            scanf("%s", p2gphone);

            printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
            printf("Home: 0\nWork: 1\nCell: 2\n\n");
            scanf("%u", & contact);
            switch (contact) {
            case 0:
              printf("Home was selected.\n\n");
              break;

            case 1:
              printf("Work was selected.\n\n");
              break;

            case 2:
              printf("Cell was selected.\n\n");
              break;
            }

            printf("What is the name of your city?\n"); //city
            scanf(" %[^\n]", p2c);

            printf("What is your street number?\n"); //street num
            scanf(" %[^\n]", p2snum);

            printf("What is your street name?\n"); //street name
            scanf(" %[^\n]", p2sname);

            printf("What year were you born?\n"); //year
            scanf("%hu", & p2y);
            Age(p2y);
            ++i;
          }

          case 3:
            printf("Continue adding players? Press '1'. To quit press '2'");
            scanf(" %d", & choice3);
            if (choice3 == 2) {
              i += 10;
              printf("You have quit the program.\n");
              break;
            } else if (choice3 == 1) {
              printf("What is your first name?\n"); //first name
              scanf("%s", p3f);

              printf("What is your last name?\n"); //last name
              scanf("%s", p3l);

              printf("What is your parent/guardians first name?\n"); //guardian first name
              scanf("%s", p3gf);

              printf("What is your parent/guardians last name?\n"); //guardian last name
              scanf("%s", p3gl);

              printf("Press the digit that corresponds with your parent/guardian:\n\n");
              printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
              scanf("%u", & guardian);

              switch (guardian) {
              case 0:
                printf("Mother was selected.\n\n");
                break;

              case 1:
                printf("Father was selected.\n\n");
                break;

              case 2:
                printf("Grandmother was selected.\n\n");
                break;

              case 3:
                printf("Grandfather was selected.\n\n");
                break;

              case 4:
                printf("Other was selected.\n\n");
                break;
              }

              printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
              scanf("%s", p3gphone);

              printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
              printf("Home: 0\nWork: 1\nCell: 2\n\n");
              scanf("%u", & contact);
              switch (contact) {
              case 0:
                printf("Home was selected.\n\n");
                break;

              case 1:
                printf("Work was selected.\n\n");
                break;

              case 2:
                printf("Cell was selected.\n\n");
                break;
              }

              printf("What is the name of your city?\n"); //city
              scanf(" %[^\n]", p3c);

              printf("What is your street number?\n"); //street num
              scanf(" %[^\n]", p3snum);

              printf("What is your street name?\n"); //street name
              scanf(" %[^\n]", p3sname);

              printf("What year were you born?\n"); //year
              scanf("%hu", & p3y);
              Age(p3y);
              ++i;
            }
            case 4:
              printf("Continue adding players? Press '1'. To quit pres '2'\n");
              scanf(" %d", & choice4);
              if (choice4 == 2) {
                i += 10;
                printf("You have quit the program.\n");
                break;
              } else if (choice4 == 1) {
                printf("What is your first name?\n"); //first name
                scanf("%s", p4f);

                printf("What is your last name?\n"); //last name
                scanf("%s", p4l);

                printf("What is your parent/guardians first name?\n"); //guardian first name
                scanf("%s", p4gf);

                printf("What is your parent/guardians last name?\n"); //guardian last name
                scanf("%s", p4gl);

                printf("Press the digit that corresponds with your parent/guardian:\n\n");
                printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                scanf("%u", & guardian);

                switch (guardian) {
                case 0:
                  printf("Mother was selected.\n\n");
                  break;

                case 1:
                  printf("Father was selected.\n\n");
                  break;

                case 2:
                  printf("Grandmother was selected.\n\n");
                  break;

                case 3:
                  printf("Grandfather was selected.\n\n");
                  break;

                case 4:
                  printf("Other was selected.\n\n");
                  break;
                }

                printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                scanf("%s", p4gphone);

                printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                printf("Home: 0\nWork: 1\nCell: 2\n\n");
                scanf("%u", & contact);
                switch (contact) {
                case 0:
                  printf("Home was selected.\n\n");
                  break;

                case 1:
                  printf("Work was selected.\n\n");
                  break;

                case 2:
                  printf("Cell was selected.\n\n");
                  break;
                }

                printf("What is the name of your city?\n"); //city
                scanf(" %[^\n]", p4c);

                printf("What is your street number?\n"); //street num
                scanf(" %[^\n]", p4snum);

                printf("What is your street name?\n"); //street name
                scanf(" %[^\n]", p4sname);

                printf("What year were you born?\n"); //year
                scanf("%hu", & p4y);
                Age(p4y);
                ++i;
              }
              case 5:
                printf("Continue adding players? Press '1'. To quit press '2'\n");
                scanf(" %d", & choice5);
                if (choice5 == 2) {
                  i += 10;
                  printf("You have quit the program.\n");
                  break;
                } else if (choice5 == 1) {
                  printf("What is your first name?\n"); //first name
                  scanf("%s", p5f);

                  printf("What is your last name?\n"); //last name
                  scanf("%s", p5l);

                  printf("What is your parent/guardians first name?\n"); //guardian first name
                  scanf("%s", p5gf);

                  printf("What is your parent/guardians last name?\n"); //guardian last name
                  scanf("%s", p5gl);

                  printf("Press the digit that corresponds with your parent/guardian:\n\n");
                  printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                  scanf("%u", & guardian);

                  switch (guardian) {
                  case 0:
                    printf("Mother was selected.\n\n");
                    break;

                  case 1:
                    printf("Father was selected.\n\n");
                    break;

                  case 2:
                    printf("Grandmother was selected.\n\n");
                    break;

                  case 3:
                    printf("Grandfather was selected.\n\n");
                    break;

                  case 4:
                    printf("Other was selected.\n\n");
                    break;
                  }

                  printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                  scanf("%s", p5gphone);

                  printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                  printf("Home: 0\nWork: 1\nCell: 2\n\n");
                  scanf("%u", & contact);
                  switch (contact) {
                  case 0:
                    printf("Home was selected.\n\n");
                    break;

                  case 1:
                    printf("Work was selected.\n\n");
                    break;

                  case 2:
                    printf("Cell was selected.\n\n");
                    break;
                  }

                  printf("What is the name of your city?\n"); //city
                  scanf(" %[^\n]", p5c);

                  printf("What is your street number?\n"); //street num
                  scanf(" %[^\n]", p5snum);

                  printf("What is your street name?\n"); //street name
                  scanf(" %[^\n]", p5sname);

                  printf("What year were you born?\n"); //year
                  scanf("%hu", & p5y);
                  Age(p5y);
                  ++i;
                }
                case 6:
                  printf("Continue adding players? Press '1'. To quit press '2'\n");
                  scanf(" %d", & choice6);
                  if (choice6 == 2) {
                    i += 10;
                    printf("You have quit the program.\n");
                    break;
                  } else if (choice6 == 1) {
                    printf("What is your first name?\n"); //first name
                    scanf("%s", p6f);

                    printf("What is your last name?\n"); //last name
                    scanf("%s", p6l);

                    printf("What is your parent/guardians first name?\n"); //guardian first name
                    scanf("%s", p6gf);

                    printf("What is your parent/guardians last name?\n"); //guardian last name
                    scanf("%s", p6gl);

                    printf("Press the digit that corresponds with your parent/guardian:\n\n");
                    printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                    scanf("%u", & guardian);

                    switch (guardian) {
                    case 0:
                      printf("Mother was selected.\n\n");
                      break;

                    case 1:
                      printf("Father was selected.\n\n");
                      break;

                    case 2:
                      printf("Grandmother was selected.\n\n");
                      break;

                    case 3:
                      printf("Grandfather was selected.\n\n");
                      break;

                    case 4:
                      printf("Other was selected.\n\n");
                      break;
                    }

                    printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                    scanf("%s", p6gphone);

                    printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                    printf("Home: 0\nWork: 1\nCell: 2\n\n");
                    scanf("%u", & contact);
                    switch (contact) {
                    case 0:
                      printf("Home was selected.\n\n");
                      break;

                    case 1:
                      printf("Work was selected.\n\n");
                      break;

                    case 2:
                      printf("Cell was selected.\n\n");
                      break;
                    }

                    printf("What is the name of your city?\n"); //city
                    scanf(" %[^\n]", p6c);

                    printf("What is your street number?\n"); //street num
                    scanf(" %[^\n]", p6snum);

                    printf("What is your street name?\n"); //street name
                    scanf(" %[^\n]", p6sname);

                    printf("What year were you born?\n"); //year
                    scanf("%hu", & p6y);
                    Age(p6y);
                    ++i;
                  }
                  case 7:
                    printf("Continue adding players? Press '1'. To quit press '2'\n");
                    scanf(" %d", & choice7);
                    if (choice7 == 2) {
                      i += 10;
                      printf("You have quit the program.\n");
                      break;
                    } else if (choice7 == 1) {
                      printf("What is your first name?\n"); //first name
                      scanf("%s", p7f);

                      printf("What is your last name?\n"); //last name
                      scanf("%s", p7l);

                      printf("What is your parent/guardians first name?\n"); //guardian first name
                      scanf("%s", p7gf);

                      printf("What is your parent/guardians last name?\n"); //guardian last name
                      scanf("%s", p7gl);

                      printf("Press the digit that corresponds with your parent/guardian:\n\n");
                      printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                      scanf("%u", & guardian);

                      switch (guardian) {
                      case 0:
                        printf("Mother was selected.\n\n");
                        break;

                      case 1:
                        printf("Father was selected.\n\n");
                        break;

                      case 2:
                        printf("Grandmother was selected.\n\n");
                        break;

                      case 3:
                        printf("Grandfather was selected.\n\n");
                        break;

                      case 4:
                        printf("Other was selected.\n\n");
                        break;
                      }

                      printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                      scanf("%s", p7gphone);

                      printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                      printf("Home: 0\nWork: 1\nCell: 2\n\n");
                      scanf("%u", & contact);
                      switch (contact) {
                      case 0:
                        printf("Home was selected.\n\n");
                        break;

                      case 1:
                        printf("Work was selected.\n\n");
                        break;

                      case 2:
                        printf("Cell was selected.\n\n");
                        break;
                      }

                      printf("What is the name of your city?\n"); //city
                      scanf(" %[^\n]", p7c);

                      printf("What is your street number?\n"); //street num
                      scanf(" %[^\n]", p7snum);

                      printf("What is your street name?\n"); //street name
                      scanf(" %[^\n]", p7sname);

                      printf("What year were you born?\n"); //year
                      scanf("%hu", & p7y);
                      Age(p7y);
                      ++i;
                    }
                    case 8:
                      printf("Continue adding players? Press '1'. To quit press '2'\n");
                      scanf(" %d", & choice8);
                      if (choice8 == 2) {
                        i += 10;
                        printf("You have quit the program.\n");
                        break;
                      } else if (choice8 == 1) {
                        printf("What is your first name?\n"); //first name
                        scanf("%s", p8f);

                        printf("What is your last name?\n"); //last name
                        scanf("%s", p8l);

                        printf("What is your parent/guardians first name?\n"); //guardian first name
                        scanf("%s", p8gf);

                        printf("What is your parent/guardians last name?\n"); //guardian last name
                        scanf("%s", p8gl);

                        printf("Press the digit that corresponds with your parent/guardian:\n\n");
                        printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                        scanf("%u", & guardian);

                        switch (guardian) {
                        case 0:
                          printf("Mother was selected.\n\n");
                          break;

                        case 1:
                          printf("Father was selected.\n\n");
                          break;

                        case 2:
                          printf("Grandmother was selected.\n\n");
                          break;

                        case 3:
                          printf("Grandfather was selected.\n\n");
                          break;

                        case 4:
                          printf("Other was selected.\n\n");
                          break;
                        }

                        printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                        scanf("%s", p8gphone);

                        printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                        printf("Home: 0\nWork: 1\nCell: 2\n\n");
                        scanf("%u", & contact);
                        switch (contact) {
                        case 0:
                          printf("Home was selected.\n\n");
                          break;

                        case 1:
                          printf("Work was selected.\n\n");
                          break;

                        case 2:
                          printf("Cell was selected.\n\n");
                          break;
                        }

                        printf("What is the name of your city?\n"); //city
                        scanf(" %[^\n]", p8c);

                        printf("What is your street number?\n"); //street num
                        scanf(" %[^\n]", p8snum);

                        printf("What is your street name?\n"); //street name
                        scanf(" %[^\n]", p8sname);

                        printf("What year were you born?\n"); //year
                        scanf("%hu", & p8y);
                        Age(p8y);
                        ++i;
                      }
                      case 9:
                        printf("Continue adding players? Press '1'. To quit press '2'\n");
                        scanf(" %d", & choice9);
                        if (choice9 == 2) {
                          i += 10;
                          printf("You have quit the program.\n");
                          break;
                        } else if (choice9 == 1) {
                          printf("What is your first name?\n"); //first name
                          scanf("%s", p9f);

                          printf("What is your last name?\n"); //last name
                          scanf("%s", p9l);

                          printf("What is your parent/guardians first name?\n"); //guardian first name
                          scanf("%s", p9gf);

                          printf("What is your parent/guardians last name?\n"); //guardian last name
                          scanf("%s", p9gl);

                          printf("Press the digit that corresponds with your parent/guardian:\n\n");
                          printf("Mother: 0\nFather: 1\nGrandmother: 2\nGrandfather: 3\nOther: 4\n\n");
                          scanf("%u", & guardian);

                          switch (guardian) {
                          case 0:
                            printf("Mother was selected.\n\n");
                            break;

                          case 1:
                            printf("Father was selected.\n\n");
                            break;

                          case 2:
                            printf("Grandmother was selected.\n\n");
                            break;

                          case 3:
                            printf("Grandfather was selected.\n\n");
                            break;

                          case 4:
                            printf("Other was selected.\n\n");
                            break;
                          }

                          printf("What is parent/guardian phone number? ('5555555555')\n"); //guardian phone num
                          scanf("%s", p9gphone);

                          printf("\nPress the digit that correpsonds with your parent/guardian phone number type.\n");
                          printf("Home: 0\nWork: 1\nCell: 2\n\n");
                          scanf("%u", & contact);
                          switch (contact) {
                          case 0:
                            printf("Home was selected.\n\n");
                            break;

                          case 1:
                            printf("Work was selected.\n\n");
                            break;

                          case 2:
                            printf("Cell was selected.\n\n");
                            break;
                          }

                          printf("What is the name of your city?\n"); //city
                          scanf(" %[^\n]", p9c);

                          printf("What is your street number?\n"); //street num
                          scanf(" %[^\n]", p9snum);

                          printf("What is your street name?\n"); //street name
                          scanf(" %[^\n]", p9sname);

                          printf("What year were you born?\n"); //year
                          scanf("%hu", & p9y);
                          Age(p9y);
                          ++i;
                        }
                        case 10: // Max player case
                          printf("Continue adding players? Press '1'. To quit press '2'\n");
                          scanf(" %d", & choice10);
                          if (choice10 == 2) {
                            i += 10;
                            printf("You have quit the program.\n");
                            break;
                          } else if (choice10 == 1) {
                            if (i == 11) {
                              printf("Maximum players for a team has been reached.\nProgram will quit now.");
                              break;
                            }
                          }
      }

    } while (i < 10); //change this to a boolean, and when 2 is pressed we switch false

  } while (i < 10);

  return 0;
}
