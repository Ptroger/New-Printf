#include "ft_printf.h"
#include <stdio.h>

int	main()
{
    unsigned long i;
	char	c;
	char	*s;
  char *s2;
  unsigned int u = 10;

  s = (char*)malloc(4);
    s = "tat";
    s2 = "oot";
	c = '\n';
	i = -489102481204;
//    printf("printf == %d\n", printf("123%*0*%", 15));
//    ft_printf("printf == %d\n", ft_printf("123%*i", 10, 1));
    ft_printf("123%*i", 10, 1);
}
