#include "ft_printf.h"

int		ft_itoa_base_count(unsigned long nb, unsigned int base)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long nb, unsigned int base)
{
	char	*ret;
	char	*numbers;
	int		size;

	numbers = ft_strdup("0123456789abcdef");
	ret = NULL;
	size = ft_itoa_base_count(nb, base);
	ret = (char*)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	ret[size--] = '\0';
	while (size >= 0)
	{
		ret[size--] = numbers[nb % base];
		nb /= base;
	}
	free(numbers);
	return (&ret[0]);
}
