#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	i;
	char	c;
	char	*s;
  char *s2;

	s = "tat";
  s2 = "1234";
	c = '\n';
	i = 0;
	printf("printf == %d\n", printf("tontc%s%%18%s%d", s, s2, i));
	ft_printf("printf == %d\n", ft_printf("tontc%s%%18%s%d", s, s2, i));
}
