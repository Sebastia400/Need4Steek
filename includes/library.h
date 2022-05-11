/*
** EPITECH PROJECT, 2022
** my_tetris.h
** File description:
** my_tetris
*/

#ifndef LIBRARY_H_
    #define LIBRARY_H_
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <math.h>

    typedef struct t_var {
    char **info;
    float distance_prev1;
    float distance_prev2;
    float distance_actual;
    float velocity;
    unsigned int acuracity;
    } s_var;

void my_putstr(char const *str);
int my_strlen2(char const *str);
char *my_revstr(char *str);
int my_nbrlen(int nb);
char *my_return_char(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char *src);
int quantity_sentences(int size_text, char *str, char delimiter);
int len_sentence(char *arraytext, char delimiter);
char **save_word(char *arraytext, char separator);
int array_len(char **array);
void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);
void write_output(char *out);
void turn_car_ext(s_var *all, int left, int right);
void turn_car(s_var *all, int left, int right);
#endif