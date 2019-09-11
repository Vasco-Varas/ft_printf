/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:31:30 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:18:11 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_d(t_gv *gv, va_list lst)
{
	signed long long	o;
	char				*str;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
	str = "";
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "hh", 2))
			o = (signed long long)(char)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "h", 2))
			o = (signed long long)(short)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "l", 2))
			o = (signed long long)va_arg(lst, long);
		else if (ft_strncmp(gv->leng, "ll", 2))
			o = va_arg(lst, long long);
	}
	else
		o = (signed long long)va_arg(lst, int);
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_DASH)
		gv->pflags ^= FLAG_ZERO;
	manage_d_e(gv, str, o);
}

void	manage_d_e(t_gv *gv, char *str, signed long long o)
{
	int	j;

	j = 0;
	if (o < 0)
	{
		str = ft_ulltoa((unsigned long long)(o * -1ll));
		gv->minlen--;
	}
	else
		str = ft_ulltoa((unsigned long long)o);
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_PRECISION)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->pflags ^= FLAG_ZERO;
	}
	if (gv->pflags & FLAG_PRECISION && gv->precision == 0 && o == 0)
	{
		free(str);
		str = ft_strdup(str);
	}
	manage_d_ex(gv, o, str, j);
}

void	manage_d_ex(t_gv *gv, signed long long o, char *str, int j)
{
	if (gv->pflags & FLAG_DASH)
	{
		if (o >= 0)
		{
			if (gv->pflags & FLAG_PLUS)
				addchartobuff(gv, '+');
			else if (gv->pflags & FLAG_SPACE)
				addchartobuff(gv, ' ');
		}
		if (o < 0)
			addchartobuff(gv, '-');
		if (gv->pflags & FLAG_PRECISION)
		{
			j = 0;
			while (j < (gv->precision - (int)ft_strlen(str)))
			{
				addstrtobuff(gv, "0");
				j++;
			}
		}
		addstrtobuff(gv, str);
	}
	manage_d_ext(gv, o, j, str);
}

void	manage_d_ext(t_gv *gv, signed long long o, int j, char *str)
{
	if ((gv->pflags & FLAG_SPACE || gv->pflags & FLAG_PLUS) && o >= 0)
		gv->minlen--;
	if (o < 0 && !(gv->pflags & FLAG_DASH) && (gv->pflags & FLAG_ZERO))
	{
		addchartobuff(gv, '-');
	}
	if (!(gv->pflags & FLAG_DASH))
	{
		if (o >= 0 && (gv->pflags & FLAG_ZERO))
		{
			if (gv->pflags & FLAG_PLUS)
				addchartobuff(gv, '+');
			else if (gv->pflags & FLAG_SPACE)
				addchartobuff(gv, ' ');
		}
	}
	manage_d_extr(gv, j, o, str);
}

void	manage_d_extr(t_gv *gv, int j, signed long long o, char *str)
{
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen -
		ft_max((int)ft_strlen(str), gv->precision)))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? '0' : ' ');
			j++;
		}
	}
	if (o < 0 && !(gv->pflags & FLAG_DASH) && !(gv->pflags & FLAG_ZERO))
	{
		addchartobuff(gv, '-');
	}
	if (!(gv->pflags & FLAG_DASH))
	{
		if (o >= 0 && (gv->pflags & FLAG_PRECISION))
		{
			if (gv->pflags & FLAG_PLUS)
				addchartobuff(gv, '+');
			else if (gv->pflags & FLAG_SPACE)
				addchartobuff(gv, ' ');
		}
	}
	manage_d_extra(gv, j, str, o);
}
