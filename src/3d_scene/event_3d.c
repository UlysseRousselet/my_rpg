/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void move_player(Env_3d *env)
{
    if (env->camera->avancer == 1) {
        env->camera->x += cos(env->camera->angle_horiz / (180/PI));
        env->camera->y += sin(env->camera->angle_horiz / (180/PI));
    }
    if (env->camera->reculer == 1) {
        env->camera->x -= cos(env->camera->angle_horiz / (180/PI));
        env->camera->y -= sin(env->camera->angle_horiz / (180/PI));
    }
    if (env->camera->droite == 1) {
        env->camera->x -= cos((env->camera->angle_horiz + 90) / (180/PI));
        env->camera->y -= sin((env->camera->angle_horiz + 90) / (180/PI));
    }
    if (env->camera->gauche == 1) {
        env->camera->x -= cos((env->camera->angle_horiz - 90) / (180/PI));
        env->camera->y -= sin((env->camera->angle_horiz - 90) / (180/PI));
    }
    if (env->camera->monter == 1) {
        env->camera->z += 1;
    }
    if (env->camera->descendre == 1) {
        env->camera->z -= 1;
    }
}

void event_fct(sfRenderWindow *window, sfEvent event, Env_3d *env)
{
    sfMouse_setPositionRenderWindow(env->middle_of_screen, window);
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtKeyPressed) {
            switch (event.key.code) {
                case sfKeyZ:
                    env->camera->avancer = 1;
                    break;
                case sfKeyS:
                    env->camera->reculer = 1;
                    break;
                case sfKeyD:
                    env->camera->droite = 1;
                    break;
                case sfKeyQ:
                    env->camera->gauche = 1;
                    break;
                case sfKeySpace:
                    env->camera->monter = 1;
                    break;
                case sfKeyLShift:
                    env->camera->descendre = 1;
                    break;
                default:
                    break; 
            }
        }
        if (event.type == sfEvtKeyReleased) {
            switch (event.key.code) {
                case sfKeyZ:
                    env->camera->avancer = 0;
                    break;
                case sfKeyS:
                    env->camera->reculer = 0;
                    break;
                case sfKeyD:
                    env->camera->droite = 0;
                    break;
                case sfKeyQ:
                    env->camera->gauche = 0;
                    break;
                case sfKeySpace:
                    env->camera->monter = 0;
                    break;
                case sfKeyLShift:
                    env->camera->descendre = 0;
                    break;
                default:
                    break; 
            }
        }
        if (event.type == sfEvtMouseMoved) {
            env->camera->angle_horiz -= (float)(event.mouseMove.x - env->middle_of_screen.x) / env->camera->sensivity;
            env->camera->angle_vertic -= (float)(event.mouseMove.y - env->middle_of_screen.y) / env->camera->sensivity;
            if (env->camera->angle_horiz > 360)
                env->camera->angle_horiz = 0;
            if (env->camera->angle_horiz < 0)
                env->camera->angle_horiz = 360;
            if (env->camera->angle_vertic > 360)
                env->camera->angle_vertic = 0;
            if (env->camera->angle_vertic < 0)
                env->camera->angle_vertic = 360;
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    move_player(env);
    
}
