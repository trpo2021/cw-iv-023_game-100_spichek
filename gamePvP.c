#include "gamePVP.h"
#include "out.h"

int gamePVP(char *player_one, char *player_two) {
  PVP_out();
  //почему-то не работает первый ввод имени
  printf("Псевдоним второго игрока(не более 15 символов): ");
  fgets(player_one, 16, stdin);
  puts(player_one);
  printf("\n");
  printf("Псевдоним первого игрока(не более 15 символов): ");
  fgets(player_two, 16, stdin);
  puts(player_two);
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
    stick(num[1]);
    printf("\n\n");

    printf("игрок №1, введите число: ");
    scanf("%d", &choise);
    if (choise > num[1]) {
      printf("\nспичек слишком мало, попробуйте ещё раз");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nчисло должно быть не меньше 1, и не больше 10");
      printf("\nигрок №1, введите число: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nспичек слишком мало, попробуйте ещё раз");
        choise = 100;
      }
    }
    *num += choise;
    *(num + 1) -= choise;
    num[2] = 2;

    stick(num[1]);
    printf("\n\n");
    printf("игрок №2, введите число: ");
    scanf("%d", &choise);

    if (choise > num[1]) {
      printf("\nспичек слишком мало, попробуйте ещё раз");
      choise = 100;
    }

    while (choise < 1 || choise > 10) {
      choise = 0;
      printf("\nчисло должно быть не меньше 1, и не больше 10");
      printf("\nигрок №2, введите число: ");
      scanf("%d", &choise);
      if (choise > num[1]) {
        printf("\nспичек слишком мало, попробуйте ещё раз");
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
