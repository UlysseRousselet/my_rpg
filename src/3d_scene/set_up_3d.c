/*
** EPITECH PROJECT, 5022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void create_vertices(Env_3d *env)
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

void create_line(Env_3d *env_3d)
{
    for (int i = 0; i < 2; i++) {
        env_3d->plateform[i] = sfConvexShape_create(); 
        sfConvexShape_setPointCount(env_3d->plateform[i], 12);
        sfConvexShape_setOutlineColor(env_3d->plateform[i], sfWhite);
        sfConvexShape_setOutlineThickness(env_3d->plateform[i], 1);
        sfTexture *texture = sfTexture_createFromFile("assets/ground.jpg", NULL);
        sfConvexShape_setTexture(env_3d->plateform[i], texture, sfTrue);
    }
}

void set_up_skybox(Env_3d *env)
{
    env->sky_box = sfConvexShape_create();
    sfConvexShape_setPointCount(env->sky_box, 4);
    env->sky_box_size.x = 0;
    env->sky_box_size.y = 0;
    sfConvexShape_setPoint(env->sky_box, 0, env->sky_box_size);
    env->sky_box_size.x = 1920;
    sfConvexShape_setPoint(env->sky_box, 1, env->sky_box_size);
    env->sky_box_size.y = 540;
    sfConvexShape_setPoint(env->sky_box, 2, env->sky_box_size);
    env->sky_box_size.x = 0;
    sfConvexShape_setPoint(env->sky_box, 3, env->sky_box_size);
    sfColor sky_box_color = {50, 50, 50, 255};
    sfConvexShape_setFillColor(env->sky_box, sky_box_color);
}

void set_up_3d_scene(ALL *all)
{
    Camera_3d *camera = malloc(sizeof(Camera_3d));
    Env_3d *env = malloc(sizeof(Env_3d));
    camera->x = 0;
    camera->y = 0;
    camera->z = 5;
    camera->angle_horiz = 0;
    camera->angle_vertic = 0;
    camera->last_mouse_pos_x = 0;
    camera->last_mouse_pos_y = 0;
    camera->sensivity = 100;
    camera->avancer = 0;
    camera->reculer = 0;
    camera->droite = 0;
    camera->gauche = 0;
    camera->monter = 0;
    camera->descendre = 0;
    env->camera = camera;
    env->middle_of_screen.x = MIDSCREENX;
    env->middle_of_screen.y = MIDSCREENY;
    set_up_skybox(env);
    create_vertices(env);
    create_line(env);
    all->env_3d = env;
}
