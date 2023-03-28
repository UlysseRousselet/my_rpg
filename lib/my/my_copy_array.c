/*
** EPITECH PROJECT, 2022
** free_array.c
** File description:
** lib
*/

#include "my.h"

char **copy_array(char **array)
{
    char **new_array = malloc(sizeof(char*) * (my_len_of_array(array) + 1));
    int y = my_len_of_array(array);
    for (int i = 0; i < y; i++) {
        new_array[i] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
    }
    new_array[y] = NULL;
    for (int i = 0; i < y; i++) {
        my_strcpy(new_array[i], array[i]);
    }
    return new_array;
}
