/*
** EPITECH PROJECT, 2022
** funct_flag.c
** File description:
** printf
*/

#include <stdlib.h>
#include "my.h"

char **malloc_2d_array(int y, int x)
{
    char **tab = malloc(sizeof(char*) * y);
    for (int i = 0; i < y; i++) {
        tab[i] = malloc(sizeof(char) * x);
    }
    return tab;
}
