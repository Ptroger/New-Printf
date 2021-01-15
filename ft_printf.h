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

typedef struct		t_options
{
	char			wildcard;
	char            negative;
	char            zero;
	char            dot;
	char            dotHash;
	char            hash;
}					t_options;

typedef struct		t_values
{
    int             index;
    int             result;
    int             precision;
    int             width;
}					t_values;


//############# FONCTIONS AFFICHAGE ENTIERS ##########

void		ft_handle_numbers(const char format, va_list ta, struct t_values *values, struct t_options *options);
void	ft_putnbr(int n, struct t_values *values, struct t_options *options);
void     ft_handle_hexa(const char format, va_list tab, struct t_values *values, struct t_options *options);

//############# FONCTIONS GESTION STRUCT #############

struct t_options     *initialise_options(void);
struct t_values     *initialise_values(void);

//############# FONCTIONS AFFICHAGE CHAR ET CHAR* #############

void    ft_handle_options(struct t_values *values, struct t_options *options);
int 	ft_putchar(int c);
int		ft_putstr(char *str, struct t_values *values, struct t_options *options, const char format);
void	ft_handle_char(const char format, va_list tab, struct t_values *values, struct t_options *options);

//############# FONCTIONS UTILS PRINTF ########################

char	*ft_itoa_base(unsigned long nb, unsigned int base);
int		ft_atoi(const char *str);
void    ft_handle_modulo(struct t_values *values, struct t_options *options);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
char	*ft_strdup(const char *src);

//############# FONCTIONS ALGO PRINTF #########################

void        put_tab(const char *format, va_list tab, struct t_values *values, struct t_options *options);
void		parse(const char *format, va_list tab, struct t_values *values, struct t_options *options);
void		parse_options(const char *format, va_list tab, struct t_values *values, struct t_options *options);
int		ft_printf(const char *format, ...);

#endif
