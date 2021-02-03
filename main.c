#include "ft_printf.h"
#include "stdlib.h"
#include <unistd.h>
#include <fcntl.h>

int main()
{
	unsigned	int		fd;
	fd = -2147483648;

	printf("\n|--->%-*.*u<---|\n%-*.*x|\n", 1, -1, 8, 1, -1, 8);
	ft_printf("\n|--->%-*.*u<---|\n%-*.*x|\n", 1, -1, 8, 1, -1, 8);
}