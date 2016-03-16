/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:09:47 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 04:33:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_printf(const char *format, ...)
{
	int			index;
	va_list		ap;
	int			index2;
	t_arg		arg;

	index2 = 0;
	va_start(ap, format);
	index = -1;
	while (format[index2] != '\0')
		index2++;
	ft_init_struct(&arg, index2);
	while (format[++index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			ft_choose(ap, format, &index, &arg);
			index--;
		}
		else
			ft_putchar(format[index], &arg);
	}
	
	printf("\n");
	printf("%d is arg_flag0\n", arg.flag0);
	printf("%d is arg_flag sharp\n", arg.flag_sharp);
	printf("%d is arg_flag less\n", arg.flag_less);
	printf("%d is arg_flag more\n", arg.flag_more);
	printf("%d is arg_second_flag\n", arg.second_flag);
	printf("%d is arg_space\n", arg.flag_space);
	printf("%d is arg_is_width\n", arg.is_width);
	printf("%d is arg_width\n", arg.width);
	printf("%d is the is_precision\n", arg.is_precision);
	printf("%d is the precision\n", arg.precision);
	
	va_end(ap);
	return (ft_retur(&arg));
}
