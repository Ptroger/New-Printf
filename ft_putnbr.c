/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:43:10 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/08 20:24:16 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//void	ft_putnbr(int n, struct t_values *values, struct t_options *options)
//{
//	if (n > 2147483647 || n < -2147483648)
//		return ;
//	if (n == -2147483648)
//	{
//		ft_putstr("-2147483648", values, options, format);
//		return ;
//	}
//	if (n < 0)
//	{
//		ft_putchar('-');
//		n = n * -1;
//	}
//	if (n >= 10)
//	{
//		ft_putnbr(n / 10, values, options);
//		ft_putchar(n % 10 + 48);
//	}
//	else
//		ft_putchar(n + 48);
//}
