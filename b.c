/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:47:16 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 11:57:36 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_b(t_gv *gv, va_list lst)
{
	unsigned long long	o;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "hh", 2))
			o = (unsigned char)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "h", 2))
			o = (unsigned short)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "l", 2))
			o = va_arg(lst, unsigned long);
		else if (ft_strncmp(gv->leng, "ll", 2))
			o = va_arg(lst, unsigned long long);
	}
	else
		o = (unsigned long long)va_arg(lst, unsigned int);
	ultoa_base(gv, (unsigned long)o, 2, 0);
}

void	manage_k(t_gv *gv, va_list lst)
{
	int		j;
	char	*str;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	j = 0;
	str = va_arg(lst, char *);
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen - (int)ft_strlen(str)
		- (gv->pflags & FLAG_PRECISION && gv->precision >
		ft_strlenfrom(str, '.') ? gv->precision -
		ft_strlenfrom(str, '.') : 0)))
		{
			addchartobuff(gv, ' ');
			j++;
		}
	}
	manage_k_e(gv, str, j);
}

void	manage_k_e(t_gv *gv, char *str, int j)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			addchartobuff(gv, str[i]);
		else
		{
			addchartobuff(gv, '<');
			addstrtobuff(gv, gv->keycodes[(int)str[i]]);
			addchartobuff(gv, '>');
		}
		i++;
	}
	if (gv->pflags & FLAG_PRECISION)
	{
		j = 0;
		while (j < (gv->precision - ft_strlenfrom(str, '.')))
		{
			addstrtobuff(gv, "0");
			j++;
		}
	}
}
