/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vextra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:04:23 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 11:50:03 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_v_add_top_2(t_gv *gv, int j, int lendp, int i)
{
	j = 0;
	if (gv->pflags & FLAG_PRECISION)
	{
		while (j++ < lendp - ilen(i + gv->precision))
			addchartobuff(gv, ' ');
	}
}

void	manage_v_add_bottom(t_gv *gv, char **o, int greatstr, int i)
{
	int j;

	j = 0;
	if (*o[i + 1])
	{
		addchartobuff(gv, '|');
		while (j++ < greatstr + 1)
			addchartobuff(gv, '-');
		addchartobuff(gv, '|');
		addchartobuff(gv, '\n');
	}
}

void	manage_v_add_ubottom(t_gv *gv, int greatstr)
{
	int j;

	j = 0;
	addchartobuff(gv, '|');
	while (j++ < greatstr + 1)
		addchartobuff(gv, '=');
	addstrtobuff(gv, "|\n");
}
