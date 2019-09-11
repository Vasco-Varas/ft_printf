/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fconvextra2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:09:18 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:23:17 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_pow(long double base, long double ex)
{
	long double	res;

	res = 1;
	if (!ex)
		return (1);
	while (ex-- != 0)
		res *= base;
	return (res);
}

char		*ft_lltoa(long long n)
{
	char *str;
	char *t;
	char *u;

	if (!(str = (char *)malloc(30)))
		return (NULL);
	t = str;
	(n < 0 ? *t++ = '-' : 1);
	if (n > 0)
		n = -n;
	if (n <= -10)
	{
		u = ft_lltoa(-(n / 10));
		free(u);
		while (*u)
			*t++ = *u++;
	}
	*t = '0' - n % 10;
	*(t + 1) = '\0';
	return (str);
}

char		*replace_c(char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	dst = malloc(ft_strlenfc(s1) + 1);
	while (i < ft_strlenfc(s1))
	{
		if (i == n)
		{
			dst[j++] = c;
			i++;
		}
		else
			dst[j++] = s1[i++];
	}
	dst[j] = '\0';
	free(s1);
	s1 = ft_strdupfc(dst);
	free(dst);
	return (s1);
}

char		*self_conscious_potato(char *str, int i)
{
	while (str[i] == '9' && (i - 1))
	{
		if (str[i - 1] != '9')
		{
			str[i] = '0';
			str[i - 1] += 1;
			break ;
		}
		else
			str[i--] = '0';
		if (str[i] == '0')
			str[i] = '1';
	}
	return (str);
}

char		*round_potato(long double n)
{
	char	*str;
	int		i;

	i = 7;
	str = ft_lltoa((long long)n);
	if (str[1] == '9' && str[2] == '9' && str[3] == '9' && str[4] == '9'
		&& str[5] == '9' && str[6] == '9' && str[7] > '4')
	{
		str[0] = 'P';
		while (--i)
			str[i] = '0';
	}
	else if (str[7] > '4' && str[6] == '9')
		str = self_conscious_potato(str, i - 1);
	else if (str[7] > '4' && str[6] != '9')
		str[6] += 1;
	str[7] = '\0';
	return (str);
}
