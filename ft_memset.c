/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 20:01:23 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/03 20:02:08 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void			*ft_memset(void *destination, int int_value, size_t len)
{
	size_t			i;
	unsigned char	*location;
	unsigned char	value;

	value = (unsigned char)int_value;
	location = (unsigned char*)destination;
	i = 0;
	while (i < len)
	{
		location[i] = value;
		i++;
	}
	return (destination);
}
