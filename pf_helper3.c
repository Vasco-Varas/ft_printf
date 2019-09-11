/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:29:38 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 12:21:00 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) *
			(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void		parse_stuff(t_gv *gv)
{
	if (*gv->format == '%')
	{
		gv->pflags = 0;
		gv->format++;
		if (parse_access(gv))
		{
			if (gv->pflags & FLAG_ACCESS)
				gv->pflags = FLAG_ACCESS;
			else
				gv->pflags = 0;
			parse_flags(gv);
			while (parse_minwidth(gv))
			{
			}
			if (parse_precision(gv))
				if (parse_length(gv))
					if (parse_specifics(gv))
						return ;
			gv->format--;
		}
		return ;
	}
	gv->format++;
	parse_colors(gv);
}

int			parse_access(t_gv *gv)
{
	int		i;
	char	access[MAX_ACCESSLEN];

	i = 0;
	gv->access = 0;
	while (i < MAX_ACCESSLEN && ft_isdigit(gv->format[i]))
	{
		access[i] = gv->format[i];
		i++;
	}
	if (gv->format[i] == '$')
	{
		gv->access = ft_atoi(access);
		if (gv->access > 127)
		{
			gv->access = 0;
			return (0);
		}
		gv->format += i + 1;
		gv->pflags |= FLAG_ACCESS;
		return (1);
	}
	return (1);
}

void		parse_flags(t_gv *gv)
{
	while (*gv->format == '#' || *gv->format == '0' || *gv->format == '-'
	|| *gv->format == '+' || *gv->format == ' ' || *gv->format == '\'')
	{
		if (*gv->format == '#')
			gv->pflags |= FLAG_HASH;
		else if (*gv->format == '0')
			gv->pflags |= FLAG_ZERO;
		else if (*gv->format == '-')
			gv->pflags |= FLAG_DASH;
		else if (*gv->format == '+')
			gv->pflags |= FLAG_PLUS;
		else if (*gv->format == ' ')
			gv->pflags |= FLAG_SPACE;
		else if (*gv->format == '\'')
			gv->pflags |= FLAG_QUOTE;
		gv->format++;
	}
}

int			countdigits(t_gv *gv)
{
	int		len;

	len = 0;
	while (ft_isdigit(gv->format[len]))
		len++;
	return (len);
}
