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
      win();
      printf("The player %s won!", player_one);
    }
    if (winner == 2) {
      win();
      printf("The player %s won!", player_two);
    }
    printf("Do you want to play again?\n");
    printf("1 - yes, go back to the menu.\n2 - no, quit the game.\n");
    scanf("%d", &answer);
    if (answer == 1)
      return main();
    if (answer == 2)
      return 0;
  }

  if (answer == 3)
    return main();
  if (answer == 2) {
    winner = gamePVE(player_one);
    if (winner == 1) {
      win();
      printf("Player %s win!\n", player_one);
    }
    if (winner == 2) {
      win();
      srand(time(NULL));
      int bot = rand() % 100 + 1;
      printf("BOT_%d win!\n", bot);
    }
    printf("Do you want to play again?\n");
    printf("1 - yes, go back to the menu.\n2 - no, quit the game.\n");
    scanf("%d", &answer);
    if (answer == 1)
      return main();
    if (answer == 2)
      return 0;
  }
}
