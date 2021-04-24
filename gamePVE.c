#include "gamePVE.h"
#include "out.h"

int gamePVE(char *player_one) {
  nickname_out(player_one);
  printf("Player's nickname(no more than 15 characters): ");
  scanf("%s", player_one);
  choise_dif();
  int choise;
  printf("1 - easy. 2-medium. 3-hard.\n");
  scanf("%d", &choise);
  int winner = 0;
  int input = 0, stick = 100;
  int num[3];
  num[0] = input;
  num[1] = stick;
  num[2] = winner;
  if (choise == 1)
    winner = bot_easy(num);
  if (choise == 2)
    winner = bot_medium(num);
  if (choise == 3)
    winner = bot_hard(num);
  return winner;
}

int bot_easy(int *num) {
  srand(time(NULL));
  int choise = 0;
  while (num[0] != 100) {
    game(num[1]);
    printf("\n\n");
    printf("Player, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[1]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 2;

    if (num[1] != 0) {
      if (num[1] < 10)
        choise = num[1];
      else
        choise = rand() % 10 + 1;
      *num += choise;
      *(num + 1) -= choise;
      num[2] = 1;
    }
  }
  int winner = num[2];
  return winner;
}

int bot_medium(int *num) {
  srand(time(NULL));
  int choise = 0;
  while (num[0] != 100) {
    game(num[1]);
    printf("\n\n");
    printf("Player, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[1]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 2;

    if (num[1] != 0) {
      if (num[1] < 10)
        choise = num[1] - 1;
      if (num[1] == 1)
        choise = 1;
      else
        choise = rand() % 10 + 1;
      *num += choise;
      *(num + 1) -= choise;
      num[2] = 1;
    }
  }
  int winner = num[2];
  return winner;
}

int bot_hard(int *num) {
  srand(time(NULL));
  int choise = 0;
  while (num[0] != 100) {
    game(num[1]);
    printf("\n\n");
    printf("Player, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[1]) {
      printf("\nThere are too few matches, try again");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nThe number must be at least 1, and not more than 10");
      printf("\nPlayer, enter the number: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 2;

    if (num[1] != 0) {
      if (num[1] < 10)
        choise = num[1] - 1;
      if (num[1] == 1)
        choise = 1;
      else
        *num += choise;
      *(num + 1) -= choise;
      num[2] = 1;
    }
  }
  int winner = num[2];
  return winner;
}
