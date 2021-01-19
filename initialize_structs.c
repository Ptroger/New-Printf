#include "ft_printf.h"

t_opts     *initialise_opts(void)
{
    t_opts   *opts;

    opts = (t_opts*)malloc(sizeof(struct t_opts));
    if (!opts)
        return (NULL);
    opts->hash = '\0';
    opts->dotHash = '\0';
    opts->negative = '\0';
    opts->zero = '\0';
    opts->wildcard = '\0';
    opts->dot = '\0';
    return(opts);
}

t_val     *initialise_val(void)
{
    t_val   *val;

    val = (t_val*)malloc(sizeof(struct t_val));
    if (!val)
        return (NULL);
    val->index = 0;
    val->result = 0;
    val->precision = 0;
    val->width = 0;
    return(val);
}

void                reset_opts(struct t_val *val, struct t_opts *opts)
{
    opts->hash = '\0';
    opts->dotHash = '\0';
    opts->negative = '\0';
    opts->zero = '\0';
    opts->wildcard = '\0';
    opts->dot = '\0';
    val->precision = 0;
    val->width = 0;
}