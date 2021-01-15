#include "ft_printf.h"
#include "stdio.h"

char    *ft_to_upper(char *str)
{
    int i;

    i = -1;
    while(str[i++])
        str[i] -= 40;
    return(str);
}

void     ft_handle_hexa(const char format, va_list tab, t_values *values, t_options *options)
{
    char *hex;
    unsigned long nb;

    if (format == 'X' || format == 'x')
    {
        nb = va_arg(tab, unsigned int);
        if (format == 'X') {
            if (options->hash == 1)
                values->result += ft_putstr("0X", values, options, format);
        }
        if (options->hash == 1)
            values->result += ft_putstr("0x", values, options, format);
        hex = ft_to_upper(ft_itoa_base((unsigned int)nb, 16));
    }
    else
    {
        values->width = 0;
        values->result += (ft_putstr("0x", values, options, format) + 1);
        nb = va_arg(tab, unsigned long);
        hex = ft_itoa_base(nb, 16);
    }
    values->result += ft_putstr(hex, values, options, format);
    free(hex);
    return ;
}
