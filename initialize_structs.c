#include "ft_printf.h"

t_options     *initialise_options(void)
{
    t_options   *options;

    options = (t_options*)malloc(sizeof(struct t_options));
    if (!options)
        return (NULL);
    options->hash = '\0';
    options->negative = '\0';
    options->zero = '\0';
    options->wildcard = '\0';
    options->dot = '\0';
    return(options);
}

t_values     *initialise_values(void)
{
    t_values   *values;

    values = (t_values*)malloc(sizeof(struct t_values));
    if (!values)
        return (NULL);
    values->index = 0;
    values->result = 0;
    values->precision = 0;
    values->width = 0;
    return(values);
}