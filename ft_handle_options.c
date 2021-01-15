#include "ft_printf.h"

void    ft_handle_options(va_list tab, struct t_values *values, struct t_options *options)
{
    if (options->hash == '#')
        values->width = va_arg(tab, unsigned int);
    if (options->zero == '0')
    {
        while (values->width--)
            values->result += ft_putchar('0');
    }
    while (values->width--)
        values->result += ft_putchar(' ');
    return;
}