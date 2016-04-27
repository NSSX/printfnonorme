#include "my_printf.h"

int my_accurate(t_main *main, va_list *myva)
{
  main->i++;

  int i;
  int size;
  int i2;
  char *myacc;

  i = 0;
  i2 = 0;
  if(main->chaine[main->i] == '.')
    {
      main->pointetat = 1;
      if(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
        {
          i = main->i + 1;
          while(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
            {
              main->i++;
            }
          size = main->i - i;
          myacc = (char *)malloc(sizeof(char) * size + 10);
          while(i <= main->i)
            {
              myacc[i2] = main->chaine[i];
              i2++;
              i++;
            }
          myacc[i2] = '\0';
          main->accurate = ft_atoi(myacc);
          free(myacc);
        }
      else if(main->chaine[main->i + 1] == '*')
        {
          main->i++;
          main->accurate = (int)main->elem;
          main->elem = va_arg(*myva, void *);
        }
      else
      {
	     main->accurate = 0;
      }
      my_accurate(main, myva);
    }
  else
    main->i--;
  return (0);
}
