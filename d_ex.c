/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ex.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:17:04 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:17:10 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_d_extra(t_gv *gv, int j, char *str, signed long long o)
{
	if ((gv->pflags & FLAG_PRECISION) && !(gv->pflags & FLAG_DASH))
	{
		j = 0;
		while (j < (gv->precision - (int)ft_strlen(str)))
		{
			addstrtobuff(gv, "0");
			j++;
		}
	}
	if (!(gv->pflags & FLAG_DASH))
	{
		if (o >= 0 && !(gv->pflags & FLAG_ZERO) &&
		!(gv->pflags & FLAG_PRECISION))
		{
			if (gv->pflags & FLAG_PLUS)
				addchartobuff(gv, '+');
			else if (gv->pflags & FLAG_SPACE)
				addchartobuff(gv, ' ');
		}
		addstrtobuff(gv, str);
	}
	free(str);
}
