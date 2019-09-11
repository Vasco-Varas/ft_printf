/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fconvextra4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:10:13 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 12:02:14 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ldtoa(long double n)
{
	char		*first;
	size_t		len;
	int			neg;

	neg = (n < 0) ? 1 : 0;
	if ((long long)n == 0)
		return (low_carb_potato(n, neg));
	first = ft_lltoa((long long)n);
	if (neg)
		first = str_chop2(first, 1);
	len = ft_strlenfc(first);
	if (len > 1 && len < 19)
		n = potato_magic(n, first, len);
	else if (len == 19)
	{
		free(first);
		first = ft_lltoa((long long)(n / 10));
		return (potato_supreme(n, first, first[0], neg));
	}
	n *= ft_pow(10, 7);
	return (!n ? first : mighty_potato(n, first, len, neg));
}
