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

void		ft_handle_unsigned(int nb, struct t_values *values, struct t_options *options)
{
    char    *str;
	if (nb < 0)
    {
		ft_putstr("4294967272");
        values->result += 10;
        return ;
	}
	ft_putnbr(nb);
	str = ft_itoa(nb);
	values->result += 1;
	free(str);
	return ;
}

void        ft_handle_numbers(const char format, va_list tab, struct t_values *values, struct t_options *options)
{
	int		i;
	int		nb;
	char	*str;

	if (format == 'u')
	{
        nb = va_arg(tab, unsigned int);
        ft_handle_unsigned(nb, values, options);
        return ;
    }
    nb = va_arg(tab, int);
    if (nb == -2147483648)
    {
	    ft_putstr("-2147483648");
	    values->result += 10;
	    return ;
    }
	ft_putnbr(nb);
	str = ft_itoa(nb);
	values->result += ft_strlen(str);
	free(str);
	return ;
}
