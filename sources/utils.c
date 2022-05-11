/*
** EPITECH PROJECT, 2022
** my_tetris.h
** File description:
** my_tetris
*/

#include "./../includes/library.h"

void my_putstr(char const *str)
{
    int len = 0;

    if (str) {
        len = strlen(str);
        if (len > 0)
            write(1, str, len);
    }
}

int my_strlen2(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char *dup = malloc(sizeof(char) * my_strlen2(str) + 2);
    int j = my_strlen2(str);
    int i = 0;

    memset(dup, '\0', my_strlen2(str) + 1);
    while (str[i] != '\0') {
        dup[i] = str[j];
        i++;
        j--;
    }
    dup[i] = '\0';
    return (dup);
}

int my_nbrlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        nb /= 10;
        len++;
    } return (len);
}
