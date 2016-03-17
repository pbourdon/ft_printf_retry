#include "libprintf.h"

int		ft_printf_char(va_list ap, t_arg *arg)
{
	int		c;

	c = va_arg(ap, int);
	if (arg->flag_less != 1 && arg->is_width == 1)
	{
		while (arg->width-- - 1 > 0)
			ft_putchar(arg->prefix, arg);
		ft_putchar(c, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	else if (arg->flag_less == 1 && arg->is_width == 1)
	{
		ft_putchar(c, arg);
		while (arg->width-- - 1 > 0)
			ft_putchar(arg->prefix, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	ft_putchar(c, arg);
	return (0);
}
