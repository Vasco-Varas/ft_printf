/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:13:23 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 12:23:22 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_x(t_gv *gv, va_list lst)
{
	unsigned long long	o;
	char				*hex;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
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
	{
		o = (unsigned long long)(unsigned int)va_arg(lst, void *);
	}
	hex = dec_to_hexa(o, 'a', gv->precision == 0 &&
	gv->pflags & FLAG_PRECISION);
	manage_xx_ex(gv, o, hex);
}

void	manage_ux(t_gv *gv, va_list lst)
{
	unsigned long long	o;
	char				*hex;

	gv->minlen = get_mwidth(gv, lst);
	gv->precision = get_prec(gv, lst);
	o = 0;
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
	{
		o = (unsigned long long)(unsigned int)va_arg(lst, void *);
	}
	hex = dec_to_hexa(o, 'A', gv->precision == 0 &&
	gv->pflags & FLAG_PRECISION);
	manage_xx_ex(gv, o, hex);
}

void	manage_xx_ex(t_gv *gv, unsigned long long o, char *hex)
{
	if (gv->pflags & FLAG_ZERO && gv->pflags & FLAG_PRECISION)
	{
		if (gv->pflags & FLAG_MINWIDTH)
			gv->pflags ^= FLAG_ZERO;
	}
	if (o != 0)
		add_ox_forxconv_rem(gv);
	if (gv->pflags & FLAG_DASH)
	{
		if (o != 0)
			add_ox_forxconv(gv);
		add_prec_str(gv, hex);
		addstrtobuff(gv, hex);
		add_mwidth_str(gv, ' ', hex, ' ');
	}
	else
	{
		manage_xx_ext(gv, hex, o);
	}
	free(hex);
}

void	manage_xx_ext(t_gv *gv, char *hex, unsigned long long o)
{
	if (!(gv->pflags & FLAG_PRECISION))
		if (gv->pflags & FLAG_ZERO)
			if (o != 0)
				add_ox_forxconv(gv);
	add_mwidth_str(gv, '0', hex, ' ');
	if (!(gv->pflags & FLAG_ZERO) || gv->pflags & FLAG_PRECISION)
		if (o != 0)
			add_ox_forxconv(gv);
	add_prec_str(gv, hex);
	addstrtobuff(gv, hex);
}
