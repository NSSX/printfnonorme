#include "my_printf.h"
#include <wchar.h>


void second_mask(wint_t mycarac, t_main *main)
{
 	 unsigned char first;
   	 unsigned char second;

      first =  (unsigned char)(((mycarac & 0x07c0) >>6) + 0xC0);
      second = (unsigned char)((mycarac & 0x003F) + 0x80);
      main->print = ft_strjoin_carac(main->print, (char)first);
 	 main->print = ft_strjoin_carac(main->print, (char)second);
}

void three_mask(wint_t mycarac, t_main *main)
{
 	 unsigned char first;
   	 unsigned char second;
	unsigned char three;
    
  	first = (unsigned char)(((mycarac & 0xF000) >> 12) + 0xE0);
    second = (unsigned char)(((mycarac & 0x0FC0) >> 6) + 0x80);
    three = (unsigned char)((mycarac & 0x003F)+ 0x80);
    main->print = ft_strjoin_carac(main->print, (char)first);
 	 main->print = ft_strjoin_carac(main->print, (char)second);
   main->print =  ft_strjoin_carac(main->print, (char)three);
}

void four_mask(wint_t mycarac, t_main *main)
{
 	 unsigned char first;
   	 unsigned char second;
	unsigned char three;
    unsigned char four;

	first=(unsigned char)(0xF0 | mycarac >> 18);
  	second = (unsigned char)(((mycarac & 0xF000) >> 12) + 0xE0);
    three = (unsigned char)(((mycarac & 0x0FC0) >> 6) + 0x80);
   	four = (unsigned char)((mycarac & 0x003F)+ 0x80);
   main->print = ft_strjoin_carac(main->print, (char)first);
   main->print = ft_strjoin_carac(main->print, (char)second);
    main->print = ft_strjoin_carac(main->print, (char)three);
     main->print = ft_strjoin_carac(main->print, (char)four);
}



void mywchar(t_main *main, wint_t value)
{
	wint_t mycarac;

	mycarac = value;
	if(mycarac < 0x80)
	{
		if(main->accurate >= 0)
		{
			if((main->size + 1 <= main->accurate) || find(main,'C') == 1)
		{
			main->size += 1;
			main->print = ft_strjoin_carac(main->print, (char)mycarac);
		}
	}
		else
		{
			main->size += 1;
			main->print = ft_strjoin_carac(main->print, (char)mycarac);
		}
	}
	else if(mycarac < 0x800)
	{	if(main->accurate >= 0)
		{
		if((main->size + 2 <= main->accurate) || find(main,'C') == 1)
		{
			main->size += 2;
			second_mask(mycarac, main);
		}
	}
		else
		{
			main->size += 2;
			second_mask(mycarac, main);
		}
	}
	else if(mycarac < 0x10000)
	{
		if(main->accurate >= 0)
		{
			if((main->size + 3 <= main->accurate) || find(main,'C') == 1)
			{
				main->size += 3;
				three_mask(mycarac, main);
			}
		}
		else
		{
			main->size += 3;
				three_mask(mycarac, main);
		}
	}
	else if(mycarac < 0x200000)
	{	
	if(main->accurate >= 0)
		{
			if((main->size + 4 <= main->accurate) || find(main,'C') == 1)
		{
			main->size += 4;
			four_mask(mycarac, main);
		}
	}
		else
		{
				main->size += 4;
			four_mask(mycarac, main);
		}
	}
}