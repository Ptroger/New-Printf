/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle-char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:18:35 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/11 15:06:44 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(const char format, va_list tab, struct t_val *val,
	struct t_opts *opts)
{
	if (format == 'c')
	{
		val->precision = 0;
		val->width -= 1;
		if (val->width > 0)
			ft_handle_opts(val, opts, "+");
		ft_putchar(va_arg(tab,
		int));
		while (val->width-- > 0 && opts->negative == '-')
			val->result += ft_putchar(' ');
		opts->negative = '\0';
		return ;
	}
	val->result += ft_putstr(va_arg(tab, char*), val, opts, format);
	reset_opts(val, opts);
	return ;
}
