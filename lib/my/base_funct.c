/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** va_arg
*/

#include <dirent.h>
#include <stdarg.h>
#include "my.h"

int my_get_nbr_2(int nb)
{
    int compteur = 0;
    if (nb >= -2147483647 && nb < 0) {
        compteur++;
        nb = nb * (- 1);
    }
    if (nb < -2147483647 || nb > 2147483647){
        compteur++;
        return compteur;
    }
    if (nb > 0 && nb <= 2147483647) {
        compteur ++;
        compteur += my_get_nbr_2(nb / 10);
    }
    return compteur;
}

void str_str(const char *format, va_list list, int *i, int *count)
{
    (void) format;
    char *a = va_arg(list, char*);
    my_putstr(a);
    *count += my_strlen(a);
    *i = *i + 1;
}

void str_char(const char *format, va_list list, int *i, int *count)
{
    (void) format;
    (void) list;
    my_putchar(va_arg(list, int));
    *i = *i + 1;
    ++*count;
}

void str_mod(const char *format, va_list list, int *i, int *count)
{
    (void) list;
    my_putchar('%');
    if (format[*i - 1] == '%')
        ++*i;
    ++*i;
    ++*count;
}

void str_int(const char *format, va_list list, int *i, int *count)
{
    (void) format;
    int b = va_arg(list, int);
    if (b == 0)
        my_putstr("0");
    else
        my_put_nbr(b);
    *count += my_get_nbr_2(b);
    *i = *i + 1;
}
