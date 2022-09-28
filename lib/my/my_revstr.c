/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** No Requirement
*/

char *my_revstr(char *str)
{
    int i = 0;
    int length = 0;
    char a = 0;

    for (length = 0; str[length] != '\0'; length++)
        length = length;
    length--;
    for (i = 0; i < ((length + 1) / 2 + (length + 1) % 2); i++) {
        a = str[i];
        str[i] = str[length - i];
        str[length - i] = a;
    }
    return (str);
}
