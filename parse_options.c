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

//void		parse_after_width(const char *format, va_list tab, struct t_values *values, struct t_options *options)
//{
//
//}

void		parse_options(const char *format, va_list tab, struct t_values *values, struct t_options *options)
{
    char    *str;
    int     i;

    i = 0;
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
//    printf("\nLALALA == %d\n", values->index);
//    printf("\nICI == %s\n", format);
    if (format[values->index] == '*')
    {
        options->wildcard = '*';
        values->index += 1;
//        printf("\nICI == %c\n", format[values->index - 6]);
    }
    while (ft_isdigit(format[values->index]))
    {
        str[i++] = format[values->index];
        values->index += 1;
    }
    if (str)
        values->width = ft_atoi(str);
//    parse_after_width(format, tab, values, options);
	return ;
}
