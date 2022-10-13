/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** main.cpp
** File description:
** Main function
*/

#include <iostream>
#include "returned.hpp"

int start(int const ac, char *av[], char *env[]);

static int return_value(int const returned)
{
    if (returned < 0 || returned >= RETURNED_TOTAL)
        return returned;
    if (RETURNED_MESSAGES[returned] == STRING_NULL)
        return returned;
    std::cout << RETURNED_MESSAGES[returned] << LINEBREAK;
    return returned;
}

int main(int const ac, char *av[], char *env[])
{
    if (env == NULL || env[0] == NULL)
        return return_value(RETURNED_ERROR_NO_ENV);
    return return_value(start(ac, av, env));
}
