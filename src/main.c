/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void game_loop(sfEvent event, ALL *all)
{
    while (all->is_in_fight == false && sfRenderWindow_isOpen(all->window))
    ; // deplacement sur la map en 2D
    while (all->is_in_fight == true && sfRenderWindow_isOpen(all->window)) {
        //combat en 3d
        main_battle_3d(all->window, event, all);
    }
}

int main(void)
{
    sfEvent event;
    ALL all;
    set_up(&all);

    all.is_in_fight = true;

    while (sfRenderWindow_isOpen(all.window)) {
        game_loop(event, &all);
    }
    return 0;
}
