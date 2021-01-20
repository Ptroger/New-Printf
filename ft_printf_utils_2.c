/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:38:36 by ptroger           #+#    #+#             */
/*   Updated: 2020/01/07 13:52:31 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	return (str);
}

static int	ft_intlen(unsigned int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_unsigned_itoa(unsigned int n)
{
	int		i;
	char	*s;

	if (!(s = ft_strnew(ft_intlen(n))))
		return (NULL);
	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n > 0)
	{
		s[(ft_intlen(n)) + i - 1] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;

	if (!(s = ft_strnew(ft_intlen(n))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		if (n == -2147483648)
		{
			s[i++] = '2';
			n = -147483648;
		}
		n = -n;
	}
	if (n == 0)
		s[i++] = '0';
	while (n > 0)
	{
		s[(ft_intlen(n)) + i - 1] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}
