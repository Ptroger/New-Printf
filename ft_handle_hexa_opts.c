#include "ft_printf.h"

void	ft_handle_hash(struct s_val *val, struct s_opt *opt,
		const char format)
{
	val->width += 2;
	if (format == 'x' || format == 'p')
		val->result += (ft_putstr("0x", val, opt, 'x') + 1);
	else
		val->result += (ft_putstr("0X", val, opt, 'x') + 1);
}

void	ft_handle_negative(struct s_val *val, struct s_opt *opt,
		char *str, const char format)
{
	int i;

	i = ft_strlen(str);
	if (opt->zero != '0' || (opt->dot == '.' && val->precision >= 0))
	{
		while (val->width > val->precision && val->width > i)
		{
			val->result += ft_putchar(' ');
			val->width--;
		}
	}
	if (opt->hash == '#')
		ft_handle_hash(val, opt, format);
	while (val->width > val->precision && val->width > i)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
	while (val->precision-- > i)
		val->result += ft_putchar('0');
	val->result += ft_putstr(str, val, opt, 'd');
}

void	ft_handle_not_negative(struct s_val *val, struct s_opt *opt,
							char *str, const char format)
{
	int i;

	i = ft_strlen(str);
	if (opt->hash == '#')
	{
		if (format == 'x' || format == 'p')
			val->result += (ft_putstr("0x", val, opt, 'x') + 1);
		else
			val->result += (ft_putstr("0X", val, opt, 'x') + 1);
	}
	while (val->precision > i)
	{
		val->width--;
		val->precision--;
		val->result += ft_putchar('0');
	}
	val->result += ft_putstr(str, val, opt, 'd');
	while (val->width - i > 0)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
	opt->negative = '\0';
}

void	ft_handle_options(struct s_val *val, struct s_opt *opt, char *str,
					   const char format)
{
	if (format != 'p' && opt->hash == '#')
		val->width -= 2;
	if (opt->negative != '-')
		ft_handle_negative(val, opt, str, format);
	else if (opt->negative == '-')
		ft_handle_not_negative(val, opt, str, format);
}