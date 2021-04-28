#include "gamePVP.h"
#include "out.h"

int gamePVP(char *player_one, char *player_two) {
  int i = 2;
  nickname_out(player_one, i);
  i++;
  nickname_out(player_two, i);
  int num[2];
  num[0] = 100;
  // stick
  num[1] = 0;
  // winner
  num[1] = maingame(num);
  return num[1];
}

int maingame(int *num) {
  int choise = 0;
  while (num[0] != 0) {
    game(num[0]);
    printf("Player #1, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[0]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }
    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer #1, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[0]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num -= choise;
    num[1] = 2;

    game(num[0]);
    printf("Player #2, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[0]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }
    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer #2, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[0]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num -= choise;
    num[1] = 1;
  }
  int winner = num[1];
  return winner;
}
