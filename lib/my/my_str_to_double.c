/*
** EPITECH PROJECT, 2021
** my_str_to_double.c
** File description:
** No Requirement
*/

#include <stdlib.h>

static double decimal_part(char const *str)
{
    int i = 0;
    double value = 0;

    for (i = 0; str[i] != '\0'; i++);
    for (i--; i >= 0 && str[i] != '.'; i--)
        value = value / 10 + str[i] - '0';
    return (value / 10);
}

double my_str_to_double(char const *str)
{
    int i = 0;
    int mult = 1;
    double value = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '-')
        mult = -1;
    for (; str[i] == '-'; i++);
    for (; str[i] != '\0' && str[i] != '.'; i++)
        value = value * 10 + str[i] - '0';
    for (; str[i] == '.'; i++);
    if (str[i] == '\0')
        return value * mult;
    return (value + decimal_part(str)) * mult;
}
