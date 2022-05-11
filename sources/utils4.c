/*
** EPITECH PROJECT, 2022
** my_tetris.h
** File description:
** my_tetris
*/

#include "./../includes/library.h"

void ftoa(float n, char *res, int afterpoint)
{
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = intToStr(ipart, res, 0);

    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

void write_output(char *out)
{
    int rd;
    char *buf = malloc(sizeof(char) * 4000);

    my_putstr(my_strcat(out, "\n"));
    rd = read(0, buf, 4000);
    buf[rd] = '\0';
}

void turn_car_ext(s_var *all, int left, int right)
{
    float turn = 0.0;
    char *out = NULL;
    char res[10];

    turn = (float)(right - left) / all->acuracity;
    if (turn <= -1) {
        write_output("WHEELS_DIR:-1");
    } else {
        ftoa(turn, res, 4);
        out = my_strcat("WHEELS_DIR:", "-");
        write_output(my_strcat(out, res));
        free(out);
    }
}

void turn_car(s_var *all, int left, int right)
{
    float turn;
    char res[10];
    char *out = NULL;

    if (left > right) {
        turn = (float)(left - right) / all->acuracity;
        if (turn > 1) {
            write_output("WHEELS_DIR:1");
        } else {
            ftoa(turn, res, 4);
            out = my_strcat("WHEELS_DIR:", res);
            write_output(out);
            free(out);
        }
    } else if (right > left) {
        turn_car_ext(all, left, right);
    } else
        write_output("WHEELS_DIR:0");
}
