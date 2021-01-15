#include "ft_printf.h"
#include <stdio.h>

int	main()
{
    unsigned int i;
	char	c;
	char	*s;
  char *s2;
  unsigned int u = 10;

  s = (char*)malloc(4);
    s = NULL;
    s2 = "oot";
	c = '\n';
	i = 1564;
    printf("printf == %d\n", printf("123%-4.5d\n", i));
    ft_printf("ft_printf == %d\n", ft_printf("123%4.5d\n", i));
//    ft_printf("123%*i", 10, 1);
}
