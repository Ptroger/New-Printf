/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opt.c                                    	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:41:28 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/10 17:41:53 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_after_width(const char *format, va_list tab,
		struct s_val *val, struct s_opt *opt)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(64);
	if (format[val->index] == '.')
	{
		opt->dot = '.';
		val->index += 1;
	}
	while (format[val->index] >= '0' && format[val->index] <= '9')
		str[i++] = format[val->index++];
	str[i] = '\0';
	if (format[val->index] == '*')
	{
		opt->dothash = '*';
		val->precision = va_arg(tab,
		int);
		val->index += 1;
	}
	if (opt->dothash != '*')
		val->precision = ft_atoi(str);
	free(str);
}

void	fill_opt(const char *format, va_list tab, struct s_val *val,
		struct s_opt *opt)
{
	while (format[val->index] == '#' || format[val->index] == '-'
	|| format[val->index] == '0')
	{
		if (format[val->index] == '#' && opt->hash != '#')
			opt->hash = '#';
		if (format[val->index] == '-' && !opt->negative)
			opt->negative = '-';
		if (format[val->index] == '0' && !opt->zero)
			opt->zero = '0';
		val->index += 1;
	}
	if (format[val->index] == '*')
	{
		opt->wildcard = '*';
		val->index += 1;
		val->width += va_arg(tab,
		int);
		if (val->width < 0)
		{
			opt->negative = '-';
			val->width *= -1;
		}
	}
}

void	parse_opt(const char *format, va_list tab, struct s_val *val,
				struct s_opt *opt)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(64);
	fill_opt(format, tab, val, opt);
	while (format[val->index] >= '0' && format[val->index] <= '9')
		str[i++] = format[val->index++];
	str[i] = '\0';
	if (!opt->wildcard)
		val->width = ft_atoi(str);
	free(str);
	parse_after_width(format, tab, val, opt);
}
