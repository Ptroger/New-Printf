#include "ft_printf.h"
#include "stdio.h"

void        ft_handle_options(struct t_val *val, struct t_opts *opts, int i, char *str, const char format)
{
    if (format != 'p' && opts->hash == '#')
        val->width -= 2;
    if (opts->negative != '-')
    {
        if (opts->zero != '0' || (opts->dot == '.' && val->precision >= 0))
        {
//            printf("\ni = %d\nval->precision = %d\nval->width = %d\n", i, val->precision, val->width);
            while (val->width > val->precision && val->width > i )
            {
                val->result += ft_putchar(' ');
                val->width--;
            }
        }
        if (opts->hash == '#')
        {
            val->width += 2;
            if (format == 'x' || format == 'p')
                val->result += (ft_putstr("0x", val, opts, 'x') + 1);
            else
                val->result += (ft_putstr("0X", val, opts, 'x') + 1);
        }
        while (val->width > val->precision && val->width > i)
        {
            val->width--;
            val->result += ft_putchar('0');
        }
        while (val->precision-- > i)
            val->result += ft_putchar('0');
        val->result += ft_putstr(str, val, opts, 'd');
    }
    else if (opts->negative == '-')
    {
        if (opts->hash == '#')
        {
            if (format == 'x' || format == 'p')
                val->result += (ft_putstr("0x", val, opts, 'x') + 1);
            else
                val->result += (ft_putstr("0X", val, opts, 'x') + 1);
        }
        while (val->precision > i)
        {
            val->width--;
            val->precision--;
            val->result += ft_putchar('0');
        }
        val->result += ft_putstr(str, val, opts, 'd');
        while (val->width - i > 0)
        {
            val->width--;
            val->result += ft_putchar(' ');
        }
        opts->negative = '\0';
    }
}

char    *ft_to_upper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
        i++;
    }
    return(str);
}

void    handle_zero_hex(struct t_val *val, struct t_opts *opts)
{
    if (!opts->negative && (val->precision < 0 || !opts->dot))
        val->width--;
    while (!opts->negative && val->width > 0 && val->width > val->precision)
    {
        val->width--;
//        printf("\nic\n000 === %c\n", opts->zero);
        if (opts->zero && (!opts->dot || val->precision < 0))
        val->result += ft_putchar('0');
        else
        val->result += ft_putchar(' ');
//        printf("\nic\n");
    }
    if (val->precision < 0 || !opts->dot)
    {
        val->width--;
        val->result += ft_putchar('0');
    }
    while(val->precision > 0)
    {
        val->width--;
        val->result += ft_putchar('0');
        val->precision--;
    }
    while (opts->negative && val->width > 0 && val->width > val->precision)
    {
        val->width--;
        val->result += ft_putchar(' ');
    }
}

void     ft_handle_hexa(const char format, va_list tab, t_val *val, t_opts *opts) {
    char *hex;
    int i;
    unsigned long nb;

    i = 0;
    if (format == 'X' || format == 'x') {
        nb = va_arg(tab, unsigned int);
        if (format == 'X')
            hex = ft_to_upper(ft_itoa_base((unsigned int) nb, 16));
        else
            hex = ft_itoa_base((unsigned int) nb, 16);
    } else {
        val->width -= 2;
        opts->hash = '#';
        nb = va_arg(tab, unsigned long);
        if (nb == 0)
        {
            if (opts->dot != '.')
                val->width--;
            handle_zero_zero(val, opts, format);
            return;
        }
        hex = ft_itoa_base(nb, 16);
    }
    if (nb == 0) {
        handle_zero_hex(val, opts);
        val->result--;
        return;
    }
    i = ft_strlen(hex);
    ft_handle_options(val, opts, i, hex, format);
    free(hex);
    reset_opts(val, opts);
    return;
}