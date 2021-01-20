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

struct			s_opt
{
	char wildcard;
	char negative;
	char zero;
	char dot;
	char dothash;
	char hash;
}				s_opt;

struct			s_val
{
	int index;
	int result;
	int precision;
	int width;
}				s_val;

void			ft_handle_numbers(const char format, va_list tab,
				struct s_val *val, struct s_opt *opt);
void			ft_handle_nb(struct s_val *val, struct s_opt *opt, int nb,
				char *str);
void			ft_handle_hexa(const char format, va_list tab,
				struct s_val *val, struct s_opt *opt);
void			handle_zero_zero(struct s_val *val, struct s_opt *opt,
				const char format);
void			ft_handle_options(struct s_val *val, struct s_opt *opt,
				char *str, const char format);

struct s_opt	*initialise_opt(void);
struct s_val	*initialise_val(void);
void			reset_opt(struct s_val *val, struct s_opt *opt);

int				ft_handle_opt(struct s_val *val,
				struct s_opt *opt, char *str);
int				ft_putchar(int c);
int				ft_putstr(char *str, struct s_val *val, struct s_opt *opt,
				const char format);
void			ft_handle_char(const char format, va_list tab,
				struct s_val *val, struct s_opt *opt);

char			*ft_to_upper(char *str);
char			*ft_itoa_base(unsigned long nb, unsigned int base);
int				ft_atoi(const char *str);
void			ft_handle_modulo(struct s_val *val, struct s_opt *opt);
char			*ft_itoa(int n);
char			*ft_unsigned_itoa(unsigned int n);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
char			*ft_strdup(const char *src);

void			put_tab(const char *format, va_list tab, struct s_val *val,
				struct s_opt *opt);
void			parse(const char *format, va_list tab,
				struct s_val *val, struct s_opt *opt);
void			parse_opt(const char *format, va_list tab, struct s_val *val,
				struct s_opt *opt);
int				ft_printf(const char *format, ...);

#endif
