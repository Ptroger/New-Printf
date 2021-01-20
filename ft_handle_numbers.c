/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:27:29 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/08 20:23:32 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_neg(struct t_val *val, struct t_opts *opts, int nb,
	char *str)
{
	int i;

	i = ft_strlen(str);
	if (nb < 0)
		val->result += ft_putchar('-');
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

void	ft_handle_not_neg(struct t_val *val, struct t_opts *opts, int nb,
	char *str)
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
	if (nb < 0 && ft_atoi(str) != -2147483648)
		val->result += ft_putchar('-');
	while (val->width > val->precision && val->width > i)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
	while (val->precision-- > i)
		val->result += ft_putchar('0');
	val->result += ft_putstr(str, val, opts, 'd');
}

void	ft_handle_nb(struct t_val *val, struct t_opts *opts, int nb,
	char *str)
{
	if (nb < 0)
		val->width--;
	if (opts->negative != '-')
		ft_handle_not_neg(val, opts, nb, str);
	else if (opts->negative == '-')
		ft_handle_neg(val, opts, nb, str);
}

void	ft_handle_unsigned(unsigned int nb, struct t_val *val,
	struct t_opts *opts, const char format)
{
	char *str;

	if (nb == 0 && val->precision == 0 && opts->dot == '.')
	{
		handle_zero_zero(val, opts, format);
		val->result--;
		return ;
	}
	str = ft_unsigned_itoa(nb);
	ft_handle_nb(val, opts, 1, str);
	free(str);
	return ;
}

void	handle_zero_zero(struct t_val *val, struct t_opts *opts,
	const char format)
{
	if (format == 'p' && opts->negative)
	{
		if (opts->dot == '.')
			val->result += ft_putstr("0x", val, opts, format);
		else
			val->result += ft_putstr("0x0", val, opts, format);
	}
	while (val->width > 0)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
	if (format == 'p' && !opts->negative)
	{
		if (opts->dot == '.')
			val->result += ft_putstr("0x", val, opts, format);
		else
			val->result += ft_putstr("0x0", val, opts, format);
	}
	if (format == 'd' || format == 'i')
		val->result--;
}

char	*ft_handle_int(int nb)
{
	char	*str;
	int		neg;

	neg = 1;
	if (nb < 0)
		neg = -1;
	if (nb == -2147483648)
		str = ft_strdup("2147483648");
	else
		str = ft_itoa(nb * neg);
	return (str);
}

void	ft_handle_numbers(const char format, va_list tab, struct t_val *val,
	struct t_opts *opts)
{
	char	*str;
	int		neg;
	int		nb;

	neg = 1;
	if (format == 'u')
	{
		nb = va_arg(tab, unsigned int);
		ft_handle_unsigned(nb, val, opts, format);
		return ;
	}
	nb = va_arg(tab, int);
	if (nb == 0 && val->precision == 0 && opts->dot == '.')
		handle_zero_zero(val, opts, format);
	if (format == 'u' || (nb == 0 && val->precision == 0 && opts->dot == '.'))
		return ;
	if (nb < 0)
		neg = -1;
	str = ft_handle_int(nb);
	ft_handle_nb(val, opts, neg, str);
	free(str);
	reset_opts(val, opts);
}
