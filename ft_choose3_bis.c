/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose3_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 02:54:02 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 03:01:10 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_choose3_bis(va_list ap, const char* format, int *index, t_arg *arg)
{
	*index = *index + 1;
	while (format[*index] >= '0' && format[*index] <= '9')
	{
		arg->is_precision = 1;
		arg->precision = arg->precision * 10 + format[*index] - '0';
		*index = *index + 1;
	}
	return (ft_choose(ap, format, index, arg));
}
