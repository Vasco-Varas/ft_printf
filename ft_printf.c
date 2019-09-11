/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:27:17 by vvaras            #+#    #+#             */
/*   Updated: 2019/03/18 13:56:32 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_gv	gv;

	ft_bzero(&gv, sizeof(gv));
	setupkeycodes(&gv);
	gv.fd = 1;
	if (format == NULL)
		return (0);
	gv.format = (char *)format;
	va_start(gv.ap, format);
	while (*gv.format)
	{
		if (*gv.format == '%' || *gv.format == '{')
			parse_stuff(&gv);
		else
			addtobuff(&gv);
		gv.format++;
	}
	va_end(gv.ap);
	return (gv.pbufflen - gv.takeout);
}

int			ft_printfd(int fd, const char *format, ...)
{
	t_gv	gv;
	int		ret;

	ft_bzero(&gv, sizeof(gv));
	setupkeycodes(&gv);
	gv.fd = fd;
	if (format == NULL)
		return (0);
	gv.format = (char *)format;
	va_start(gv.ap, format);
	while (*gv.format)
	{
		if (*gv.format == '%' || *gv.format == '{')
			parse_stuff(&gv);
		else
			addtobuff(&gv);
		gv.format++;
	}
	va_end(gv.ap);
	ret = gv.pbufflen - gv.takeout;
	return (ret);
}

void		addtobuff(t_gv *gv)
{
	gv->pbufflen++;
	write(gv->fd, gv->format, 1);
}

void		addchartobuff(t_gv *gv, char c)
{
	gv->pbufflen++;
	write(gv->fd, &c, 1);
}

int			ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
