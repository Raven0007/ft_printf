#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft(char *str)
{
	printf("%s", str);
}
int	main()
{
	char *str = "Helo" "World";
	ft(str);

}