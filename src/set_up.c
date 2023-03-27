/*
** EPITECH PROJECT, 5022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void create_vertices(env *env)
{
    env->nbr_vertices = 24;
    Vertices *vertices = malloc(sizeof(Vertices) * env->nbr_vertices);
    for (int i = 0; i < env->nbr_vertices; i++) {
        vertices[i].x = 0;
        vertices[i].y = 0;
        vertices[i].z = 0;
        vertices[i].angle_relativ_player_hori = 0;
        vertices[i].angle_relativ_player_vertic = 0;
        vertices[i].x_to_screen = 0;
        vertices[i].y_to_screen = 0;
    }
    vertices[0].x = 15; vertices[12].x = 15 + 50;
    vertices[1].x = 13; vertices[13].x = 13 + 50;
    vertices[1].y = 7.5; vertices[13].y = 7.5;
    vertices[2].x = 7.5; vertices[14].x = 7.5 + 50;
    vertices[2].y = 13; vertices[14].y = 13;
    vertices[3].x = 0; vertices[15].x = 50;
    vertices[3].y = 15; vertices[15].y = 15;
    vertices[4].x = -7.5; vertices[16].x = -7.5 + 50;
    vertices[4].y = 13; vertices[16].y = 13;
    vertices[5].x = -13; vertices[17].x = -13 + 50;
    vertices[5].y = 7.5; vertices[17].y = 7.5;
    vertices[6].x = -15; vertices[18].x = -15 + 50;
    vertices[7].x = -13; vertices[19].x = -13 + 50;
    vertices[7].y = -7.5; vertices[19].y = -7.5;
    vertices[8].x = -7.5; vertices[20].x = -7.5 + 50;
    vertices[8].y = -13; vertices[20].y = -13;
    vertices[9].y = -15; vertices[21].y = -15; vertices[21].x = 50;
    vertices[10].x = 7.5; vertices[22].x = 7.5 + 50;
    vertices[10].y = -13; vertices[22].y = -13;
    vertices[11].x = 13; vertices[23].x = 13 + 50;
    vertices[11].y = -7.5; vertices[23].y = -7.5;
    env->vertices = vertices;
}

void set_up(env *env, Player *player)
{    
    player->x = 0;
    player->y = 0;
    player->z = 5;
    player->angle_horiz = 0;
    player->angle_vertic = 0;
    player->last_mouse_pos_x = 0;
    player->last_mouse_pos_y = 0;
    player->sensivity = 100;
    player->avancer = 0;
    player->reculer = 0;
    player->droite = 0;
    player->gauche = 0;
    player->monter = 0;
    player->descendre = 0;
    env->player = player;
    create_vertices(env);
    env->middle_of_screen.x = 960;
    env->middle_of_screen.y = 540;
}

void create_line(env *env)
{
    for (int i = 0; i < 2; i++) {
        env->plateform[i] = sfConvexShape_create();
        sfConvexShape_setPointCount(env->plateform[i], 12);
        sfConvexShape_setOutlineColor(env->plateform[i], sfWhite);
        sfConvexShape_setOutlineThickness(env->plateform[i], 1);
        sfTexture *texture = sfTexture_createFromFile("portal.png", NULL);
        sfConvexShape_setTexture(env->plateform[i], texture, sfTrue);
    }
}
