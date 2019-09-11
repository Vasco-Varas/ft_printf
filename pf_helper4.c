/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:33:20 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:47:40 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ast(t_gv *gv, int *len)
{
	if (gv->format[*len] == '*')
	{
		(*len)++;
		if (!ft_isdigit(gv->format[*len]))
		{
			gv->pflags |= FLAG_AST_MINW;
			gv->pflags |= FLAG_MINWIDTH;
		}
		else
			(void)va_arg(gv->ap, int);
	}
}

void	check_mwidth(t_gv *gv, int *len, char *minwid)
{
	while (ft_isdigit(gv->format[*len]))
	{
		minwid[*len] = gv->format[*len];
		(*len)++;
	}
}

int		parse_minwidth(t_gv *gv)
{
	int		i;
	int		len;
	char	minwid[countdigits(gv) + 1];

	len = 0;
	ft_bzero(minwid, (size_t)countdigits(gv) + 1);
	check_mwidth(gv, &len, minwid);
	check_ast(gv, &len);
	minwid[len] = '\0';
	if (len >= 1)
	{
		i = ft_atoi(minwid);
		gv->minlen = i;
		gv->pflags |= FLAG_MINWIDTH;
		gv->format += len;
	}
	return (gv->format[0] == '*' || ft_isdigit(gv->format[0]));
}

int		parse_precision(t_gv *gv)
{
	int		len;
	int		i;
	char	*prec;

	if (*gv->format == '.')
	{
		pp_hat(gv);
		len = countdigits(gv);
		if (len >= 1)
		{
			prec = (char *)malloc(sizeof(char) * (len + 1));
			ft_bzero(prec, (size_t)len + 1);
			if (prec == NULL)
				return (0);
			i = 0;
			pp_mid(gv, prec, i, len);
		}
		else
		{
			if (*gv->format == '*')
				return (pp_top(gv));
			gv->precision = 0;
		}
	}
	return (1);
}

void	pp_hat(t_gv *gv)
{
	gv->pflags |= FLAG_PRECISION;
	gv->format++;
}
