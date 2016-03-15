/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/14 17:05:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_choose_type(va_list ap, const char *format, int *index, t_arg *arg)
{
//	printf ("here");
	if (format[*index] == '%')
	{
		*index = *index + 1;
		ft_printf_percent(arg);
		return (0);
	}
	else if (format[*index] == 's')
		ft_printf_str(ap, arg);
	return (0);
}
