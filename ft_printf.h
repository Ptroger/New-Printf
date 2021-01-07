/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptroger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:47:23 by ptroger           #+#    #+#             */
/*   Updated: 2020/02/11 14:08:42 by ptroger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_struct
{
	char			type;
	int				precision;
	int				paddle;
}					t_struct;


//############# FONCTIONS AFFICHAGE ENTIERS ##########

int		ft_handle_numbers(const char format, va_list tab);
void	ft_putnbr(int n);
int     ft_handle_hexa(const char format, va_list tab);

//############# FONCTIONS AFFICHAGE CHAR ET CHAR* #############

void	ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_handle_char(const char format, va_list tab);

//############# FONCTIONS UTILS PRINTF ########################

char	*ft_itoa_base(unsigned long int nb, unsigned int base);
int     ft_handle_modulo();
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char *src);

//############# FONCTIONS ALGO PRINTF #########################

int		put_tab(const char *format, va_list tab);
int		parse(const char *format, va_list tab);
int		parse_options(const char *format, va_list tab);
int		ft_printf(const char *format, ...);

#endif
