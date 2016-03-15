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
	if (format[*index] == '%')
	{
		*index = *index + 1;
		ft_printf_percent(arg);
		return(0);
	}
	return (0);
}
