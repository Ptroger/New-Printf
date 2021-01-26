/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:18:35 by ptroger           #+#    #+#             */
/*   Updated: 2021/01/21 13:05:52 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(const char format, va_list tab, struct s_val *val,
	struct s_opt *opt)
{
	if (format == 'c')
	{
		val->precision = 0;
		val->width -= 1;
		if (val->width > 0)
			ft_handle_opt(val, opt, "+");
		ft_putchar(va_arg(tab,
		int));
		while (val->width-- > 0 && opt->negative == '-')
			val->result += ft_putchar(' ');
		opt->negative = '\0';
		return ;
	}
	val->result += ft_putstr(va_arg(tab, char*), val, opt, format);
	reset_opt(val, opt);
	return ;
}
