#include "ft_printf.h"
#include "stdio.h"

void	ft_handle_hash(struct t_val *val, struct t_opts *opts,
	const char format)
{
	val->width += 2;
	if (format == 'x' || format == 'p')
		val->result += (ft_putstr("0x", val, opts, 'x') + 1);
	else
		val->result += (ft_putstr("0X", val, opts, 'x') + 1);
}

void	ft_handle_negative(struct t_val *val, struct t_opts *opts,
	char *str, const char format)
{
	int i;

	i = ft_strlen(str);
	if (opts->zero != '0' || (opts->dot == '.' && val->precision >= 0))
	{
		while (val->width > val->precision && val->width > i)
		{
			val->result += ft_putchar(' ');
			val->width--;
		}
	}
	if (opts->hash == '#')
		ft_handle_hash(val, opts, format);
	while (val->width > val->precision && val->width > i)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
	while (val->precision-- > i)
		val->result += ft_putchar('0');
	val->result += ft_putstr(str, val, opts, 'd');
}

void	ft_handle_not_negative(struct t_val *val, struct t_opts *opts,
	char *str, const char format)
{
	int i;

	i = ft_strlen(str);
	if (opts->hash == '#')
	{
		if (format == 'x' || format == 'p')
			val->result += (ft_putstr("0x", val, opts, 'x') + 1);
		else
			val->result += (ft_putstr("0X", val, opts, 'x') + 1);
	}
	while (val->precision > i)
	{
		val->width--;
		val->precision--;
		val->result += ft_putchar('0');
	}
	val->result += ft_putstr(str, val, opts, 'd');
	while (val->width - i > 0)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
	opts->negative = '\0';
}

void	ft_handle_options(struct t_val *val, struct t_opts *opts, char *str,
	const char format)
{
	if (format != 'p' && opts->hash == '#')
		val->width -= 2;
	if (opts->negative != '-')
		ft_handle_negative(val, opts, str, format);
	else if (opts->negative == '-')
		ft_handle_not_negative(val, opts, str, format);
}

char	*ft_to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		i++;
	}
	return (str);
}

void	handle_pre(struct t_val *val, struct t_opts *opts)
{
	if (!opts->negative && (val->precision < 0 || !opts->dot))
		val->width--;
	while (!opts->negative && val->width > 0 && val->width > val->precision)
	{
		val->width--;
		if (opts->zero && (!opts->dot || val->precision < 0))
			val->result += ft_putchar('0');
		else
			val->result += ft_putchar(' ');
	}
	if (val->precision < 0 || !opts->dot)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
}

void	handle_zero_hex(struct t_val *val, struct t_opts *opts)
{
	handle_pre(val, opts);
	while (val->precision > 0)
	{
		val->width--;
		val->result += ft_putchar('0');
		val->precision--;
	}
	while (opts->negative && val->width > 0 && val->width > val->precision)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
}

char	*ft_handle_x(const char format, va_list tab, t_val *val, t_opts *opts)
{
	char			*hex;
	unsigned int	nb;

	nb = va_arg(tab, unsigned int);
	if (nb == 0)
	{
		handle_zero_hex(val, opts);
		val->result--;
		return (NULL);
	}
	if (format == 'X')
		hex = ft_to_upper(ft_itoa_base(nb, 16));
	else
		hex = ft_itoa_base(nb, 16);
	return (hex);
}

char	*ft_handle_p(const char format, va_list tab, t_val *val, t_opts *opts)
{
	unsigned long nb;

	val->width -= 2;
	opts->hash = '#';
	nb = va_arg(tab, unsigned long);
	if (nb == 0)
	{
		if (opts->dot != '.')
			val->width--;
		handle_zero_zero(val, opts, format);
		return (NULL);
	}
	return (ft_itoa_base(nb, 16));
}

void	ft_handle_hexa(const char format, va_list tab, t_val *val, t_opts *opts)
{
	char *hex;

	if (format == 'X' || format == 'x')
		hex = ft_handle_x(format, tab, val, opts);
	else
		hex = ft_handle_p(format, tab, val, opts);
	if (!hex)
		return ;
	ft_handle_options(val, opts, hex, format);
	free(hex);
	reset_opts(val, opts);
}
