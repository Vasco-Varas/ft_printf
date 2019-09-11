/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:03:37 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:16:19 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_c(t_gv *gv, va_list lst)
{
	char	o;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = (char)va_arg(lst, int);
	if (gv->pflags & FLAG_DASH)
		addchartobuff(gv, o);
	add_mwidth(gv, '0');
	if (!(gv->pflags & FLAG_DASH))
		addchartobuff(gv, o);
}

void	manage_v(t_gv *gv, va_list lst)
{
	char	**o;
	int		greatstr;
	int		lendp;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = va_arg(lst, char **);
	lendp = ilen(getlen_dpointer(o) + gv->precision);
	greatstr = getlen_biggeststr(o) + lendp + 2;
	if (!(gv->pflags & FLAG_PRECISION))
	{
		greatstr -= (lendp + 1);
		lendp = -1;
	}
	if (gv->pflags & FLAG_MINWIDTH)
		if (greatstr < gv->minlen)
			greatstr = gv->minlen;
	manage_v_helper(gv, greatstr, lendp, o);
}

void	manage_v_helper(t_gv *gv, int greatstr, int lendp, char **o)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	manage_v_add_utop(gv, greatstr, j);
	while (*o[i])
	{
		manage_v_add_top(gv, i);
		manage_v_add_top_2(gv, j, lendp, i);
		addstrtobuff(gv, o[i]);
		j = 0;
		while ((int)ft_strlen(o[i]) + j < greatstr - lendp - 1)
		{
			j++;
			addchartobuff(gv, ' ');
		}
		j = 0;
		addstrtobuff(gv, "|\n");
		manage_v_add_bottom(gv, o, greatstr, i);
		i++;
	}
	manage_v_add_ubottom(gv, greatstr);
}

void	manage_v_add_utop(t_gv *gv, int greatstr, int j)
{
	addstrtobuff(gv, "\n|");
	while (j++ < greatstr + 1)
		addchartobuff(gv, '=');
	addstrtobuff(gv, "|\n");
}

void	manage_v_add_top(t_gv *gv, int i)
{
	addstrtobuff(gv, "| ");
	if (gv->pflags & FLAG_PRECISION)
	{
		addstrtobuff(gv, ft_itoa(i + gv->precision));
		addchartobuff(gv, ':');
	}
}
