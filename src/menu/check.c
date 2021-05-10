#include "check.h"

int check_input(int max, char* input)
{
    int arr[3];
    int i = 0;
    int answer;
    if (atoi(input) == 0) {
        printf("input error. try again.\n");
        return 0;
    }
    answer = atoi(input);
    while (i < max) {
        arr[i] = i + 1;
        i++;
    }
    if (max == 1) {
        if (answer > 1 || answer < 1) {
            printf("input > 1 or < 1\n");
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
            printf("\nThe number must be at least 1, and not more than 10");
            return 0;
        } else
            return answer;
    }
}
