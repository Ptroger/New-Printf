/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <ptroger@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:06:53 by pierre            #+#    #+#             */
/*   Updated: 2021/01/21 13:06:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct	s_opt	*initialise_opt(void)
{
	struct s_opt	*opt;

	opt = (struct s_opt*)malloc(sizeof(s_opt));
	if (!opt)
		return (NULL);
	opt->hash = '\0';
	opt->dothash = '\0';
	opt->negative = '\0';
	opt->zero = '\0';
	opt->wildcard = '\0';
	opt->dot = '\0';
	return (opt);
}

struct	s_val	*initialise_val(void)
{
	struct s_val	*val;

	val = (struct s_val*)malloc(sizeof(s_val));
	if (!val)
		return (NULL);
	val->index = 0;
	val->result = 0;
	val->precision = 0;
	val->width = 0;
	return (val);
}

void			reset_opt(struct s_val *val, struct s_opt *opt)
{
	opt->hash = '\0';
	opt->dothash = '\0';
	opt->negative = '\0';
	opt->zero = '\0';
	opt->wildcard = '\0';
	opt->dot = '\0';
	val->precision = 0;
	val->width = 0;
}
