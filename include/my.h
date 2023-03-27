/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-ulysse.rousselet
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define PI 3.14159
    #include <signal.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ucontext.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <math.h>

typedef struct Vertices {
    int x;
    int y;
    int z;
    double angle_relativ_player_hori;
    double angle_relativ_player_vertic;
    int x_to_screen;
    int y_to_screen;
} Vertices;

typedef struct Player {
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
} Player;

typedef struct env {
    Player *player;
    Vertices *vertices;
    sfVector2i middle_of_screen;
    sfConvexShape *plateform[2];
    int nbr_vertices;
} env;

int my_printf(const char *format, ...);
int my_show_word_array(char * const *tab);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_get_nbr_2(int nb);
void str_str(const char *format, va_list list, int *i, int *count);
void str_int(const char *format, va_list list, int *i, int *count);
void str_char(const char *format, va_list list, int *i, int *count);
void str_unsint(const char *format, va_list list, int *i, int *count);
void str_mod(const char *format, va_list list, int *i, int *count);
void str_oct(const char *format, va_list list, int *i, int *count);
void str_bin(const char *format, va_list list, int *i, int *count);
void str_hex(const char *format, va_list list, int *i, int *count);
void str_hex2(const char *format, va_list list, int *i, int *count);
void str_e(const char *format, va_list list, int *i, int *count);
void str_float(const char *format, va_list list, int *i, int *count);
void str_g(const char *format, va_list list, int *i, int *count);
int my_put_unsnbr(unsigned int nb);
int my_put_nbr_virgule(int nb, int virgule);
void str_n(const char *format, va_list list, int *i, int *count);
void str_p(const char *format, va_list list, int *i, int *count);
int type_zero(const char *format, int *i);
int type_plus(const char *format, int *i);
int type_moin(const char *format, int *i);
int type_space(const char *format, int *i);
int type_hashtag(const char *format, int *i);
void str_e2(const char *format, va_list list, int *i, int *count);
void str_float2(const char *format, va_list list, int *i, int *count);
void str_m(const char *format, va_list list, int *i, int *count);
char **malloc_2d_array(int y, int x);
void set_up(env *env, Player *player);
void event_fct(sfRenderWindow *window, sfEvent event, env *env);
void create_line(env *env);
void get_angle_horizontal(Vertices *v, Player *p);
void set_vertices_x_to_screen(Vertices *v, Player *p);
void get_angle_vertical(Vertices *v, Player *p);
void set_verticles_y_to_screen(Vertices *v, Player *p);
void set_convex_shap(env *env, sfRenderWindow *window);

#endif
