/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:22:06 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/16 13:03:53 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addstrtobuff(t_gv *gv, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		addchartobuff(gv, str[i++]);
}

int		get_prec(t_gv *gv, va_list lst)
{
	int d;

	if (gv->pflags & FLAG_AST_PREC)
	{
		d = va_arg(lst, int);
		if (d < 0)
			gv->pflags ^= FLAG_PRECISION;
		return (ft_max(d, 0));
	}
	return (gv->precision);
}

int		get_mwidth(t_gv *gv, va_list lst)
{
	int d;

	if (gv->pflags & FLAG_AST_MINW)
	{
		d = va_arg(lst, int);
		if (d < 0 && !(gv->pflags & FLAG_DASH))
			gv->pflags |= FLAG_DASH;
		return (ft_max(d, -d));
	}
	return (gv->minlen);
}

void	addstrtobuff_wlimit(t_gv *gv, char *str, int limit)
{
	int		i;

	i = 0;
	while (str[i] && limit)
	{
		addchartobuff(gv, str[i++]);
		limit--;
	}
}

void	addstrtobuff_wlimit_from(t_gv *gv, char *str, int limit, char f)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	while (str[i])
	{
		if (found)
			limit--;
		if (str[i] == f)
			found = 1;
		if ((limit >= 0 || !found) &&
		((!(limit == 0 && str[i] == f) || gv->pflags & FLAG_HASH)))
		{
			addchartobuff(gv, str[i++]);
		}
		else
			i++;
	}
}
