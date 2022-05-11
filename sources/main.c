/*
** EPITECH PROJECT, 2022
** my_tetris.h
** File description:
** my_tetris
*/

#include "./../includes/library.h"

void move_car(s_var *all)
{
    int i = 3;
    int len = array_len(all->info);
    int left = 0;
    int right = 0;

    while (i <= 3) {
        if (atoi(all->info[i]) > 600)
            left += 600;
        else
            left += atoi(all->info[i]);

        if (atoi(all->info[len - i]) > 600)
            right += 600;
        else
            right += atoi(all->info[len - i + 2]);
        i++;
    }
    turn_car(all, left, right);
}

void speed_car(s_var *all)
{
    char *buf = malloc(sizeof(char) * 4000);
    char res[10];
    char *prova = NULL;
    float distance = 0.0;

    all->distance_prev2 = all->distance_prev1;
    all->distance_prev1 = all->distance_actual;
    all->distance_actual = (float)atoi(all->info[array_len(all->info) / 2]);
    distance = (all->distance_prev2 + all->distance_prev1
    + all->distance_actual) / 3;
    all->velocity = distance / 2500 + 0.2;
    if (all->velocity >= 1)
        all->velocity = 1.0;
    ftoa(all->velocity, res, 4);
    if (all->velocity < 1)
        prova = my_strcat("0", res);
    else
        prova = strdup(res);
    prova = my_strcat("CAR_FORWARD:", prova);
    write_output(prova);
    free(prova);
}

void get_acuracity(s_var *all)
{
    float distance = (all->distance_prev2 + all->distance_prev1
    + all->distance_actual) / 3;
    all->acuracity = (int)(distance * 2 + 150);
}

s_var *ini_struct(void)
{
    s_var *tmp = malloc(sizeof(s_var));

    tmp->info = NULL;
    tmp->distance_prev1 = 3000;
    tmp->distance_prev2 = 3000;
    tmp->velocity = 0;
    tmp->acuracity = 0;
    return (tmp);
}

int main (void)
{
    char *buf = malloc(sizeof(char) * 4000);
    s_var *all = ini_struct();
    int rd;

    my_putstr("START_SIMULATION\n");
    rd = read(0, buf, 4000);
    buf[rd] = '\0';
    while (1) {
        my_putstr("GET_INFO_LIDAR\n");
        rd = read(0, buf, 4000);
        buf[rd] = '\0';
        all->info = save_word(buf, ':');
        speed_car(all);
        get_acuracity(all);
        move_car(all);
        usleep(1000);
    }
    free(buf);
    sleep(1);
}