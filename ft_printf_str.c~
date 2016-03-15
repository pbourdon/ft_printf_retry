/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:41:27 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/14 16:47:45 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf_str(va_list ap, t_arg *arg)
{
	char	*str;
//	int		index;

	str = va_arg(ap, char*);
//	index = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", arg);
		return (0);
	}
	ft_putstr(str, arg);
	return (0); // need to handle that 
}
