/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** No Requirement
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int my_strcmp(char const *str1, char const *str2)
{
    if (str1 == NULL || str2 == NULL)
        return 0;
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}
