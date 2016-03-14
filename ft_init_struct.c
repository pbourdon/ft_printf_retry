/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:27:17 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/14 15:23:34 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_init_struct(t_arg *arg)
{
	arg->flag_sharp = 0;
	arg->flag_less = 0;
	arg->flag_more = 0;
	arg->flag_space = 0;
	arg->flag0 = 0;
	arg->is_width = 0;
	arg->second_flag = 0;
	arg->is_precision = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->prefix = ' ';
	arg->retur = 0;
}
