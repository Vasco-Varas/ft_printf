/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:13:44 by vvaras            #+#    #+#             */
/*   Updated: 2019/03/15 10:41:08 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_specifics(t_gv *gv)
{
	int	i;

	i = 0;
	if (*gv->format)
	{
		return (parse_specifics_e(gv, i));
	}
	else
		return (0);
}

int		parse_specifics_e(t_gv *gv, int i)
{
	va_list vlist;

	va_copy(vlist, gv->ap);
	if (gv->pflags & FLAG_ACCESS)
		while (i++ < gv->access - 1)
			va_arg(vlist, void *);
	if (*gv->format == 'd' || *gv->format == 'i')
		manage_d(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'o')
		manage_o(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'u')
		manage_u(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'x')
		manage_x(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'X')
		manage_ux(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'e')
		manage_e(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'f')
		manage_f(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else
		return (parse_specifics_ex(gv, vlist));
	va_end(vlist);
	return (1);
}

int		parse_specifics_ex(t_gv *gv, va_list vlist)
{
	if (*gv->format == 'c')
		manage_c(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 's')
		manage_s(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'p')
		manage_p(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'b')
		manage_b(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'r')
		manage_r(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'k')
		manage_k(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'v')
		manage_v(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == 'y')
		manage_y(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else if (*gv->format == '%')
		manage_pers(gv, gv->pflags & FLAG_ACCESS ? vlist : gv->ap);
	else
	{
		va_end(vlist);
		return (0);
	}
	va_end(vlist);
	return (1);
}
