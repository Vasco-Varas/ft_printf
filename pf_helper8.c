/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:07:09 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/16 13:06:58 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlento(char *s, char c)
{
	int		lenght;

	lenght = 0;
	while (*s != c && *s != '\0')
	{
		lenght++;
		s++;
	}
	return (lenght);
}

int		ft_strlenfrom(char *s, char c)
{
	return ((int)ft_strlen(s + ft_strlento(s, c) + 1));
}

char	*ft_ulltoa(unsigned long long n)
{
	unsigned long long		tmpn;
	unsigned int			len;
	char					*str;

	tmpn = n;
	len = 2;
	while (tmpn /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void    manage_p_helper_else(t_gv *gv, int j, char *hex)
{
	j = 0;
	while (j + 2 < (gv->minlen -
	                ft_max((int)ft_strlen(hex), gv->precision)))
	{
		addstrtobuff(gv, " ");
		j++;
	}
	if (!(gv->pflags & FLAG_DASH))
		addstrtobuff(gv, "0x");
}
