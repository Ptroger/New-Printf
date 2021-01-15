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

void	ft_handle_char(const char format, va_list tab, struct t_values *values, struct t_options *options)
{
	if (format == 'c')
	{
        values->precision = 0;
        values->result += 1;
        values->width -= 1;
        if (values->width > 0)
            ft_handle_options(values, options);
        ft_putchar(va_arg(tab, int));
        return ;
	}
    values->result += ft_putstr(va_arg(tab, char*), values, options, format);
    return ;
}
