/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** 3D test
*/

#include "my.h"

void get_angle_horizontal(Vertices *v, Camera_3d *p)
{
    double distance_x = v->x - p->x;
    double distance_y = v->y - p->y;
    double distance_xy = sqrt(distance_x * distance_x + distance_y * distance_y);
    distance_x = distance_x / distance_xy;
    distance_y = distance_y / distance_xy;
    v->angle_relativ_player_hori = atan2(distance_y, distance_x) * (180/PI);
    if (v->angle_relativ_player_hori < 0)
        v->angle_relativ_player_hori += 360;
}

void set_vertices_x_to_screen(Vertices *v, Camera_3d *p)
{
    if (p->angle_horiz < v->angle_relativ_player_hori - 180)
        v->x_to_screen = (v->angle_relativ_player_hori - 360 - p->angle_horiz) * -21 + 960;
    else if (p->angle_horiz > v->angle_relativ_player_hori + 180)
        v->x_to_screen = (v->angle_relativ_player_hori + 360 - p->angle_horiz) * -21 + 960;
    else {
        v->x_to_screen = (v->angle_relativ_player_hori - p->angle_horiz) * -21 + 960;
    }
}

void get_angle_vertical(Vertices *v, Camera_3d *p)
{
    double distance_x = v->x - p->x;
    double distance_y = v->y - p->y;
    double distance_z = v->z - p->z;
    double distance_xy = sqrt(distance_x * distance_x + distance_y * distance_y);
    double distance_xyz = sqrt(distance_xy * distance_xy + distance_z * distance_z);
    distance_z = distance_z / distance_xyz;
    distance_xy = distance_xy / distance_xyz;
    v->angle_relativ_player_vertic = atan2(distance_z, distance_xy) * (180/PI);
}

void set_verticles_y_to_screen(Vertices *v, Camera_3d *p)
{
    if (p->angle_vertic < v->angle_relativ_player_vertic - 180)
        v->y_to_screen = (v->angle_relativ_player_vertic - 360 - p->angle_vertic) * -21 + 540;
    else if (p->angle_vertic > v->angle_relativ_player_vertic + 180)
        v->y_to_screen = (v->angle_relativ_player_vertic + 360 - p->angle_vertic) * -21 + 540;
    else {
        v->y_to_screen = (v->angle_relativ_player_vertic - p->angle_vertic) * -21 + 540;
    }
}

void calcul_3D(Env_3d *env)
{
    for (int i = 0; i < env->nbr_vertices; i++) {
        get_angle_vertical(&env->vertices[i], env->camera);
        set_verticles_y_to_screen(&env->vertices[i], env->camera);
        get_angle_horizontal(&env->vertices[i], env->camera);
        set_vertices_x_to_screen(&env->vertices[i], env->camera);
    }
}
