/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void main_battle_3d(sfRenderWindow *window, sfEvent event, ALL *all)
{
    event_fct(window, event, all->env_3d);
    calcul_3D(all->env_3d);
    print_3D_scene(window, all->env_3d);
}
