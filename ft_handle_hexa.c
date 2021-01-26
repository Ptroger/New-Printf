/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <ptroger@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:05:59 by pierre            #+#    #+#             */
/*   Updated: 2021/01/26 22:22:47 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_pre(struct s_val *val, struct s_opt *opt)
{
	if (!opt->negative && (val->precision < 0 || !opt->dot))
		val->width--;
	while (!opt->negative && val->width > 0 && val->width > val->precision)
	{
		val->width--;
		if (opt->zero && (!opt->dot || val->precision < 0))
			val->result += ft_putchar('0');
		else
			val->result += ft_putchar(' ');
	}
	if (val->precision < 0 || !opt->dot)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
}

void	handle_zero_hex(struct s_val *val, struct s_opt *opt)
{
	handle_pre(val, opt);
	while (val->precision > 0)
	{
		val->width--;
		val->result += ft_putchar('0');
		val->precision--;
	}
	while (opt->negative && val->width > 0 && val->width > val->precision)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
}

char	*ft_handle_x(const char format, va_list tab,
		struct s_val *val, struct s_opt *opt)
{
	char			*hex;
	unsigned int	nb;

	nb = va_arg(tab, unsigned int);
	if (nb == 0)
	{
		handle_zero_hex(val, opt);
		val->result--;
		return (NULL);
	}
	if (format == 'X')
		hex = ft_to_upper(ft_itoa_base(nb, 16));
	else
		hex = ft_itoa_base(nb, 16);
	return (hex);
}

char	*ft_handle_p(const char format, va_list tab,
		struct s_val *val, struct s_opt *opt)
{
	unsigned long nb;

	val->width -= 2;
	opt->hash = '#';
	nb = va_arg(tab, unsigned long);
	if (nb == 0)
	{
		if (opt->dot != '.')
			val->width--;
		handle_zero_zero(val, opt, format);
		return (NULL);
	}
	return (ft_itoa_base(nb, 16));
}

void	ft_handle_hexa(const char format, va_list tab,
		struct s_val *val, struct s_opt *opt)
{
	char *hex;

	if (format == 'X' || format == 'x')
		hex = ft_handle_x(format, tab, val, opt);
	else
		hex = ft_handle_p(format, tab, val, opt);
	if (!hex)
		return ;
	ft_handle_options(val, opt, hex, format);
	free(hex);
	reset_opt(val, opt);
}
