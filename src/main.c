/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void game_loop(sfRenderWindow *window, sfEvent event, ALL *all)
{
    while (sfRenderWindow_isOpen(window)) {
        all->is_in_fight = true;
        if (all->is_in_fight == false) {
            ;
        } else {
            main_battle_3d(window, event, all);
        }
    }
}

int main(void)
{
    sfEvent event;
    ALL all;
    set_up(&all);
    sfRenderWindow_setFramerateLimit(all.window, 60);
    game_loop(all.window, event, &all);
    sfRenderWindow_destroy(all.window);
    return EXIT_SUCCESS;
}
