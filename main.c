#include "out.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int answer = out_menu();
  char player_one[15], player_two[15];
  if (answer == 2) {
    rules_page();
    return main();
  }
  if (answer == 3)
    return 0;
  if (answer == 1)
    answer = start_game_out();

  system("pause");
}
