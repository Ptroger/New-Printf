/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:24:43 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/08 20:25:37 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_handle_modulo(t_values *values, t_options *options)
{
  values->width -= 1;
  if (values->width > 0)
      ft_handle_options(values, options);
  ft_putchar('%');
	return ;
}
