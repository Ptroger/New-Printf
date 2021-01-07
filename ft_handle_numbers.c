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

int		ft_handle_unsigned(int nb)
{
	if (nb < 0)
    {
		ft_putstr("4294967272");
		return (10);
	}
	ft_putnbr(nb);
	return (ft_strlen(ft_itoa(nb)));
}

int		ft_handle_numbers(const char format, va_list tab)
{
	int		i;
	int		nb;
	char	*str;

	nb = va_arg(tab, unsigned int);
	if (format == 'u')
		return (ft_handle_unsigned(nb) - 1);
	if (nb == -2147483648)
    {
	    ft_putstr("-2147483648");
	    return (10);
    }
	ft_putnbr(nb);
	str = ft_itoa(nb);
	i = ft_strlen(str);
	free(str);
	return (i - 1);
}
