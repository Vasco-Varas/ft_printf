/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pers.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:59:00 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/18 13:54:12 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_pers(t_gv *gv, va_list lst)
{
	int			j;
	char		str[2];

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	str[0] = '%';
	str[1] = '\0';
	if (gv->pflags & FLAG_DASH)
	{
		addstrtobuff(gv, str);
		if (gv->pflags & FLAG_ZERO)
			gv->pflags ^= FLAG_ZERO;
	}
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (gv->minlen -
		(int)ft_strlen(str)))
		{
			addstrtobuff(gv, (gv->pflags & FLAG_ZERO) ? "0" : " ");
			j++;
		}
	}
	if (!(gv->pflags & FLAG_DASH))
		addstrtobuff(gv, str);
}

void	manage_r(t_gv *gv, va_list lst)
{
	int		j;
	char	*str;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	str = va_arg(lst, char *);
	j = 0;
	if (gv->pflags & FLAG_MINWIDTH)
	{
		while (j < (gv->minlen - (int)ft_strlen(str) -
		(gv->pflags & FLAG_PRECISION && gv->precision >\
		ft_strlenfrom(str, '.') ? gv->precision -
		ft_strlenfrom(str, '.') : 0)))
		{
			addchartobuff(gv, ' ');
			j++;
		}
	}
	manage_r_ex(gv, str, j);
}

void	manage_r_ex(t_gv *gv, char *str, int j)
{
	int i;

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
			addchartobuff(gv, '0');
			j++;
		}
	}
}

void	manage_y(t_gv *gv, va_list lst)
{
	int		i;
	char	*a;

	i = va_arg(lst, int);
	a = ft_itoa(i);
	addstrtobuff(gv, "\033[38;5;");
	addstrtobuff(gv, a);
	addstrtobuff(gv, "m");
	free(a);
}
