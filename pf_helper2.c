/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:22:35 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 12:19:40 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addstrtobuff_wdotprec(t_gv *gv, char *str, int prec, int o)
{
	int		i;
	int		dot;

	dot = 0;
	i = 0;
	if (gv->pflags & FLAG_PLUS && o >= 0)
		addchartobuff(gv, '+');
	else if (gv->pflags & FLAG_SPACE && o >= 0)
		addchartobuff(gv, ' ');
	while (str[i] && (prec || !dot))
	{
		if (dot)
			prec--;
		if (str[i] == '.')
		{
			dot = 1;
			if (prec)
				addchartobuff(gv, str[i++]);
		}
		else
			addchartobuff(gv, str[i++]);
	}
	addstrtobuff_wdotprec_e(gv, prec, dot);
}

void	addstrtobuff_wdotprec_e(t_gv *gv, int prec, int dot)
{
	if (!dot)
		addchartobuff(gv, '.');
	while (prec)
	{
		addchartobuff(gv, '0');
		prec--;
	}
}

int		addstrtobuff_wdotprec_count(t_gv *gv, char *str, int prec, int o)
{
	int		dot;
	int		count;

	dot = 0;
	count = 0;
	if ((gv->pflags & FLAG_SPACE || gv->pflags & FLAG_PLUS) && o >= 0)
		count++;
	return (addstrtobuff_wdotprec_count_e(str, prec, dot, count));
}

int		addstrtobuff_wdotprec_count_e
	(char *str, int prec, int dot, int count)
{
	int		i;

	i = 0;
	while (str[i] && (prec || !dot))
	{
		if (dot)
			prec--;
		if (str[i] == '.')
		{
			dot = 1;
			if (prec)
				count++;
		}
		else
			count++;
		i++;
	}
	if (!dot)
		count++;
	while (prec)
	{
		count++;
		prec--;
	}
	return (count);
}

double	ft_power(double num, int pow)
{
	return (pow ? num * ft_power(num, pow - 1) : 1);
}
