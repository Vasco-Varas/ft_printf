/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:56:47 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/23 10:31:52 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_s(t_gv *gv, va_list lst)
{
	int		j;
	char	*o;
	int		minwidth;

	j = 0;
	minwidth = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = va_arg(lst, char *);
	if (o == NULL)
		o = "(null)";
	if (gv->pflags & FLAG_DASH)
	{
		if (gv->pflags & FLAG_ZERO)
			gv->pflags ^= FLAG_ZERO;
		if (gv->pflags & FLAG_PRECISION)
			addstrtobuff_wlimit(gv, o, gv->precision);
		else
			addstrtobuff(gv, o);
	}
	manage_s_helper(gv, j, o, minwidth);
}

void	manage_s_helper(t_gv *gv, int j, char *o, int minwidth)
{
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < minwidth - ((gv->pflags & FLAG_PRECISION)
		? ft_min(gv->precision, (int)ft_strlen(o)) : (int)ft_strlen(o)))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? '0' : ' ');
			j++;
		}
	}
	if (!(gv->pflags & FLAG_DASH))
	{
		if (gv->pflags & FLAG_PRECISION)
			addstrtobuff_wlimit(gv, o, gv->precision);
		else
			addstrtobuff(gv, o);
	}
}

void	manage_p(t_gv *gv, va_list lst)
{
	int		j;
	void	*o;
	char	*hex;

	j = 0;
	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = va_arg(lst, void *);
	hex = dec_to_hexa((unsigned long long)o, 'a',
	(gv->pflags & FLAG_PRECISION) && (gv->precision == 0));
	if (gv->pflags & FLAG_DASH)
	{
		if (gv->pflags & FLAG_ZERO)
			gv->pflags ^= FLAG_ZERO;
		addstrtobuff(gv, "0x");
		add_prec_str(gv, hex);
		addstrtobuff(gv, hex);
	}
	manage_p_helper(gv, j, hex);
}

void	manage_p_helper(t_gv *gv, int j, char *hex)
{
	if (gv->pflags & FLAG_MINWIDTH)
	{
		if (gv->pflags & FLAG_ZERO && !(gv->pflags & FLAG_PRECISION))
		{
			addstrtobuff(gv, "0x");
			j = 0;
			while (j + 2 < (gv->minlen -
			ft_max((int)ft_strlen(hex), gv->precision)))
			{
				addstrtobuff(gv, "0");
				j++;
			}
		}
		else
			manage_p_helper_else(gv, j, hex);
	}
	manage_p_helper_2(gv, hex);
}

void	manage_p_helper_2(t_gv *gv, char *hex)
{
	if (!(gv->pflags & FLAG_MINWIDTH) && (!(gv->pflags & FLAG_DASH)))
		addstrtobuff(gv, "0x");
	if (!(gv->pflags & FLAG_DASH))
	{
		add_prec_str(gv, hex);
		addstrtobuff(gv, hex);
	}
	free(hex);
}
