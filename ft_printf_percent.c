/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:32:58 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 02:41:10 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_percent(t_arg *arg)
{
	int		index2;

	index2 = 0;
	if (arg->is_width == 1 && arg->flag_less == 1)
	{
		ft_putchar('%', arg);
		while (index2 < arg->width - 1)
		{
			ft_putchar(arg->prefix, arg);
			index2++;
		}
	}
	else if (arg->is_width == 1)
	{
		while (index2 < arg->width - 1)
		{
			ft_putchar(arg->prefix, arg);
			index2++;
		}
		ft_putchar('%', arg);
	}
	else
		ft_putchar('%', arg);
	return (0);
}
