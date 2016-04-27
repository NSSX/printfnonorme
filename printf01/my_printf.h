#ifndef MY_PRINTF_H
#define MY_PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <wchar.h>
  /*
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define LONG_MAX 2147483647
#define LONG_MIN -2147483648
#define SHORT_MAX 32767
#define SHORT_MIN -32768*/
typedef struct s_main
{
  int i;
  const char *chaine;
  int nb;
  int taille;
  void *elem;
  int signemoin;
  int casc;
  int pointetat;
  int type;
  char conv;
  int etoile;
  int etat;
  int dietat;
  int plusetat;
  int accurate;
  int width;
  int moinetat;
  int zeroetat;
  int mini;
  char *parsed;
  char *print;
  int size;
  int sizeword;
  int totalsize;
}t_main;

int no_conv(t_main *main);
void parsing(t_main *main);
void mywchar(t_main *main, wint_t value);
char                    *my_utoa(unsigned long long int n);
char                    *my_itoa(long long int n);
char    *ft_strjoin_carac(char const *s1, char s2);
int manage_arg(t_main *main);
int base_converter(t_main *main, unsigned long long int convert, int basee);
int base_converter_upper(t_main *main, unsigned long long int convert, int basee);
int ft_printf(const char *format, ...);
int add_mini(t_main *main);
int my_width(t_main *main, va_list *myva);
int flag_fiel(t_main *main, va_list *myva);
int my_accurate(t_main *main, va_list *myva);
int lenght_fiel(t_main *main);
int find(t_main *main, char tofind);
#endif
