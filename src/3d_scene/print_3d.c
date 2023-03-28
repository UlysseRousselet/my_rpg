/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void print_skybox(Env_3d *env, sfRenderWindow *window)
{
    env->sky_box_size.x = 1920;
    env->sky_box_size.y = sin(env->camera->angle_vertic * (PI / 180)) * 1080 + 540;
    sfConvexShape_setPoint(env->sky_box, 2, env->sky_box_size);
    env->sky_box_size.x = 0;
    sfConvexShape_setPoint(env->sky_box, 3, env->sky_box_size);
    sfRenderWindow_drawConvexShape(window, env->sky_box, NULL);
}

void print_3D(Env_3d *env, sfRenderWindow *window)
{
    sfVector2f pos[env->nbr_vertices];
    for (int i = 0; i < 12; i++) {
        pos[i].x = env->vertices[i].x_to_screen;
        pos[i].y = env->vertices[i].y_to_screen;
        sfConvexShape_setPoint(env->plateform[0], i, pos[i]);
    }
    for (int i = 12; i < env->nbr_vertices; i++) {
        pos[i].x = env->vertices[i].x_to_screen;
        pos[i].y = env->vertices[i].y_to_screen;
        sfConvexShape_setPoint(env->plateform[1], i - 12, pos[i]);
    }
    sfRenderWindow_drawConvexShape(window, env->plateform[0], NULL);
    sfRenderWindow_drawConvexShape(window, env->plateform[1], NULL);
}

void print_3D_scene(sfRenderWindow *window, Env_3d *env)
{
    sfRenderWindow_clear(window, sfBlack);
    print_skybox(env, window);
    print_3D(env, window);
    sfRenderWindow_display(window);
}