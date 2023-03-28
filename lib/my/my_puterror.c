/*
** EPITECH PROJECT, 2022
** my_puterror.c
** File description:
** a
*/

#include <unistd.h>

void my_puterror(char const *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
}
