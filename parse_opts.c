/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:41:28 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/10 17:41:53 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_after_width(const char *format, va_list tab, struct t_val *val, struct t_opts *opts) {
    char *str;
    int i;


    i = 0;
    str = (char *) malloc(64);
    if (format[val->index] == '.')
    {
        opts->dot = '.';
        val->index += 1;
    }
    while (format[val->index] >= '0' && format[val->index] <= '9') {
        str[i++] = format[val->index++];
    }
    str[i] = '\0';
    if (format[val->index] == '*')
    {
        opts->dotHash = '*';
        val->precision = va_arg(tab, int);
        val->index += 1;
    }
    if (opts->dotHash != '*')
        val->precision = ft_atoi(str);
    free(str);
}

void		parse_opts(const char *format, va_list tab, struct t_val *val, struct t_opts *opts)
{
    char    *str;
    int     i;

    i = 0;
    str = (char*)malloc(64);

//	printf("\nici = %d\n", val->index);
//	printf("\nici = %c\n", format[val->index]);
	while (format[val->index] == '#' || format[val->index] == '-' || format[val->index] == '0')
    {
        if (format[val->index] == '#' && opts->hash != '#')
            opts->hash = '#';
        if (format[val->index] == '-' && !opts->negative)
            opts->negative = '-';
        if (format[val->index] == '0' && !opts->zero)
            opts->zero = '0';
        val->index += 1;
    }
	if (format[val->index] == '*')
    {
        opts->wildcard = '*';
        val->index += 1;
        val->width += va_arg(tab, int);
        if (val->width < 0)
        {
            opts->negative = '-';
            val->width *= -1;
        }
    }
	while (format[val->index] >= '0' && format[val->index] <= '9')
        str[i++] = format[val->index++];
    str[i] = '\0';
    if (!opts->wildcard)
        val->width = ft_atoi(str);
    free(str);
    parse_after_width(format, tab, val, opts);
	return ;
}
