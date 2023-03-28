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

typedef struct Element Element;
typedef struct Element {
    char ligne[10000];
    Element *suivant;
} Element;

typedef struct liste liste;
typedef struct liste {
    Element *premier;
    Element *dernier;
} liste;

typedef struct shell {
    char real_path[100];
    char **array;
} shell;

int my_printf(const char *format, ...);
int my_show_word_array(char * const *tab);
void my_putchar(char c);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
void my_puterror(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
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
char **my_str_to_word_array(char *str, char delimiter);
int my_len_of_array(char **tab);
void reduce_len_of_str(char *dest, char *src, int reduce);
void free_array(char **array, int size);
int my_strcmplen(char const *s1, char const *s2, int len);
void my_memset(char *buffer, char character, int len);
char **copy_array(char **array);

#endif
