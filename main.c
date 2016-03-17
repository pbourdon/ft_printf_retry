/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:48:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 05:30:28 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		main(void)
{
//	ft_printf("%.s", "string");
//	ft_printf("%-10s%s%.1s%s", "this", "this", "this", "this");
	// ft_printf("%-10s%-14.2s%.3s%.s%s", "this", "is", "aaaaa", "multi", "string");
//	printf ("%.s", "string");
//	printf("%-10s%s%.1s%s", "this", "this", "this", "this");
//	printf("%-10s%-14.2s%.3s%.s%s", "this", "this", "this", "this", "this");
//
//
//	ft_printf("%-2c", 'a');
	ft_printf("@moulitest : %-2c%2c", '0', 'a');
	printf("\n");
//	printf ("%-2c", 'a');
	printf ("@moulitest : %-2c%2c", '0', 'a');
	return (0);
}
