/*
** EPITECH PROJECT, 2021
** my_putdouble.c
** File description:
** Requires my_putchar my_putint.c
*/

void my_putchar(char);

void my_putint(int);

void my_putdouble(double nbr, int e)
{
    int e10 = 1;
    int nb2 = 0;

    for (int i = 0; i < e; i++)
        e10 *= 10;
    nb2 = nbr * e10;
    my_putint(nb2 / e10);
    my_putchar('.');
    my_putint(nb2 % e10);
}
