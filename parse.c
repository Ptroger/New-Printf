/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:46:56 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/11 16:10:46 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		put_tab(const char *format, va_list tab)
{
	if (*format == 'c' || *format == 's')
	{
		return (ft_handle_char(*format, tab));
	}
	if (*format == 'd' || *format == 'i' || *format == 'u')
		return (ft_handle_numbers(*format, tab));
	//if (*format == '%')
	//	return (ft_handle_modulo(*format, tab));
	//if (*format == 'p' || *format == 'x' || *format == 'X')
	//	return (ft_handle_hexa(*format, tab));
	return (0);
}

char	getFlag(char format)
{
	int		i;
	char	*flags;
	char	c;

	flags = ft_strdup("cspdiuxX%");
	i = 0;
	while (flags[i])
	{
		if (format == flags[i])
		{
			c = flags[i];
			free(flags);
			flags = NULL;
			return ('c');
		}
		i++;
	}
	return ('e');
}

int		parse(const char *format, va_list tab)
{
	int			i;
	int			nb_flag;
	int			tab_len;

	nb_flag = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			nb_flag++;
			i++;
			if (getFlag(format[i]) == 'e')
				i += parse_options(format + i, tab);
			printf("\nI == %d\n", i);
			tab_len += put_tab(format + i, tab);
			i++;
			printf("\nformat[%d] == %c\n", i, format[i]);
		}
	}
	return (i - nb_flag + tab_len);
}

int		ft_printf(const char *format, ...)
{
	int			result;
	va_list		tab;
	char		*str;

	va_start(tab, format);
	result = parse((char*)format, tab);
	va_end(tab);
	return (result);
}
