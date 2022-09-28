/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** Requires my_strlen
*/

#include <stdlib.h>

int my_strlen(char const *);

static void *my_strcat_fill(char const *str1, char const *str2, char *str3)
{
    int i = 0;

    for (int j = 0; str1[j] != '\0'; j++) {
        str3[i] = str1[j];
        i++;
    }
    for (int j = 0; str2[j] != '\0'; j++) {
        str3[i] = str2[j];
        i++;
    }
    str3[i] = '\0';
}

char *my_strcat(char const *str1, char const *str2)
{
    int length = my_strlen(str1) + my_strlen(str2) + 1;
    char *str3 = NULL;

    if (str1 == NULL || str2 == NULL)
        return NULL;
    str3 = malloc(sizeof(char) * length);
    if (str3 == NULL)
        return NULL;
    my_strcat_fill(str1, str2, str3);
    return str3;
}
