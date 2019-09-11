/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:57:30 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/16 13:01:53 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_e(t_gv *gv, va_list lst)
{
	int			j;
	long double	o;
	char		*str;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
	j = 0;
	str = "";
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "l", 2))
			o = (long double)va_arg(lst, double);
		else if (ft_strncmp(gv->leng, "L", 2))
			o = va_arg(lst, long double);
	}
	else
		o = (long double)va_arg(lst, double);
	manage_e_e(gv, str, j, o);
}

void	manage_e_e(t_gv *gv, char *str, int j, long double o)
{
	str = cnot(o, gv);
	if (gv->pflags & FLAG_MINWIDTH)
	{
		j = 0;
		while (j < (int)(gv->minlen - ft_strlen(str) - (gv->pflags & FLAG_PLUS
		|| gv->pflags & FLAG_SPACE) -
		ft_max((int)ft_strlen(gv->cnotat),
		ft_strlento(gv->cnotat, '.') - 1 + gv->precision)))
		{
			addstrtobuff(gv, " ");
			j++;
		}
	}
	manage_e_ex(gv, o, j, str);
}

void	manage_e_ex(t_gv *gv, long double o, int j, char *str)
{
	if (gv->pflags & FLAG_PLUS && o >= 0)
		addchartobuff(gv, '+');
	else if (gv->pflags & FLAG_SPACE && o >= 0)
		addchartobuff(gv, ' ');
	if (gv->pflags & FLAG_PRECISION)
		addstrtobuff_wlimit_from(gv, gv->cnotat, gv->precision, '.');
	else
		addstrtobuff(gv, gv->cnotat);
	if (gv->pflags & FLAG_PRECISION)
	{
		j = 0;
		while (j < (gv->precision - ft_strlenfrom(gv->cnotat, '.')))
		{
			addstrtobuff(gv, "0");
			j++;
		}
	}
	addstrtobuff(gv, str);
	free(str);
	free(gv->cnotat);
}

char	*ft_strjoin_fl(char const *s1, char *s2)
{
	int		i;
	char	*str;
	char	*s2p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s2p = s2;
	str = (char*)malloc(sizeof(char) *
		(ft_strlen((char *)s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(s2p);
	return (str);
}
