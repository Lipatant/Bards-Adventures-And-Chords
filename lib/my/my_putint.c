/*
** EPITECH PROJECT, 2021
** my_putint.c
** File description:
** Requires my_putchar
*/

void my_putchar(char);

void my_putint(long int nbr)
{
    int deci = nbr / 10;
    int unit = 0;
    int abs = 0;

    if (nbr < 0)
        abs = 0 - nbr;
    else
        abs = nbr;
    unit = abs % 10;
    if (abs < 10 && nbr < 0)
        my_putchar('-');
    if (abs >= 10)
        my_putint(deci);
    my_putchar('0' + unit);
}
