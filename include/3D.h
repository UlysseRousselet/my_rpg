/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-ulysse.rousselet
** File description:
** my.h
*/

#define PI 3.14159
#define MIDSCREENX 960
#define MIDSCREENY 540
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ucontext.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct Vertices {
    int x;
    int y;
    int z;
    double angle_relativ_player_hori;
    double angle_relativ_player_vertic;
    int x_to_screen;
    int y_to_screen;
} Vertices;

typedef struct Camera_3d {
    int last_mouse_pos_x;
    int last_mouse_pos_y;
    int sensivity;
    double angle_horiz;
    double angle_vertic;
    double x;
    double y;
    double z;
    int avancer;
    int reculer;
    int droite;
    int gauche;
    int monter;
    int descendre;
} Camera_3d;

typedef struct Env_3d {
    Camera_3d *camera;
    Vertices *vertices;
    sfVector2i middle_of_screen;
    sfConvexShape *plateform[2];
    sfConvexShape *sky_box;
    sfVector2f sky_box_size;
    int nbr_vertices;
} Env_3d;
