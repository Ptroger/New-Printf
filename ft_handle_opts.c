#include "ft_printf.h"


int    ft_handle_opts(struct t_val *val, struct t_opts *opts, char *str)
{
    int neg;

    neg = 0;
    if (opts->negative == '\0')
    {
        if (opts->zero == '0' && (opts->dot != '.' || val->precision < 0 ))
        {
            if (str[0] == '-')
            {
                val->result += ft_putchar('-');
                neg = 1;
            }
            while (val->width > 0)
            {
                    val->result += ft_putchar('0');
                    val->width--;
            }
            opts->zero = '\0';
        }
        while (val->width > 0)
        {
            val->result += ft_putchar(' ');
            val->width--;
        }
    }
    return (neg);
}