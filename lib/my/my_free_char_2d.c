/*
** EPITECH PROJECT, 2022
** my_free_char_2d.c
** File description:
** No Requirement
*/

#include <stdlib.h>

char *my_free_char_2d(char **ary)
{
    if (ary == NULL)
        return NULL;
    for (int i = 0; ary[i] != NULL; i++)
        free(ary[i]);
    free(ary);
    return NULL;
}
