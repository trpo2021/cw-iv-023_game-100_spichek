#include "check.h"

int check_input(int max, char* input)
{
    int answer;
    char admin[] = "NN";
    if (strcmp(admin, input) == 0)
        return 0;
    if (atoi(input) == 0) {
        printf("please do not enter anything other than numbers.\n");
        return 0;
    }
    answer = atoi(input);
    if (max == 1) {
        if (answer > 1 || answer < 1) {
            printf("input not equal to 1\n");
            return 0;
        } else
            return answer;
    }
    if (max == 2) {
        if (answer > 2 || answer < 1) {
            printf("input > 2 or < 1\n");
            return 0;
        } else
            return answer;
    }
    if (max == 3) {
        if (answer > 3 || answer < 1) {
            printf("input > 3 or < 1\n");
            return 0;
        } else
            return answer;
    }
    if (max == 10) {
        if (answer < 1 || answer > 10) {
            printf("\nThe number must be at least 1, and not more than 10\n");
            return 0;
        } else
            return answer;
    }
    return 0;
}

bool check_nick(char* nick)
{
    int i = 0;
    while (i != 15) {
        if ((int)*(nick + i) == 0)
            return true;
        if (((int)*(nick + i) > 64 && (int)*(nick + i) < 91)
            || ((int)*(nick + i) > 96 && (int)*(nick + i) < 123))
            i++;
        else
            return false;
    }
    return true;
}
