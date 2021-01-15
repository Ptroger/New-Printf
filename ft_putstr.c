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

void     ft_handle_precision(int i, struct t_values *values, struct t_options *options)
{
    values->precision -= i;
    while(values->width-- > values->precision)
        values->result += ft_putchar(' ');
    values->width = 0;
    while(values->precision-- > 0)
        values->result += ft_putchar('0');
    values->precision = -1;
}

int		ft_putstr(char *str, struct t_values *values, struct t_options *options, const char format)
{
	int	i;

	i = ft_strlen(str);
    values->width -= i;
    if (values->precision >= i)
        ft_handle_precision(i, values, options);
    if (values->width > 0 || values->precision >= 0)
        ft_handle_options(values, options);
    if (format == 's')
    {
        if (options->dot == '.' && values->precision != -1)
        {
            write(1, str, values->precision);
            return (values->precision);
        }
    }
	write(1, str, i);
	return (i - 1);
}
