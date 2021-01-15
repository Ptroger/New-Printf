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

void        put_tab(const char *format, va_list tab, struct t_values *values, struct t_options *options)
{
    if (values->width != 0)
      ft_handle_options(tab, values, options);
  if (format[values->index] == 'c' || format[values->index] == 's')
      ft_handle_char(format[values->index], tab, values, options);
  else if (format[values->index] == 'd' || format[values->index] == 'i' || format[values->index] == 'u')
    ft_handle_numbers(format[values->index], tab, values, options);
  else if (format[values->index] == '%')
  	ft_handle_modulo(values, options);
  else if (format[values->index] == 'p' || format[values->index] == 'x' || format[values->index] == 'X')
  	ft_handle_hexa(format[values->index], tab, values, options);
  return ;
}

int     getOptions(char c)
{
    if (c == '#' || c == '-' || c == '*' || c == '.' || ft_isdigit(c))
        return (1);
    else
        return (0);
}

char	getFlag(char c)
{
  if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
    return (1);
  else 
    return (0);
}

void parse(const char *format, va_list tab, struct t_values *values, struct t_options *options)
{
    while (format[values->index])
  {
      if (format[values->index] == '%')
    {
      values->index++;
      if (getOptions(format[values->index]))
        parse_options(format, tab, values, options);
//        printf("\nformat = %c\n", format[values->index]);
        if (getFlag(format[values->index]))
          put_tab(format, tab, values, options);
    }
    else
      ft_putchar(format[values->index]);
    values->index += 1;
    values->result += 1;
  }
    return ;
}

int		ft_printf(const char *format, ...)
{
    t_values    *values;
    t_options   *options;
    int         i;

    options = initialise_options();
    values = initialise_values();
    if (!options || !values)
    {
//        printf("icicicic");
//        ft_putstr("Malloc Error");
        return(0);
    }
  va_list		tab;
  va_start(tab, format);
  parse((char*)format, tab, values, options);
  va_end(tab);
  free(options);
  i = values->result;
  free(values);
  return (i);
}
