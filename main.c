#include "gamePVE.h"
#include "gamePVP.h"
#include "out.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int winner;
  int answer = out_menu();
  char player_one[16];
  char player_two[16];
  if (answer == 2) {
    rules_page();
    return main();
  }
  if (answer == 3)
    return 0;
  if (answer == 1)
    answer = start_game_out();
  if (answer == 1) {
    winner = gamePVP(player_one, player_two);
    if (winner == 1) {
      system("cls");
      printf("победил игрок ");
      puts(player_one);
    }
    if (winner == 2) {
      system("cls");
      printf("победил игрок ");
      puts(player_two);
    }
    printf("хотите сыграть ещё раз?\n");
    printf("1 - да, вернуться в меню.\n2 = нет, выйти из игры.\n");
    scanf("%d", &answer);
    if (answer == 1)
      return main();
    if (answer == 2)
      return 0;
  }
  if (answer == 3)
    return main();
  if (answer == 2)
    winner = gamePVE(player_one);

  system("pause");
}
