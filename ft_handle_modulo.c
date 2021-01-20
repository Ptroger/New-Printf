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

void	ft_handle_modulo(struct s_val *val, struct s_opt *opt)
{
	val->width -= 1;
	if (!opt->negative)
	{
		if (opt->zero == '0')
		{
			while (val->width-- > 0)
				val->result += ft_putchar('0');
		}
		while (val->width-- > 0)
			val->result += ft_putchar(' ');
		if (!opt->negative)
			ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		while (val->width-- > 0)
			val->result += ft_putchar(' ');
	}
	reset_opt(val, opt);
}
