#include "ft_printf.h"
#include <stdio.h>

int	main()
{
    void *i;
	char	c;
	char	*s;
  char *s2;
  unsigned int u = 24;

	s = "tat";
  s2 = "1234";
	c = '\n';
	i = &s;
	printf("printf == %d\n", printf("tontc%s%%18%s\n%p\n %u", s, s2, i, u));
	ft_printf("printf == %d\n", ft_printf("tontc%s%%18%s\n%p\n %u", s, s2, i, u));
}
