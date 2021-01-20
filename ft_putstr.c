/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:36:13 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/11 14:08:54 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	first_checks(char *str, const char format, struct s_val *val,
	struct s_opt *opt)
{
	int i;

	i = ft_strlen(str);
	if (format == 's' && opt->dot == '.' && val->precision >= 0 &&
		val->precision < i)
		val->width = (val->width - i) + (i - val->precision);
	else if (opt->negative != '-')
		val->width = (val->width - i);
	if (format == 's')
	{
		if (val->width > 0 || val->precision >= 0)
			ft_handle_opt(val, opt, str);
		if (opt->dot == '.' && val->precision >= 0 && val->precision < i)
		{
			write(1, str, val->precision);
			while (val->width-- > 0 && opt->negative == '-')
				val->result += ft_putchar(' ');
			opt->negative = '\0';
		}
	}
}

int		ft_putstr(char *str, struct s_val *val, struct s_opt *opt,
	const char format)
{
	int i;

	if (!str)
		return (ft_putstr("(null)", val, opt, 's'));
	i = ft_strlen(str);
	first_checks(str, format, val, opt);
	if (format == 's')
	{
		if (opt->dot == '.' && val->precision >= 0 && val->precision < i)
			return (val->precision -= 1);
	}
	write(1, str, i);
	while (format == 's' && (val->width-- - i) > 0 && opt->negative == '-')
		val->result += ft_putchar(' ');
	if (format == 's')
		opt->negative = '\0';
	return (i - 1);
}
