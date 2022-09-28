/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** No Requirement
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = src[i];
    return dest;
}
