#include "ctest.h"
#include <stdbool.h>
#include <stdio.h>

#include "menu/check.h"

CTEST(input, input_in_menu_true)
{
    char out[2] = "1";
    bool result;
    int res;
    res = check_input(1, out);
    if (res == 1)
        result = true;
    else
        result = false;
    ASSERT_TRUE(result);
}

CTEST(input, input_name_true)
{
    char out[16] = "Naicik";
    bool result = check_nick(out);
    ASSERT_TRUE(result);
}

CTEST(input, input_in_menu_false)
{
    char out[2] = "a";
    bool result;
    int res;
    res = check_input(1, out);
    if (res == 1)
        result = true;
    else
        result = false;
    ASSERT_TRUE(result);
}

CTEST(input, input_name_false)
{
    char out[16] = "Nai12";
    bool result = check_nick(out);
    ASSERT_TRUE(result);
}
