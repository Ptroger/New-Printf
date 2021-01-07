#include "ft_printf.h"
#include "stdio.h"

int     ft_handle_hexa(const char format, va_list tab)
{
    char    *hex;
    int nb;
    int len;

    nb = va_arg(tab, unsigned long int);
    if (format == 'p') {
        len += 2;
        ft_putstr("0x");
    }
    //    if (nb < 0)
//        hex = convert_to_hex_neg(nb);
//    else
    hex = ft_itoa_base(nb, 16);
    len += ft_strlen(hex);
    ft_putstr(hex);
    free(hex);
    return(len);
}
