#include "gamePVP.h"
#include "out.h"

int gamePVP(char *player_one, char *player_two) {
  nickname_out();
  printf("Nickname of the first player(no more than 15 characters): ");
  scanf("%s", player_one);
  printf("Nickname of the second player(no more than 15 characters): ");
  scanf("%s", player_two);
  printf("\n");
  int input = 0, stick = 100;
  int num[3];
  num[0] = input;
  num[1] = stick;
  int winner = 0;
  num[2] = winner;
  winner = maingame(num);
  return winner;
}

int maingame(int *num) {
  int choise = 0;
  while (num[0] != 100) {
    game(num[1]);
    printf("\n\n");

    printf("Player #1, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[1]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer #1, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 2;

    game(num[1]);
    printf("\n\n");
    printf("Player #2, enter the number: ");
    scanf("%d", &choise);

    if (choise > num[1]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer #2, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 1;
  }
  int winner = num[2];
  return winner;
}
