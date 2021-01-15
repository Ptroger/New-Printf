/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:29:53 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/10 18:05:11 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (src[i])
		i++;
	if ((dest = (char *)malloc(sizeof(char) * (i + 1))))
	{
		while (src[n])
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = 0;
	}
	return (dest);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int				sign;
	long	int		res;

	sign = 1;
	res = 0;
	while ((*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' ||
		*str == '\f' || *str == ' ') && (*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		res = res * 10 + (unsigned int)(*str - '0');
		str++;
	}
	return (res * sign);
}
