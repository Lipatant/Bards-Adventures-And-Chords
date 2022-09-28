/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** my.h
** File description:
** Random things that I need
*/

#pragma once
    #define POWER_OF_TWO(i) (1 << (i))
    #define LINEBREAK '\n'
    #define ABS(X) (((X) < 0) ? (0 - (X)) : (X))
    #define ISD(X) ('0' <= (X) && (X) <= '9')
    #define ISNOTD(X) ((X) < '0' || '9' < (X))
    #define ITC(X) ((X) + '0')
    #define CTI(X) ((X) - '0')
    #define XOR(A, B) (((A) || (B)) && !((A) && (B)))
    #define MIN(X, M) (((X) < (M)) ? (M) : (X))
    #define MAX(X, M) (((X) > (M)) ? (M) : (X))
    #define DUP(X) (my_strdup(X))
    #define LEN(X) (my_strlen(X))

char *my_strcat(char const *str1, char const *str2);
void my_putchar(char);
int my_putstr(char const *);
void my_putint(long int);
void my_putdouble(double number, int powerof10);
char *my_revstr(char *);
char *my_strcpy(char *destination, char const *copied);
char *my_strdup(char const *);
int my_strlen(char const *);
int my_str_to_int(char const *);
double my_str_to_double(char const *);
char *my_int_to_str(int);
char **my_str_to_array(char const *arg, char const *sep);
char *my_free_char_2d(char **ary);
int my_strcmp(char const *str1, char const *str2);
