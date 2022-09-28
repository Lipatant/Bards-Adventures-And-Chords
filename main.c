/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "returned.h"
#include <stddef.h>

int start(int const ac, char * const *av, char * const *env);

int main(int const ac, char * const *av, char * const *env)
{
    if (env == NULL || env[0] == NULL)
        return RETURNED_EXIT;
    return start(ac, av, env);
}
