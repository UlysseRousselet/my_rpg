/*
** EPITECH PROJECT, 5022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void set_up_sfwindow(ALL *all)
{
    sfVideoMode mode = {1920, 1080, 32};
    all->window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(all->window, sfFalse);
    sfRenderWindow_setFramerateLimit(all->window, 60);
}

void set_up(ALL *all)
{
    set_up_3d_scene(all);
    set_up_sfwindow(all);
    all->is_in_fight = false;
}
