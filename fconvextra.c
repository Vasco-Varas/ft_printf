/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fconvextra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:08:36 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/18 14:30:29 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insert_c(char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = ft_strdupfc(s1);
	free(s1);
	s1 = malloc(ft_strlenfc(dst) + 2);
	while (i < ft_strlenfc(dst) + 1)
	{
		if (i == n)
		{
			s1[j++] = c;
			s1[j++] = dst[i++];
		}
		else
			s1[j++] = dst[i++];
	}
	s1[j] = '\0';
	free(dst);
	return (s1);
}

char	*str_chop2(char *str, int n)
{
	char	*pork;
	int		i;

	i = -1;
	if (ft_strlenfc(str) - n <= 0)
		return (NULL);
	pork = malloc(ft_strlenfc(str) - n + 1);
	pork[ft_strlenfc(str) - n] = '\0';
	while (++i < (int)ft_strlenfc(str) - n)
		pork[i] = str[i + n];
	free(str);
	str = ft_strdupfc(pork);
	free(pork);
	return (str);
}
