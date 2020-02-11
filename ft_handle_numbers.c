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

/*
int		ft_handle_signed(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		if (nb == INT_MIN)
		ft_putnbr(nb);
		return (ft_strlen(ft_itoa(nb)));
	}
}
*/
int		ft_handle_numbers(const char format, va_list tab)
{
	int		i;
	int		nb;
	char	*str;

//	if (format == 'i' || format == 'd')
//		return (ft_handle_signed(va_arg(tab, int)));
	nb = va_arg(tab, unsigned int);
	ft_putnbr(nb);
	str = ft_itoa(nb);
	i = ft_strlen(str);
	free(str);
	return (i);
}
