/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_converter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 20:07:09 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/03 20:28:46 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
/*
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void	*ft_memset(void *destination, int int_value, size_t len)
{
	size_t	i;
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

void	ft_bzero(void *string, size_t len)
{
	ft_memset(string, '\0', len);
}

void	*ft_memalloc(size_t size)
{
	void*fresh;

	if (size == 0)
		return (NULL);
	fresh = malloc(size);
	if (fresh == NULL)
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}

char	*ft_strnew(size_t size)
{
	return (ft_memalloc(size + 1));
}
*/
char	*ft_base_converter(int nbr, int base, int lower)
{
	char	*result;
//	int		rest;
	int		index;
	int		save;
	char		c;


	if (lower == 1)
		c = 'a';
	else
		c = 'A';
	save = nbr;
	index = 0;
//	rest = 0;
	while (nbr > base)
	{
//		rest = nbr % base;
		nbr = nbr / base;
		index++;
	}
	result = ft_strnew(index);
	return (ft_base_converter2(save, base, result, c));
}

char	*ft_base_converter2(int nbr, int base, char *result, char c)
{
	int		index;
	int		rest;

	index = 0;
	while (nbr > base)
	{
		rest = nbr % base;
		if (rest < 10)
			result[index] = rest + '0';
		else
			result[index] = c + rest - 10;
		nbr = nbr / base;
		index++;
	}
	if (nbr < 10)
		result[index] = nbr + '0';
	else
		result[index] = c + nbr - 10;
	return (ft_reverse_return(result));
}

char	*ft_reverse_return(char *str)
{
	char	*str2;
	int		index;
	int		index2;

	index = ft_strlen(str);
	index2 = 0;
	str2 = ft_strnew(ft_strlen(str));
	while (index-- > 0)
		str2[index2++] = str[index];
	return (str2);
}
/*
int		main(void)
{
	int		nbr;
	int		base;
	char	result[66666];

	nbr = 42999;
	base = 16;
	ft_base_converter(nbr, base, 1);
	return (0);
}
*/
