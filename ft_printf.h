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
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

typedef struct	t_opts
{
	char wildcard;
	char negative;
	char zero;
	char dot;
	char dothash;
	char hash;
}				s_opts;

typedef struct	t_val
{
	int index;
	int result;
	int precision;
	int width;
}				s_val;

void			ft_handle_numbers(const char format, va_list ta,
	struct t_val *val, struct t_opts *opts);
void			ft_putnbr(int n, struct t_val *val, struct t_opts *opts);
void			ft_handle_hexa(const char format, va_list tab,
	struct t_val *val, struct t_opts *opts);
void			handle_zero_zero(struct t_val *val, struct t_opts *opts,
	const char format);

struct t_opts	*initialise_opts(void);
struct t_val	*initialise_val(void);
void			reset_opts(struct t_val *val, struct t_opts *opts);

int				ft_handle_opts(struct t_val *val,
	struct t_opts *opts, char *str);
int				ft_putchar(int c);
int				ft_putstr(char *str, struct t_val *val, struct
	t_opts *opts, const char format);
void			ft_handle_char(const char format, va_list tab,
	struct t_val *val, struct t_opts *opts);

char			*ft_itoa_base(unsigned long nb, unsigned int base);
int				ft_atoi(const char *str);
void			ft_handle_modulo(struct t_val *val, struct t_opts *opts);
char			*ft_itoa(int n);
char			*ft_unsigned_itoa(unsigned int n);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
char			*ft_strdup(const char *src);

void			put_tab(const char *format, va_list tab, struct t_val *val,
	struct t_opts *opts);
void			parse(const char *format, va_list tab,
	struct t_val *val, struct t_opts *opts);
void			parse_opts(const char *format, va_list tab, struct t_val *val,
	struct t_opts *opts);
int				ft_printf(const char *format, ...);

#endif
