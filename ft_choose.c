/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:21:58 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/14 17:04:50 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_choose(va_list ap, const char *format, int *index, t_arg *arg)
{
	// printf("%c is the current letter \n", format[*index]);
	*index = *index + 1;
	if (format[*index] == '#')
	{
		arg->flag_sharp = 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == '-')
	{
		arg->flag_less = 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == '+')
	{
		arg->flag_more = 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == ' ')
	{
		arg->flag_space = 1;
		ft_choose(ap, format, index, arg);
	}
	return (ft_choose2(ap, format, index, arg));
}

int		ft_choose2(va_list ap, const char *format, int *index, t_arg *arg)
{
	if (format[*index] == '0' && format[*index - 1] != '.')
	{
		arg->flag0 = 1;
		arg->prefix = '0';
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] > '0' && format[*index] <= '9')
	{
		arg->is_width = 1;
		while (format[*index] >= '0' && format[*index] <= '9')
		{
			arg->width = arg->width * 10 + format[*index] - '0';
			*index = *index + 1;
		}
		*index = *index - 1;
		ft_choose(ap, format, index, arg);
	}
	return (ft_choose3(ap, format, index, arg));
}

int		ft_choose3(va_list ap, const char *format, int *index, t_arg *arg)
{
	if (format[*index] == '.')
	{
		arg->is_precision = 1;
		*index = *index + 1;
		while (format[*index] >= '0' && format[*index] <= '9')
		{
			arg->precision = arg->precision * 10 + format[*index] - '0';
			*index = *index + 1;
		}
		*index = *index - 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == 'h' && format[*index + 1] == 'h')
	{
		arg->second_flag = 1;
		*index = *index + 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == 'h')
	{
		arg->second_flag = 2;
		ft_choose(ap, format, index, arg);
	}
	return (ft_choose4(ap, format, index, arg));
}

int		ft_choose4(va_list ap, const char *format, int *index, t_arg *arg)
{
	if (format[*index] == 'l' && format[*index + 1] == 'l')
	{
		arg->second_flag = 3;
		*index = *index + 1;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == 'l')
	{
		arg->second_flag = 4;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == 'j')
	{
		arg->second_flag = 5;
		ft_choose(ap, format, index, arg);
	}
	else if (format[*index] == 'z')
	{
		arg->second_flag = 6;
		ft_choose(ap, format, index, arg);
	}
	return (ft_choose_type(ap, format, index, arg));
}
