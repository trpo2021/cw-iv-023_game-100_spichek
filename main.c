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
      printf("победил игрок ");
      puts(player_one);
    }
    if (winner == 2) {
      printf("победил игрок ");
      puts(player_two);
    }
  }
  if (answer == 3)
    return main();
  if (answer == 2)
    winner = gamePVE(player_one);

  system("pause");
}
