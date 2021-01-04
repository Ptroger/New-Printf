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

int	ft_handle_char(const char format, va_list tab)
{
	char	*str;

	if (format == 'c')
	{
		ft_putchar(va_arg(tab, int));
		return (0);
	}
	return (ft_putstr(va_arg(tab, char*)));
}
