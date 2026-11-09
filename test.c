#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft(long v)
{
	printf("%ld", v);
}
int	main()
{
	unsigned int	x = 2147483649;
	ft(x);
}
