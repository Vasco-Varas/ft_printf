/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:41:32 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:48:42 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pp_top(t_gv *gv)
{
	gv->pflags |= FLAG_AST_PREC;
	gv->format++;
	return (1);
}

void	pp_mid(t_gv *gv, char *prec, int i, int len)
{
	while (ft_isdigit(gv->format[i]))
	{
		prec[i] = gv->format[i];
		i++;
	}
	gv->precision = ft_atoi(prec);
	free(prec);
	gv->format += len;
}

int		parse_length(t_gv *gv)
{
	ft_bzero(&gv->leng, 3);
	if (*gv->format)
	{
		if (*gv->format == 'l')
			gv->leng[0] = 'l';
		else if (*gv->format == 'L')
			return (pl_top(gv));
		else if (*gv->format == 'h')
			gv->leng[0] = 'h';
		else
			return (1);
		pl_mid(gv);
		gv->format++;
		if (ft_strncmp(gv->leng, "hh", 2)
		|| ft_strncmp(gv->leng, "ll", 2))
			return (pl_mbot(gv));
		if (ft_strncmp(gv->leng, "h", 2)
		|| ft_strncmp(gv->leng, "l", 2))
			return (pl_bot(gv));
		gv->format -= 2;
		return (0);
	}
	return (1);
}

int		pl_mbot(t_gv *gv)
{
	gv->pflags |= FLAG_LENGTH;
	return (1);
}

int		pl_bot(t_gv *gv)
{
	gv->format--;
	gv->pflags |= FLAG_LENGTH;
	return (1);
}
