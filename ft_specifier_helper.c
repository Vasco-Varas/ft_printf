/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:55:43 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:39:39 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_mwidth(t_gv *gv, char ifzero)
{
	int	j;

	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen - 1 -
		(gv->pflags & FLAG_PRECISION && gv->precision >
		1 ? gv->precision - 1 : 0)))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? ifzero : ' ');
			j++;
		}
	}
}

void	add_mwidth_str(t_gv *gv, char ifzero, char *str, char nozero)
{
	int	j;

	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen -
		ft_max(gv->precision, (int)ft_strlen(str))))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? ifzero : nozero);
			j++;
		}
	}
}

void	add_prec_str(t_gv *gv, char *str)
{
	int	j;

	if (gv->pflags & FLAG_PRECISION)
	{
		j = 0;
		while (j < (gv->precision - (int)ft_strlen(str)))
		{
			addchartobuff(gv, '0');
			j++;
		}
	}
}
