#include "my_printf.h"

char    *ft_strjoin_carac(char const *s1, char s2)
{
  char    *chaine;
  int             index;
  int             index2;

  index2 = 0;
  index = 0;
  if (!s1 || !s2)
    return (NULL);
  chaine = ft_memalloc(sizeof(char) * (ft_strlen(s1) + 10));
  if (chaine == NULL)
    return (NULL);
  while (s1[index] != '\0')
    {
      chaine[index] = s1[index];
      index++;
    }
  chaine[index] = s2;
  index++;
  index2++;
  chaine[index] = '\0';
  return (chaine);
}



int base_converter(t_main *main ,unsigned long long int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

  unsigned long long int converted_number[64];
 unsigned long long int number_to_convert = convert;
  int base;
  int index=0;

  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
      main->size++;
    }
  --index; 
  while(index >= 0)
    {
      main->print = ft_strjoin_carac(main->print, base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}

int base_converter_upper(t_main *main, unsigned long long int convert, int basee)
{
  char base_digits[16] =
    {'0', '1', '2', '3', '4', '5', '6', '7',
     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  unsigned long long int converted_number[64];
 unsigned long long int number_to_convert = convert;
  int base;
  int index=0;
  base = basee;
  while (number_to_convert != 0)
    {
      converted_number[index] = number_to_convert % base;
      number_to_convert = number_to_convert / base;
      ++index;
      main->size++;
    }
  --index;
  while(index >= 0)
    {
      main->print = ft_strjoin_carac(main->print, base_digits[converted_number[index]]);
      index--;
    }
  return (0);
}
