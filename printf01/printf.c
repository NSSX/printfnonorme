#include "my_printf.h"

void init_main(t_main *main)
{
//  main->print = (char *)malloc(sizeof(char) * 10);
  main->print = ft_memalloc(sizeof(char) * 10);
//  main->parsed = (char *)malloc(sizeof(char) * 10);
  main->parsed = ft_memalloc(sizeof(char) * 10);
  main->accurate = -1;
  main->width = 0;
  main->mini = 0;
  main->taille = 0;
  main->signemoin = 0;
  main->pointetat = 0;
  main->etat = 0;
  main->size = 0;
  main->conv ='t';
  main->type = 0;
  main->moinetat = 0;
  main->casc = 0;
  main->dietat = 0;
  main->zeroetat = 0;
  main->plusetat = 0;
  main->etoile = 0;
}

int ft_printf(const char *format, ...)
{
  va_list myva;
  t_main *main;

  main = (t_main *)malloc(sizeof(t_main) * 10); 
  main->sizeword = 0;
  main->i = 0;
  main->totalsize = 0;
  main->chaine = format;
  //initializzzzzze VA  
  va_start(myva, format); 
  while(format[main->i] != '\0')
    {
      if(format[main->i] != '%')
	{
	  ft_putchar(format[main->i]);
	  main->sizeword++;
	  //  main->i++;
	}      
      else if(format[main->i + 1] != '\0')
  	{
  	  init_main(main);
  	  if(main->chaine[main->i + 1] != '%')
  	    main->elem = va_arg(myva, void *); 
  	  flag_fiel(main, &myva);
  	  my_width(main, &myva);
  	  my_accurate(main, &myva);
  	  lenght_fiel(main);
  	  manage_arg(main);
  	  add_mini(main);
  	  ft_putstr(main->print);
  	   if(main->casc == 1)
        write(1, "\0",1);
      main->totalsize += main->size;
	 }
      main->i++;
  }
  //END de mon VA
  va_end(myva);
  main->totalsize += main->sizeword;
  return (main->totalsize);
}
