#include "out.h"
#include "check.h"

int out_menu()
{
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
    char input[2] = "NN";
    while (answer == 0) {
        fgets(input, 2, stdin);
        answer = check_input(3, input);
    }
    return answer;
}

int rules_page()
{
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
    char input[2] = "NN";
    fgets(input, 2, stdin);
    while (check_input(1, input) == 0)
        fgets(input, 2, stdin);
    return 0;
}

int start_game_out()
{
    system("cls");
    printf("*************************************************************\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*||||||||||||||||||||||||START GAME|||||||||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*************************************************************\n");
    printf("Please read the rules before starting the game.");
    printf("Select a game mode:\n");
    printf("1 - player vs player\n2 - player vs computer\n3 - go back to the "
           "menu\n");
    int answer = 0;
    char input[2] = "NN";
    while (answer == 0) {
        fgets(input, 2, stdin);
        answer = check_input(3, input);
    }
    return answer;
}

void game(int flag)
{
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

int nickname_out(char* player_name, int choise)
{
    system("cls");
    printf("*************************************************************\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||ENTER YOUR NICKNAME|||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*************************************************************\n");
    char string[16];
    if (choise == 1) {
        printf("use only latin symbol and don't use spaces\n");
        printf("Player's nickname(no more than 15 characters): ");
        scanf("%s", string);
        if (check_nick(string) == true) {
            strcpy(player_name, string);
            return 0;
        } else
            return nickname_out(player_name, 1);
    }
    if (choise == 2) {
        printf("use only latin symbol and don't use spaces\n");
        printf("Nickname of the first player(no more than 15 characters): ");
        scanf("%s", string);
        if (check_nick(string) == true) {
            strcpy(player_name, string);
            return 0;
        } else
            return nickname_out(player_name, 2);
    }
    if (choise == 3) {
        printf("use only latin symbol and don't use spaces\n");
        printf("Nickname of the second player(no more than 15 characters): ");
        scanf("%s", string);
        if (check_nick(string) == true) {
            strcpy(player_name, string);
            return 0;
        } else
            return nickname_out(player_name, 2);
    }
    printf("\n");
    return 0;
}

int choise_dif()
{
    system("cls");
    printf("*************************************************************\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*||||||||||||||||||||CHOOSE THE DIFFICULTY||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*************************************************************\n");
    printf("\n");
    printf("1 - easy. 2-medium. 3-hard.\n");
    int answer = 0;
    char input[2] = "NN";
    while (answer == 0) {
        fgets(input, 2, stdin);
        answer = check_input(3, input);
    }
    return answer;
}

void win()
{
    system("cls");
    printf("*************************************************************\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||||||GAME OVER|||||||||||||||||||||||||*\n");
    printf("*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*\n");
    printf("*************************************************************\n");
    printf("\n");
}
