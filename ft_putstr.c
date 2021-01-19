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

int		ft_putstr(char *str, struct t_val *val, struct t_opts *opts, const char format)
{
    if (!str)
        return (ft_putstr("(null)", val, opts, 's'));
	int	i;
    i = ft_strlen(str);
	if (format == 's' && opts->dot == '.' && val->precision >= 0 && val->precision < i)
        val->width = (val->width - i) + (i - val->precision);
	else if (opts->negative != '-')
	    val->width = (val->width - i);
    if (format == 's')
    {
		if (val->width > 0 || val->precision >= 0)
            ft_handle_opts(val, opts, str);
		if (opts->dot == '.' && val->precision >= 0 && val->precision < i)
        {
			write(1, str, val->precision);
            while (val->width-- > 0 && opts->negative == '-')
                val->result += ft_putchar(' ');
            opts->negative = '\0';
			return (val->precision -= 1);
        }
    }
    write(1, str, i);
    while (format == 's' && (val->width-- - i) > 0 && opts->negative == '-')
        val->result += ft_putchar(' ');
    if (format == 's')
        opts->negative = '\0';
	return (i - 1);
}
