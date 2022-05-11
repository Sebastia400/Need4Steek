/*
** EPITECH PROJECT, 2022
** my_tetris.h
** File description:
** my_tetris
*/

#include "./../includes/library.h"

int len_sentence(char *arraytext, char delimiter)
{
    int i = 0;
    while (arraytext[i] != '\0' && arraytext[i] != delimiter)
        i++;
    return (i);
}

char **save_word(char *arraytext, char separator)
{
    int len = 0;
    int i = 0;
    int k = 0;
    int j = 0;
    char **sentences;

    sentences = calloc(quantity_sentences(strlen(arraytext), arraytext,
    separator) + 2, sizeof(char *));
    while (i < strlen(arraytext)) {
        len = len_sentence(arraytext, separator);
        sentences[j] = calloc(len * 2 + 10, sizeof(char));
        k = 0;
        while (arraytext[i] != separator && arraytext[i] != '\0'
        && arraytext[i] != '\n')
            sentences[j][k++] = arraytext[i++];
        j++;
        i++;
    }
    sentences[j] = NULL;
    return (sentences);
}

int array_len(char **array)
{
    int len = 0;

    while (array[len] != NULL)
        len++;
    return (len - 1);
}

void reverse(char *str, int len)
{
    int i = 0, j = len - 1, temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int intToStr(int x, char str[], int d)
{
    int i = 0;

    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
    while (i < d)
        str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return (i);
}
