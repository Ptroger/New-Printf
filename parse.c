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
  if (*format == '%')
  	return (ft_handle_modulo());
  if (*format == 'p' || *format == 'x' || *format == 'X')
  	return (ft_handle_hexa(*format, tab));
  return (0);
}

char	getFlag(char c)
{
  if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
    return (1);
  else 
    return (0);
}
int parse(const char *format, va_list tab)
{
  int i;
  int len;

  len = 0;
  i = -1;
  while (format[++i])
  {
    if (format[i] == '%')
    {
      i++;
      if (getFlag(format[i]))
        len += (put_tab(format + i, tab) -1);
      else
        i += parse_options(format + i, tab);
    }
    else
      ft_putchar(format[i]);
  }
  return (i + len);
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
