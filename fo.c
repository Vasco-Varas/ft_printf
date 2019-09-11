/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:51:50 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:33:12 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_f(t_gv *gv, va_list lst)
{
	long double	o;
	char		*str;
	int			counttosave;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
	str = "";
	counttosave = 0;
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "l", 2))
			o = (long double)va_arg(lst, double);
		else if (ft_strncmp(gv->leng, "L", 2))
			o = va_arg(lst, long double);
	}
	else
		o = (long double)va_arg(lst, double);
	manage_f_e(gv, str, o, counttosave);
}

void	manage_f_e(t_gv *gv, char *str, long double o, int counttosave)
{
	if (!(gv->pflags & FLAG_PRECISION))
	{
		gv->pflags |= FLAG_PRECISION;
		gv->precision = 6;
	}
	str = ft_ldtoa(o);
	counttosave = addstrtobuff_wdotprec_count(gv, str, gv->precision, (int)o);
	if (gv->pflags & FLAG_DASH)
	{
		addstrtobuff_wdotprec(gv, str, gv->precision, (int)o);
		if (gv->pflags & FLAG_HASH && gv->precision == 0 &&
		gv->pflags & FLAG_PRECISION)
			addchartobuff(gv, '.');
	}
	manage_f_ex(gv, o, str, counttosave);
}

void	manage_f_ex(t_gv *gv, long double o, char *str, int counttosave)
{
	int j;

	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen - counttosave))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? '0' : ' ');
			j++;
		}
	}
	if (!(gv->pflags & FLAG_DASH))
	{
		addstrtobuff_wdotprec(gv, str, gv->precision, (int)o);
		if (gv->pflags & FLAG_HASH && gv->precision == 0 &&
		gv->pflags & FLAG_PRECISION)
			addchartobuff(gv, '.');
	}
	free(str);
}

void	manage_o(t_gv *gv, va_list lst)
{
	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_PRECISION)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->pflags ^= FLAG_ZERO;
	}
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_DASH)
	{
		gv->pflags ^= FLAG_ZERO;
	}
	manage_o_ex(gv, lst);
}

void	manage_o_ex(t_gv *gv, va_list lst)
{
	unsigned long long	o;

	o = 0;
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "hh", 2))
			o = (unsigned long long)(unsigned char)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "h", 2))
			o = (unsigned long long)(unsigned short)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "l", 2))
			o = (unsigned long long)va_arg(lst, unsigned long);
		else if (ft_strncmp(gv->leng, "ll", 2))
			o = va_arg(lst, unsigned long long);
	}
	else
		o = (unsigned long long)va_arg(lst, unsigned int);
	ultoa_base(gv, (unsigned long)o, 8, 0);
}
