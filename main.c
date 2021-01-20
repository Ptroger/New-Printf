#include "ft_printf.h"
#include <stdio.h>

int	main()
{
    int d;
	char	c;
	char	*s;
  void *p;
  unsigned int u = 0;

  p = &c;
  s = (char*)malloc(4);
    s = "tw";
	c = '\n';
	d = -2147483648;
//    printf("printf == %d\n", printf("%-2c%-3c%-4c%-1c\n", 'q', 'q', 'q', 'q'));
//    printf("printf == %d\n", printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31));
//    printf("printf == %d\n", ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31));
//    ft_printf("123%*i", 10, 1);
    printf("printf == %d \n", printf("-->|%-4.*d|<--\n", 4, d));
    printf("ftintf == %d \n", ft_printf("-->|%-4.*d|<--\n", 4, d));
//printf("printf == %d\n", printf("%c", (char)58));
//printf("ft_printf == %d\n", ft_printf("%c", (char)58));:w

}
