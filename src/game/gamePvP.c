#include "gamePVP.h"
#include "menu/check.h"
#include "menu/out.h"

int gamePVP(char* player_one, char* player_two)
{
    nickname_out(player_one, 2);
    nickname_out(player_two, 3);
    int num[2];
    num[0] = 100;
    // stick
    num[1] = 0;
    // winner
    num[1] = maingame(num);
    return num[1];
}

int maingame(int* num)
{
    int choise = 0;
    while (num[0] > 0) {
        game(num[0]);
        printf("\nPlayer #1, enter the number: \n");
        choise = player_input_PVP(num);
        *num -= choise;
        num[1] = 2;
        if (num[0] == 0)
            return num[1];

        game(num[0]);
        printf("Player #2, enter the number: \n");
        choise = player_input_PVP(num);
        *num -= choise;
        num[1] = 1;
    }
    return num[1];
}

int player_input_PVP(int* num)
{
    char input[3];
    int choise = 0;
    while (choise < 1 || choise > 10) {
        while (choise == 0) {
            fgets(input, 3, stdin);
            choise = check_input(10, input);
        }
        if (choise < 1 && choise > 10) {
            printf("\nThe number must be at least 1, and not more than 10\n");
            choise = 100;
        }
        if (choise > num[0]) {
            printf("\nThere are too few matches, try again\n");
            choise = 100;
        }
    }
    return choise;
}
// release
