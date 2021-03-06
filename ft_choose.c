#include "libprintf.h"

int		ft_choose(va_list ap, const char *format, int *index, t_arg *arg)
{
	while (*index <= arg->position)
	{
		if (format[*index] == '#')
		{
			*index = *index + 1;
			arg->flag_sharp = 1;
			return (ft_choose(ap, format, index, arg));
		}
		else if (format[*index] == '-')
		{
			*index = *index + 1;
			arg->flag_less = 1;
			return (ft_choose(ap, format, index, arg));
		}
		else if (format[*index] == '+')
		{
			*index = *index + 1;
			arg->flag_more = 1;
			return (ft_choose(ap, format, index, arg));
		}
		return (ft_choose2(ap, format, index, arg));
	}
	return (0);
}

int		ft_choose2(va_list ap, const char *format, int *index, t_arg *arg)
{
	while (*index <= arg->position)
	{
		if (format[*index] == ' ')
		{
			*index = *index + 1;
			arg->flag_space = 1;
			return (ft_choose(ap, format, index, arg));
		}
		else if (format[*index] == '0' && format[*index - 1] != '.')
		{
			*index = *index + 1;
			arg->flag0 = 1;
			return (ft_choose(ap, format, index, arg));
		}
		return (ft_choose3(ap, format, index, arg));
	}
	return (0);
}

int		ft_choose3(va_list ap, const char *format, int *index, t_arg *arg)
{
	while (*index <= arg->position)
	{
		if (format[*index] > '0' && format[*index] <= '9')
		{
			arg->is_width = 1;
			while (format[*index] >= '0' && format[*index] <= '9')
			{
				arg->width = arg->width * 10 + format[*index] - '0';
				*index = *index + 1;
			}
			return (ft_choose(ap, format, index, arg));
		}
		/*
		else if (format[*index] == '.')
		{
			ft_choose3_bis(ap, format, index, arg);
			
			*index = *index + 1;
			while (format[*index] >= '0' && format[*index] <= '9')
			{
				arg->is_precision = 1;
				arg->precision = arg->precision * 10 + format[*index] - '0';
				*index = *index + 1;
			}
			return (ft_choose(ap, format, index, arg));
			
		}
	*/
		else if (format[*index] == 'j')
		{
			arg->second_flag = 5;
			*index = *index + 1;
			return (ft_choose(ap, format, index, arg));
		}
		return (ft_choose3_bis(ap, format, index, arg));
	}
	return (0);
}

int		ft_choose4(va_list ap, const char *format, int *index, t_arg *arg)
{
	while (*index < arg->position)
	{
		if (format[*index] == 'l' && format[*index + 1] == 'l')
		{
			arg->second_flag = 3;
			*index = *index + 1;
			arg->doubble = 1;
			return (ft_choose(ap, format, index, arg));
		}
		else if (format[*index] == 'h' && format[*index + 1] == 'h')
		{
			arg->second_flag = 1;
			*index = *index + 1;
			arg->doubble = 1;
			return (ft_choose(ap, format, index, arg));
		}
		return (ft_choose5(ap, format, index, arg));
	}
	return (0);
}

int		ft_choose5(va_list ap, const char *format, int *index, t_arg *arg)
{
	while (*index <= arg->position)
	{
		if (format[*index] == 'h' && arg->doubble != 1)
		{
			arg->second_flag = 2;
			*index = *index + 1;
			return (ft_choose(ap, format, index, arg));
		}
		else if (format[*index] == 'l' && arg->doubble != 1)
		{
			arg->second_flag = 4;
			*index = *index + 1;
			return (ft_choose(ap, format, index, arg));
		}
		return (ft_choose_type(ap, format, index, arg));
	}
	return (0);
}
