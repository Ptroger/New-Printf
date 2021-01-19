/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:24:43 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/08 20:25:37 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_modulo(t_val *val, t_opts *opts)
{
	val->width -= 1;
	if (!opts->negative)
	{
		if (opts->zero == '0')
		{
			while (val->width-- > 0)
				val->result += ft_putchar('0');
		}
		while (val->width-- > 0)
			val->result += ft_putchar(' ');
		if (!opts->negative)
			ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		while (val->width-- > 0)
			val->result += ft_putchar(' ');
	}
	reset_opts(val, opts);
}
