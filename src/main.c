/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void calcul_vertices(env *env)
{
    for (int i = 0; i < env->nbr_vertices; i++) {
        get_angle_vertical(&env->vertices[i], env->player);
        set_verticles_y_to_screen(&env->vertices[i], env->player);
        get_angle_horizontal(&env->vertices[i], env->player);
        set_vertices_x_to_screen(&env->vertices[i], env->player);
    }
}

void game_loop(sfRenderWindow *window, sfEvent event, env *env)
{
    while (sfRenderWindow_isOpen(window)) {
        event_fct(window, event, env);

        calcul_vertices(env);

        sfRenderWindow_clear(window, sfBlack);

        set_convex_shap(env, window);
        
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window;
    sfEvent event;
    env env;
    Player player;
    set_up(&env, &player);
    create_line(&env);
    window = sfRenderWindow_create(mode, "3D test", sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    game_loop(window, event, &env);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
