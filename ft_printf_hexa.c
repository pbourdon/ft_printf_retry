#include "libprintf.h"

int		ft_printf_hexa(va_list ap, t_arg *arg)
{
	int		nbr;

	nbr = va_arg(ap, int);
	return (ft_printf_display_hexa(ft_base_converter(nbr, 16, 1), arg));
}

int		ft_printf_display_hexa(char *str, t_arg *arg)
{
	int		index;
	int		precision;
	int		len;

	len = ft_strlen(str);
	precision = arg->precision;
	index = 0;
	if (arg->is_precision == 1 && arg->flag_less == 1 && arg->precision > 0)
	{
		while (arg->precision-- > 0 && len-- > 0)
			ft_putchar(str[index++], arg);
		len = ft_strlen(str);
		if (arg->is_width && arg->width > len && len < precision)
			while (arg->width-- - len > 0)
				ft_putchar(arg->prefix, arg);
		if (arg->is_width && arg->width > precision && len > precision)
			while (arg->width-- - precision > 0)
				ft_putchar(arg->prefix, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	return (0);
}
