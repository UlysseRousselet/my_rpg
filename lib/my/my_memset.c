/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** s
*/

#include "my.h"

void my_memset(char *buffer, char character, int len)
{
    int i = 0;
    for (; i < len; i++) {
        buffer[i] = character;
    }
    buffer[i] = '\0';
}
