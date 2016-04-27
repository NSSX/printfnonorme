#include "my_printf.h"

void parsing(t_main *main)
{
  int i ;
 
  i = main->i;
 while(main->chaine[i] == '+' || main->chaine[i] == '-' || main->chaine[i] == '#' || main->chaine[i] == ' ')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  while(main->chaine[i] <= '9' && main->chaine[i] >= '0')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  if(main->chaine[i] == '.')
    {
     main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
  while(main->chaine[i] <= '9' && main->chaine[i] >= '0')
    {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
    }
   while(main->chaine[i] == 'l' || main->chaine[i] == 'h' || main->chaine[i] == 'j' || main->chaine[i] == 'z')
   {
      main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
      i++;
   }
  main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
}

int anothertry(t_main *main)
{
  int i;

  i = 0;
  while(main->parsed[i] == ' ')
    {
      i++;
    }
  if(main->parsed[i] == '%')
    {
      return(1);
    }
  return(0);
}

int spacenoplus(t_main *main)
{
  int i;

  i = 0;
  while(main->parsed[i] != '\0')
  {
    if(main->parsed[i] == '+')
      return(0);
    i++;
  }
return (1);
}

int no_conv(t_main *main)
{
  char *flag;
  int i;

  i = 0;
  flag = "sSpdDioOuUxXcC";
  while(flag[i] != '\0')
  {
    if(find(main, flag[i]) == 1)
    {
      return(0);
    }
    i++;
  }
  return (1);
}

int flag_fiel(t_main *main, va_list *myva)
{
  main->i++;
  parsing(main);
   if(main->chaine[main->i] == '0')
    {
      main->zeroetat = 1;
      flag_fiel(main, myva);
    }
  if(main->chaine[main->i] == '+')
    {
      int i;
      int etat;

      etat = 0;
      i = 0;
      while(main->parsed[i] != '\0')
        {
          if(main->parsed[i] == 'u' || main->parsed[i] == 'c')
            {
              etat = 1;
            }
          i++;
        }
      if((int)main->elem >= 0 && etat == 0 && main->plusetat != 1 && find(main, 'C') == 0 && find(main, 'o') == 0 && find(main, 'O') == 0 && find(main, 's') == 0 && find(main, 'p') == 0 && find(main, 'x') == 0 && find(main, 'X') == 0)
        {
          main->taille++;
          main->size++;
	  //          main->print = ft_strjoin(main->print, "+");
	      main->plusetat = 1;
        }
      flag_fiel(main, myva);
    }
  else if(main->chaine[main->i] == '#')
    {
      main->dietat = 1;
      flag_fiel(main, myva);
    }
  else if(main->chaine[main->i] == '-')
    {
      main->moinetat = 1;
      flag_fiel(main, myva);
    }
  else if(main->chaine[main->i] == '*')
    {
      main->etoile = 1;
      main->width = (int)main->elem;
    if(main->width < 0)
    {
      main->moinetat = 1;
    }
     main->elem = va_arg(*myva, void *);

     flag_fiel(main, myva);
   }
  else if(main->chaine[main->i] == ' ')
    {
      if(no_conv(main) == 1 && find(main,'%') == 0)
      {
        return (0);
      }
      int i;
      int etat;
     
      etat = 0;
      i = 0;
      while(main->parsed[i] != '\0')
  	 {
      	  if(main->parsed[i] == 'u' || main->parsed[i] == 'c')
      	    {
      	      etat = 1;
      	    }
      	  i++;
	     }
      if((int)main->elem >= 0 && etat == 0 && anothertry(main) == 0)
        {
          if(spacenoplus(main) == 1)
          {
                if(find(main,'p') == 0 && find(main,'o') == 0 && find(main,'x') == 0 && find(main,'X') == 0 && find(main,'s') == 0 && find(main,'C') == 0 && find(main,'S') == 0 )
                {
            main->taille++;
            main->size++;
              main->print = ft_strjoin(main->print, " ");
	        }
           }
      while(main->chaine[main->i + 1] == ' ')
	    {
	      main->i++;
	    }
        }
      flag_fiel(main, myva);
    }
  else
    main->i--;
  return (0);
}
