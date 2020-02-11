#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	i;
	char	c;
	char	*s;

	s = "tata";
	c = '\n';
	i = 0;
	printf("printf == %d\n", printf("tontc%s", s));
}
