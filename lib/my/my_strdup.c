/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Requires my_strlen/my_strcpy
*/

#include <stdlib.h>

char *my_strcpy(char *, char const *);

int my_strlen(char const *);

char *my_strdup(char const *src)
{
    char *str = NULL;

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    my_strcpy(str, src);
    return (str);
}
