/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:56:47 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/13 12:20:10 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getlen_biggeststr(char **pstr)
{
	int	i;
	int	o;
	int	biggest;

	i = 0;
	biggest = 0;
	while (*pstr[i])
	{
		o = 0;
		while (pstr[i][o])
			o++;
		if (biggest < o)
			biggest = o;
		i++;
	}
	return (biggest);
}

int		getlen_dpointer(char **pstr)
{
	int i;

	i = 0;
	while (*pstr[i])
		i++;
	return (i);
}

int		ilen(int i)
{
	return ((int)ft_strlen(ft_itoa(i)));
}

void	add_ox_forxconv(t_gv *gv)
{
	if (gv->pflags & FLAG_HASH)
	{
		addchartobuff(gv, '0');
	}
	if (gv->pflags & FLAG_HASH)
	{
		addchartobuff(gv, 'x');
	}
}

void	add_ox_forxconv_rem(t_gv *gv)
{
	if (gv->pflags & FLAG_HASH)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->minlen--;
	}
	if (gv->pflags & FLAG_HASH)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->minlen--;
	}
}
