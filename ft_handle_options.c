#include "ft_printf.h"


void    ft_handle_options(struct t_values *values, struct t_options *options)
{
    if (options->negative == '\0')
    {
        if (options->zero == '0')
        {
            while (values->width-- > 0)
                values->result += ft_putchar('0');
        }
        while (values->width-- > 0)
            values->result += ft_putchar(' ');
    }
    return;
}