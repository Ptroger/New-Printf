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

void	put_tab(const char *format, va_list tab, struct s_val *val,
	struct s_opt *opt)
{
	(void)tab;
	if (format[val->index] == 'c' || format[val->index] == 's')
		ft_handle_char(format[val->index], tab, val, opt);
	else if (format[val->index] == 'd' || format[val->index] == 'i' ||
	format[val->index] == 'u')
		ft_handle_numbers(format[val->index], tab, val, opt);
	else if (format[val->index] == '%')
		ft_handle_modulo(val, opt);
	else if (format[val->index] == 'p' || format[val->index] == 'x' ||
	format[val->index] == 'X')
		ft_handle_hexa(format[val->index], tab, val, opt);
}

int		get_opt(char c)
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

void	parse(const char *format, va_list tab, struct s_val *val,
	struct s_opt *opt)
{
	(void)tab;
	(void)opt;
	while (format[val->index])
	{
		if (format[val->index] == '%')
		{
			val->index++;
			if (get_opt(format[val->index]))
				parse_opt(format, tab, val, opt);
			if (get_flag(format[val->index]))
				put_tab(format, tab, val, opt);
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
	struct s_val	*val;
	struct s_opt	*opt;
	va_list			tab;

	opt = initialise_opt();
	val = initialise_val();
	if (!opt || !val)
		return (-1);
	va_start(tab, format);
	parse(format, tab, val, opt);
	va_end(tab);
	i = val->result;
	free(opt);
	free(val);
	return (i);
}
