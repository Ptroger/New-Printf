#include "ft_printf.h"

int	ft_handle_opt(struct s_val *val, struct s_opt *opt, char *str)
{
	int	neg;

	neg = 0;
	if (opt->negative == '\0')
	{
		if (opt->zero == '0' && (opt->dot != '.' || val->precision < 0))
		{
			if (str[0] == '-')
			{
				val->result += ft_putchar('-');
				neg = 1;
			}
			while (val->width > 0)
			{
				val->result += ft_putchar('0');
				val->width--;
			}
			opt->zero = '\0';
		}
		while (val->width-- > 0)
			val->result += ft_putchar(' ');
	}
	return (neg);
}
