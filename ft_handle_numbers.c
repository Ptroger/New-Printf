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

//char        *ft_strcpy(char *dest, char *src)
//{
//    int i;
//
//    i = 0;
//    while(dest[i++])
//        dest[i] = dest[i];
//    return(dest);
//}

void		ft_handle_unsigned(int nb, struct t_values *values, struct t_options *options, const char format)
{
    char    *str;
	if (nb < 0)
    {
		ft_putstr("4294967272", values, options, format);
        values->result += 10;
        return ;
	}
	str = ft_itoa(nb);
	values->result += ft_putstr(str, values, options, format);
	free(str);
	return ;
}

void        ft_handle_numbers(const char format, va_list tab, struct t_values *values, struct t_options *options)
{
	int		nb;
	char	*str;

	str = (char*)malloc(11);
	str[11] = '\0';
	if (format == 'u')
	{
        nb = va_arg(tab, unsigned int);
        ft_handle_unsigned(nb, values, options,format);
        return ;
    }
    nb = va_arg(tab, int);
    if (nb == -2147483648)
    {
	    ft_putstr("-2147483648", values, options, format);
	    values->result += 10;
	    return ;
    }
	str = ft_itoa(nb);
	values->result += ft_putstr(str, values, options, format);
	free(str);
	return ;
}
