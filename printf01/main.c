  #include "my_printf.h"
  #include <wchar.h>
  #include <locale.h>
  //SpdDoOuUxXcC
  int main()
  {
    int res1;
    int res2;

    setlocale(LC_ALL,"");
    res1 = 0;
    res2 = 0;

    printf("VRAI PRINTF : \n");
    res1 = printf("%   %", "test");
    printf("\n");
    printf("MON PRINTF : \n");
    res2 = ft_printf("%   %", "test");
    ft_putstr("\nret 1 : ");
    ft_putnbr(res1);
    ft_putstr("\nret 2 : ");
    ft_putnbr(res2);
    return (0);
  }

