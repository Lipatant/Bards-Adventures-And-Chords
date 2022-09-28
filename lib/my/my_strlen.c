/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** No Requirement
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
