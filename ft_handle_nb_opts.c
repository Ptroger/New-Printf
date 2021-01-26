/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nb_opts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <ptroger@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:06:11 by pierre            #+#    #+#             */
/*   Updated: 2021/01/21 13:06:12 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_neg(struct s_val *val, struct s_opt *opt, int nb,
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
	val->result += ft_putstr(str, val, opt, 'd');
	while (val->width - i > 0)
	{
		val->width--;
		val->result += ft_putchar(' ');
	}
	opt->negative = '\0';
}

void	ft_handle_not_neg(struct s_val *val, struct s_opt *opt, int nb,
		char *str)
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
	if (nb < 0 && ft_atoi(str) != -2147483648)
		val->result += ft_putchar('-');
	while (val->width > val->precision && val->width > i)
	{
		val->width--;
		val->result += ft_putchar('0');
	}
	while (val->precision-- > i)
		val->result += ft_putchar('0');
	val->result += ft_putstr(str, val, opt, 'd');
}

void	ft_handle_nb(struct s_val *val, struct s_opt *opt, int nb,
		char *str)
{
	if (nb < 0)
		val->width--;
	if (opt->negative != '-')
		ft_handle_not_neg(val, opt, nb, str);
	else if (opt->negative == '-')
		ft_handle_neg(val, opt, nb, str);
}
