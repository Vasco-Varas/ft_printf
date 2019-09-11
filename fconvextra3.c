/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fconvextra3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:09:43 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 12:01:55 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*confident_potato(char *str, char *first, size_t len, int neg)
{
	while (first[--len] == '9')
		first[len] = '0';
	len++;
	if (first[0] == '0')
	{
		str = malloc(ft_strlenfc(first) + 2);
		str[0] = '1';
		while (len < ft_strlenfc(first))
			str[len++ + 1] = '0';
		str[len + 2] = '\0';
		if (neg)
			str = insert_c(str, '-', 0);
		free(first);
		return (str);
	}
	else
	{
		first[len - 1] += 1;
		if (neg)
			first = insert_c(first, '-', 0);
	}
	return (first);
}

char		*low_carb_potato(long double n, int neg)
{
	char	*str;

	if (n < 0)
		n = -n;
	n += 1;
	n *= ft_pow(10, 7);
	str = round_potato(n);
	if (str[0] == 'P')
	{
		free(str);
		return (neg ? ft_strdup("-1") : ft_strdup("1"));
	}
	str = replace_c(str, '.', 0);
	str = insert_c(str, '0', 0);
	if (neg)
		str = insert_c(str, '-', 0);
	return (str);
}

char		*mighty_potato(long double n, char *first, size_t len, int neg)
{
	char	*str;
	char	*tmp;

	(n < 0) ? n = -n : 0;
	str = round_potato(n);
	if (str[0] == 'P')
	{
		free(str);
		return (confident_potato(str, first, len, neg));
	}
	if (len > 1)
	{
		str = str_chop2(str, 1);
		tmp = str;
		str = ft_strjoinfc(first, tmp);
		free(tmp);
		str = insert_c(str, '.', ft_strlenfc(first));
	}
	else
		str = insert_c(str, '.', ft_strlenfc(first));
	if (neg)
		str = insert_c(str, '-', 0);
	free(first);
	return (str);
}

long double	potato_magic
	(long double n, char *first, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		if (n < 0)
			n += (first[i++] - 48) * ft_pow(10, len);
		else
			n -= (first[i++] - 48) * ft_pow(10, len);
	}
	n += (n < 0) ? -1 : 1;
	return (n);
}

char		*potato_supreme(long double n, char *first, char c, int neg)
{
	char	*tmp;

	if (neg)
		first = str_chop2(first, 1);
	tmp = ft_strdupfc(first);
	if (neg)
		n += (first[0] - 48) * ft_pow(10, ft_strlenfc(first));
	else
		n -= (first[0] - 48) * ft_pow(10, ft_strlenfc(first));
	free(first);
	if (neg)
		n = -n;
	first = ft_lltoa((long long)n);
	n = potato_magic(n, first, ft_strlenfc(first));
	c = first[ft_strlenfc(first) - 1];
	free(first);
	tmp = insert_c(tmp, c, ft_strlenfc(tmp));
	n *= ft_pow(10, 7);
	return (mighty_potato(n, tmp, ft_strlenfc(tmp), neg));
}
