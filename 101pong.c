/*
** EPITECH PROJECT, 2022
** 101pong
** File description:
** compute the velocity vector and the coordinate of the ball after a moment t
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "include/coordinates.h"

double atof(const char *str);

int atoi(const char *str);

int isdouble(char *str)
{
    char *end;
    int res;

    res = strtof(str, &end);
    return (res);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
}

char *nb_before_comma(char *str)
{
    int i = 0;
    char *res;

    for (i = 0; str[i] != '.' && str[i] != '\0'; i++)
        res[i] = str[i];
    return (res);
}

int my_str_isfloat(char const *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0' || str[i] == '.')
            i++;
        else
            return (0);
    }
    if (str[0] == '-')
        return (1);
    if (str[0] <= '9' && str[0] >= '0')
        return (1);
    return (0);
}

int main(int ag, char **av)
{
    struct coo *m_zero;
    struct coo *m_one;
    struct coo *speed;
    struct coo *end;
    double angle = 0.00;

    m_zero = malloc(sizeof(struct coo));
    m_one = malloc(sizeof(struct coo));
    speed = malloc(sizeof(struct coo));
    end = malloc(sizeof(struct coo));
    if (ag != 8) {
        free(m_zero);
        free(m_one);
        free(speed);
        free(end);
        return (84);
    }
    if (my_str_isnum(av[7]) == 0 || atoi(av[7]) < 0) {
        free(m_zero);
        free(m_one);
        free(speed);
        free(end);
        return (84);
    }
    if (my_str_isfloat(av[1]) == 0 | my_str_isfloat(av[2]) == 0 | my_str_isfloat(av[3]) == 0 | my_str_isfloat(av[4]) == 0 | my_str_isfloat(av[5]) == 0 | my_str_isfloat(av[6]) == 0) {
        free(m_zero);
        free(m_one);
        free(speed);
        free(end);
        return (84);
    }
    m_zero->x_coo = atof(av[1]);
    m_zero->y_coo = atof(av[2]);
    m_zero->z_coo = atof(av[3]);

    m_one->x_coo = atof(av[4]);
    m_one->y_coo = atof(av[5]);
    m_one->z_coo = atof(av[6]);

    speed->x_coo = m_one->x_coo - m_zero->x_coo;
    speed->y_coo = m_one->y_coo - m_zero->y_coo;
    speed->z_coo = m_one->z_coo - m_zero->z_coo;

    end->x_coo = m_one->x_coo + atoi(av[7]) * speed->x_coo;
    end->y_coo = m_one->y_coo + atoi(av[7]) * speed->y_coo;
    end->z_coo = m_one->z_coo + atoi(av[7]) * speed->z_coo;

    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", speed->x_coo, speed->y_coo, speed->z_coo);
    printf("At time t + %.0f, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", atof(av[7]), end->x_coo, end->y_coo, end->z_coo);

    if (m_zero->z_coo < m_one->z_coo && m_zero->z_coo > 0 && m_one->z_coo > 0)
        printf("The ball won't reach the paddle.\n");
    else if (m_zero->z_coo > m_one->z_coo && m_one->z_coo < 0)
        printf("The ball won't reach the paddle.\n");
    else if (speed->z_coo == 0 && m_one->z_coo != 0)
        printf("The ball won't reach the paddle.\n");
    else if (speed->x_coo == 0 && speed->y_coo == 0 && speed->z_coo == 0 && m_one->z_coo == 0) {        
        printf("The incidence angle is:\n0.00 degrees\n");
        free(m_zero);
        free(m_one);
        free(speed);
        free(end);
        return (0);
    } else if (speed->x_coo == 0 && speed->y_coo == 0 && speed->z_coo == 0)
        printf("The ball won't reach the paddle.\n");
    else if (m_zero->x_coo == m_one->x_coo && m_zero->y_coo == m_one->y_coo) {
        printf("The incidence angle is:\n90.00 degrees\n");
    } else {
        angle = acos((sqrt(speed->x_coo * speed->x_coo + speed->y_coo * speed->y_coo)) / (sqrt(speed->x_coo * speed->x_coo + speed->y_coo * speed->y_coo + speed->z_coo * speed->z_coo)));
        angle = angle * (180.0 / 3.1415926535);
        printf("The incidence angle is:\n%.2f degrees\n", angle);
    }
    free(m_zero);
    free(m_one);
    free(speed);
    free(end);
    return (0);
}
