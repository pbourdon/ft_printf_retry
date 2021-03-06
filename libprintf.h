/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:06:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/03/16 02:58:23 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct			s_yolo
{
	int					flag_sharp;
	int					flag_less;
	int					flag_more;
	int					flag_space;
	int					flag0;
	int					is_width;
	int					second_flag;
	int					is_precision;
	int					width;
	int					precision;
	char				prefix;
	int					retur;
	int					position;
	int					doubble;
}						t_arg;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, t_arg *arg);
int		ft_strlen(char *str);
void	ft_putstr(char *str, t_arg *arg);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *string, size_t len);
void	*ft_memset(void *destinataire, int int_value, size_t len);

void	ft_init_struct(t_arg *arg, int index);
int		ft_retur(t_arg *arg);
char	*ft_base_converter(int nbr, int base, int lower);
char	*ft_base_converter2(int nbr, int base, char *result, char c);
char	*ft_reverse_return(char *str);

int		ft_choose(va_list ap, const char *format, int *index, t_arg *arg);
int		ft_choose2(va_list ap, const char *format, int *index, t_arg *arg);
int		ft_choose3(va_list ap, const char *format, int *index, t_arg *arg);
int		ft_choose3_bis(va_list ap, const char *format, int *index, t_arg *arg);
int		ft_choose4(va_list ap, const char *format, int *index, t_arg *arg);
int		ft_choose5(va_list ap, const char *format, int *index, t_arg *arg);

int		ft_choose_type(va_list ap, const char *format, int *index, t_arg *arg);

int		ft_printf_percent(t_arg *arg);

int		ft_printf_str(va_list ap, t_arg *arg);
int		ft_printf_str2(t_arg *arg, int index, char *str);
int		ft_printf_str3(t_arg *arg, char *str);

int		ft_printf_char(va_list ap, t_arg *arg);

int		ft_printf_hexa(va_list ap, t_arg *arg);
int		ft_printf_display_hexa(char *str, t_arg *arg);
#endif
