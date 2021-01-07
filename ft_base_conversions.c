#include "ft_printf.h"




int ft_itoa_base_count(unsigned long int nb, unsigned int base) {
    int i;

    if (nb == 0)
        return (1);
    i = 0;
    while (nb > 0) {
        printf("\nnb = %x", nb);
        nb = nb / base;
        i++;
    }
    return (i);
}

char *ft_itoa_base(unsigned long int nb, unsigned int base) {
    char *ret;
    char *numbers;
    int size;
    int temp;

    numbers = ft_strdup("0123456789abcdef");
    ret = NULL;
    size = ft_itoa_base_count(nb, base);
    ret = (char *) malloc(sizeof(char) * size + 1);
    if (!ret)
        return (NULL);
    ret[size--] = '\0';
//    while(nb!=0)
//    {
//        ft_putstr("\nnb = ");
//        ft_putnbr(nb);
//        temp = nb % 16;
//        if(temp < 10)
//            ret[size--] = temp + 48;
//        else
//            ret[size--] = temp + 55;
//        nb = nb / 16;
//    }
    while (size >= 0) {
        ret[size--] = numbers[nb % base];
        nb /= base;
    }
    printf ("\n\nstr ==%s\n\n", ret);
    free(numbers);
    return (&ret[0]);
}
