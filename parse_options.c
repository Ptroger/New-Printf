/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:41:28 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/10 17:41:53 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_after_width(const char *format, va_list tab, struct t_values *values, struct t_options *options) {
    char *str;
    int i;

    i = 0;
    str = (char *) malloc(64);
    if (format[values->index] == '.')
    {
        values->index += 1;
    }
    while (format[values->index] >= '0' && format[values->index] <= '9')
        str[i++] = format[values->index++];
    if (format[values->index] == '#')
    {
        options->dotHash = '#';
        values->precision = va_arg(tab, int);
    }
    if (options->dot != '#')
        values->precision = ft_atoi(str);
    free(str);
}

void		parse_options(const char *format, va_list tab, struct t_values *values, struct t_options *options)
{
    char    *str;
    int     i;

    i = 0;
    str = (char*)malloc(64);
    while (format[values->index] == '#' || format[values->index] == '-' || format[values->index] == '0')
    {
        if (format[values->index] == '#' && !options->hash)
            options->hash = '#';
        if (format[values->index] == '-' && !options->negative)
            options->negative = '-';
        if (format[values->index] == '0' && !options->zero)
            options->zero = '0';
        values->index += 1;
    }
    if (format[values->index] == '*')
    {
        options->wildcard = '*';
        values->index += 1;
        values->width += va_arg(tab, int);
    }
    while (format[values->index] >= '0' && format[values->index] <= '9')
        str[i++] = format[values->index++];
    str[i] = '\0';
    if (!options->wildcard)
        values->width = ft_atoi(str);
    free(str);
    parse_after_width(format, tab, values, options);
	return ;
}
