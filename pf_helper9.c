/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:07:44 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/18 13:55:56 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ultoa_base(t_gv *gv, unsigned long num, int base, int is_upper)
{
	char			*tab;
	unsigned long	temp_nbr;
	char			*str;
	int				size;
	int				j;

	tab = (is_upper) ? "0123456789ABCDEF" : "0123456789abcdef";
	temp_nbr = num;
	size = 1;
	j = 0;
	while (temp_nbr /= base)
		size++;
	temp_nbr = num;
	if (*gv->format == 'o')
		if (gv->pflags & FLAG_HASH)
			size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	str[size] = '\0';
	while (size--)
	{
		str[size] = tab[(num % base)];
		num /= base;
	}
	ultoa_base_ext(gv, j, str, temp_nbr);
}

void		ultoa_base_ext(t_gv *gv, int j, char *str, unsigned long temp_nbr)
{
	if (gv->pflags & FLAG_DASH)
	{
		if (gv->pflags & FLAG_PRECISION)
		{
			j = 0;
			while (j < (gv->precision - (int)ft_strlen(str)))
			{
				addchartobuff(gv, '0');
				j++;
			}
		}
		if (temp_nbr == (unsigned long)0)
			addchartobuff(gv, '0');
		else
			addstrtobuff(gv, str);
	}
	ultoa_base_e(gv, j, temp_nbr, str);
}

void		ultoa_base_e(t_gv *gv, int j, unsigned long temp_nbr, char *str)
{
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = -(temp_nbr == (unsigned long)0 &&
		(gv->pflags & FLAG_PRECISION && gv->precision == 0) &&
		!(gv->pflags & FLAG_HASH));
		while (j < (gv->minlen -
		ft_max((int)ft_strlen(str), gv->precision)))
		{
			addchartobuff(gv, (gv->pflags & FLAG_ZERO) ? '0' : ' ');
			j++;
		}
	}
	if (gv->pflags & FLAG_PRECISION && !(gv->pflags & FLAG_DASH))
	{
		j = 0;
		while (j < (gv->precision - (int)ft_strlen(str)))
		{
			addstrtobuff(gv, "0");
			j++;
		}
	}
	ultoa_base_ex(gv, temp_nbr, str);
}

void		ultoa_base_ex(t_gv *gv, unsigned long temp_nbr, char *str)
{
	if (!(gv->pflags & FLAG_DASH))
	{
		if (temp_nbr == (unsigned long)0)
		{
			if (!(gv->pflags & FLAG_PRECISION &&
			gv->precision == 0 && !(gv->pflags & FLAG_HASH)))
				addchartobuff(gv, '0');
		}
		else
			addstrtobuff(gv, str);
	}
	free(str);
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
