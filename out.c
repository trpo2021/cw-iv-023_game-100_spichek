#include "out.h"

int out_menu() {
  system("cls");
  printf("***********************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||||START GAME(1)||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||||RULES PAGE(2)||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||||EXIT GAME|(3)||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("***********************************************************\n");
  int answer = 0;
  scanf("%d", &answer);
  while (answer != 1 && answer != 2 && answer != 3) {
    printf("input error. try again.\n");
    scanf("%d", &answer);
    printf("%d", answer);
  }
  if (answer == 1 && answer == 2 && answer == 3)
    return answer;
}

int rules_page() {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||||||GAME RULES|||||||||||||||||||||||||*\n");
  printf("*Two players take part, competing against each other. Or the*\n");
  printf("*player versus the computer's intelligence. In front of them*\n");
  printf("*100 matches are laid out in a row on the table. Each player*\n");
  printf("*can take from 1 to 10 matches in their turn. The moves are *\n");
  printf("*executed in turn. The participant who took the last match  *\n");
  printf("*(or matches) loses. The first move is made by the player #1*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||RULES OF USE OF THE APP||||||||||||||||||*\n");
  printf("*The application is controlled using numbers(when drawing   *\n");
  printf("*matches and navigating the game menu), and using symbols   *\n");
  printf("*(exclusively when entering an alias).                      *\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  printf("Back - enter 1\n");
  int answer = 0;
  scanf("%d", &answer);
  while (answer != 1) {
    printf("Back - enter 1\n");
    scanf("%d", &answer);
  }
  if (answer == 1)
    return 0;
}

int start_game_out() {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||||||START GAME|||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  printf("Please read the rules before starting the game.");
  printf("Select a game mode:\n");
  int answer = 0;
  while (answer != 1 && answer != 2 && answer != 3) {
    printf("1 - player vs player\n2 - player vs computer\n3 - "
           "go back to the menu\n");
    scanf("%d", &answer);
  }
  if (answer == 1 || answer == 2 || answer == 3)
    return answer;
}

void game(int flag) {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||GAME||||||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  printf("\n");
  printf("%d matches left\n", flag);
  printf("\n");
}

void nickname_out(char *player_name, int i) {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||ENTER YOUR NICKNAME|||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  if (i == 1) {
    printf("Player's nickname(no more than 15 characters): ");
    scanf("%s", player_name);
  }
  if (i == 2) {
    printf("Nickname of the first player(no more than 15 characters): ");
    scanf("%s", player_name);
  }
  if (i == 3) {
    printf("Nickname of the second player(no more than 15 characters): ");
    scanf("%s", player_name);
  }
  printf("\n");
}

int choise_dif() {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*||||||||||||||||||||CHOOSE THE DIFFICULTY||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  printf("\n");
  printf("1 - easy. 2-medium. 3-hard.\n");
  int choise;
  scanf("%d", &choise);
  return choise;
}

void win() {
  system("cls");
  printf("*************************************************************\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||GAME OVER|||||||||||||||||||||||||*\n");
  printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
  printf("*************************************************************\n");
  printf("\n");
}
