/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:26:11 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/13 12:29:20 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_u(t_gv *gv, va_list lst)
{
	unsigned long long	o;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_PRECISION)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->pflags ^= FLAG_ZERO;
	}
	else if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_DASH)
	{
		gv->pflags ^= FLAG_ZERO;
	}
	o = 0;
	manage_u_extra(gv, o, lst);
}

void	manage_u_extra(t_gv *gv, unsigned long long o, va_list lst)
{
	if (gv->pflags & FLAG_LENGTH)
	{
		if (ft_strncmp(gv->leng, "hh", 2))
			o = (unsigned long long)(unsigned char)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "h", 2))
			o = (unsigned long long)(unsigned short)va_arg(lst, int);
		else if (ft_strncmp(gv->leng, "l", 2))
			o = (unsigned long long)va_arg(lst, unsigned long);
		else if (ft_strncmp(gv->leng, "ll", 2))
			o = va_arg(lst, unsigned long long);
	}
	else
		o = (unsigned long long)va_arg(lst, unsigned int);
	ultoa_base(gv, (unsigned long)o, 10, 0);
}
