/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:41:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 05:29:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_str(va_list ap, t_arg *arg)
{
	char	*str;
	int		precision;
	int		index;
	int		len;

	str = va_arg(ap, char*);
	len = ft_strlen(str);
	precision = arg->precision;
	index = 0;
	if (arg->is_precision == 1 && arg->flag_less == 1)
	{
		while (arg->precision-- > 0 && len-- > 0)
			ft_putchar(str[index++], arg);
		len = ft_strlen(str);
		if (arg->is_width && arg->width > len && len < precision)
			while (arg->width-- - len > 0)
				ft_putchar(arg->prefix, arg);
		if (arg->is_width && arg->width > precision && len > precision)
			while (arg->width-- - precision >0)
				ft_putchar(arg->prefix, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	return (ft_printf_str2(arg, index, str));
}

int		ft_printf_str2(t_arg *arg, int index, char *str)
{
	int		precision;
	int		len;

	precision = arg->precision;
	len = ft_strlen(str);
	if (arg->is_precision == 1 && arg->flag_less != 1)
	{
		if (arg->is_width && arg->width > len && len < precision)
			while (arg->width-- - len > 0)
				ft_putchar(arg->prefix, arg);
		if (arg->is_width && arg->width > precision && len > precision)
			while (arg->width-- - precision >0)
				ft_putchar(arg->prefix, arg);
		while (arg->precision-- > 0 && len-- > 0)
			ft_putchar(str[index++], arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	return (ft_printf_str3(arg, str));
}

int		ft_printf_str3(t_arg *arg, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (arg->flag_less != 1 && arg->is_width == 1)
	{
		while (arg->width-- - len > 0)
			ft_putchar(arg->prefix, arg);
		ft_putstr(str, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	else if (arg->flag_less == 1 && arg->is_width == 1)
	{
		ft_putstr(str, arg);
		while (arg->width-- - len >0)
			ft_putchar(arg->prefix, arg);
		ft_init_struct(arg, arg->position);
		return (0);
	}
	else
		ft_putstr(str, arg);
	ft_init_struct(arg, arg->position);
	return (0);
}
