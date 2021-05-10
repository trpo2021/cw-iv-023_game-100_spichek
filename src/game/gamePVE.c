#include "gamePVE.h"
#include "menu/out.h"

int gamePVE(char* player_one)
{
    int i = 1;
    nickname_out(player_one, i);
    int choise;
    choise = choise_dif();
    int num[3];
    num[0] = 100;
    // stick
    num[1] = 0;
    // winner
    if (choise == 1)
        num[1] = bot_easy(num);
    if (choise == 2)
        num[1] = bot_medium(num);
    if (choise == 3)
        num[1] = bot_hard(num);
    return num[1];
}

int bot_easy(int* num)
{
    srand(time(NULL));
    int choise = 0;
    while (num[0] > 0) {
        game(num[0]);
        choise = player_input(num);
        *num -= choise;
        num[1] = 2;

        if (num[0] > 0) {
            if (num[0] <= 10)
                choise = num[0];
            else
                choise = rand() % 10 + 1;
            *num -= choise;
            num[1] = 1;
        }
    }
    int winner = num[1];
    return winner;
}

int bot_medium(int* num)
{
    srand(time(NULL));
    int choise = 0;
    while (num[0] > 0) {
        game(num[0]);
        choise = player_input(num);
        *num -= choise;
        num[1] = 2;

        if (num[0] > 0) {
            if (num[0] <= 10)
                choise = num[0] - 1;
            if (num[0] == 1)
                choise = 1;
            else
                choise = rand() % 10 + 1;
            *num -= choise;
            num[1] = 1;
        }
    }
    int winner = num[1];
    return winner;
}

int bot_hard(int* num)
{
    srand(time(NULL));
    int choise = 0;
    while (num[0] > 0) {
        game(num[0]);
        choise = player_input(num);
        *num -= choise;
        num[1] = 2;

        if (num[0] > 0) {
            if (num[0] == 1)
                choise = 1;
            if (num[0] < 100)
                choise = 11 - choise;
            if (num[0] <= 10)
                choise = num[0] - 1;

            *num -= choise;
            num[1] = 1;
        }
    }
    int winner = num[1];
    return winner;
}

int player_input(int* num)
{
    int choise;
    game(num[0]);
    printf("Player, enter the number: ");
    scanf("%d", &choise);
    if (choise > num[0]) {
        printf("\nThere are too few matches, try again");
        choise = 100;
    }

    while (choise < 1 || choise > 10) {
        choise = 0;
        printf("\nThe number must be at least 1, and not more than 10");
        printf("\nPlayer, enter the number: ");
        scanf("%d", &choise);
        if (choise > num[0]) {
            printf("\nThere are too few matches, try again");
            choise = 100;
        }
    }
    return choise;
}
