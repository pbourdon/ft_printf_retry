/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 02:43:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_choose_type(va_list ap, const char *format, int *index, t_arg *arg)
{
	if (format[*index] == '%')
	{
		*index = *index + 1;
		return (ft_printf_percent(arg));
	}
	else if (format[*index] == 's')
	{
		*index = *index + 1;
		return (ft_printf_str(ap, arg));
	}
	else if (format[*index] == 'c')
	{
		*index = *index + 1;
		return (ft_printf_char(ap, arg));
	}
	else if (format[*index] == 'x')
	{
		*index = *index + 1;
		return (ft_printf_hexa(ap, arg));
	}
	return (0);
}
