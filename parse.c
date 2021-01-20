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

void	put_tab(const char *format, va_list tab, struct t_val *val,
	struct t_opts *opts)
{
	(void)tab;

	if (format[val->index] == 'c' || format[val->index] == 's')
		ft_handle_char(format[val->index], tab, val, opts);
	else if (format[val->index] == 'd' || format[val->index] == 'i' ||
	format[val->index] == 'u')
		ft_handle_numbers(format[val->index], tab, val, opts);
	else if (format[val->index] == '%')
		ft_handle_modulo(val, opts);
	else if (format[val->index] == 'p' || format[val->index] == 'x' ||
	format[val->index] == 'X')
		ft_handle_hexa(format[val->index], tab, val, opts);
}

int		get_opts(char c)
{
	if (c == '#' || c == '-' || c == '*' || c == '.' || ft_isdigit(c))
		return (1);
	else
		return (0);
}

char	get_flag(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

void	parse(const char *format, va_list tab, struct t_val *val,
	struct t_opts *opts)
{
	(void)tab;
	(void)opts;

	while (format[val->index])
	{
		if (format[val->index] == '%')
		{
			val->index++;
			if (get_opts(format[val->index]))
				parse_opts(format, tab, val, opts);
			if (get_flag(format[val->index]))
				put_tab(format, tab, val, opts);
		}
		else
			ft_putchar(format[val->index]);
		val->index += 1;
		val->result += 1;
	}
}

int		ft_printf(const char *format, ...)
{
	int				i;
	struct t_val	*val;
	struct t_opts	*opts;
	va_list			tab;

	opts = initialise_opts();
	val = initialise_val();
	if (!opts || !val)
		return (-1);
	va_start(tab, format);
	parse(format, tab, val, opts);
	va_end(tab);
	i = val->result;
	free(opts);
	free(val);
	return (i);
}
