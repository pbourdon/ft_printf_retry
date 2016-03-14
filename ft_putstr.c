#include "libprintf.h"

void	ft_putstr(char *str, t_arg *arg)
{
	int	index;
	index = 0;
	while (str[index] != '\0')
	{
		write (1, &str[index], 1);
		arg->retur = arg->retur + 1;
		index++;
	}
}
