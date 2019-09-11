/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:21:37 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/16 13:07:26 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*dec_to_hexa(unsigned long long n, char strt, int gv)
{
	char	hexa_deci_num[17];
	int		i;
	int		rem;
	char	*hex;

	if (n == 0)
		return (dec_to_hexa_prp(gv));
	hex = (char *)malloc(sizeof(char) * 17);
	ft_bzero(&hexa_deci_num, 17);
	ft_bzero(hex, 17);
	i = 0;
	while (n != 0)
	{
		rem = n % 16;
		if (rem < 10)
		{
			hexa_deci_num[i++] = rem + '0';
		}
		else
		{
			hexa_deci_num[i++] = (rem - 10) + strt;
		}
		n = n / 16;
	}
	return (dec_to_hexa_e(hex, hexa_deci_num, i));
}

char		*dec_to_hexa_prp(int gv)
{
	if (gv)
		return (ft_strdup(""));
	else
		return (ft_strdup("0"));
}

char		*dec_to_hexa_e
	(char *hex, char *hexa_deci_num, int i)
{
	int o;

	o = 0;
	while (i > 0)
	{
		hex[o] = hexa_deci_num[i - 1];
		i--;
		o++;
	}
	return (hex);
}

char		*cnot(long double n, t_gv *gv)
{
	int		ex;
	char	*cnota;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	n = (neg) ? -n : n;
	ex = 0;
	while (n >= 10)
	{
		ex++;
		n /= 10;
	}
	while (n < 1 && n != 0)
	{
		ex--;
		n *= 10;
	}
	cnota = ft_ldtoa(n);
	return (cnot_e(gv, neg, cnota, ex));
}

char		*cnot_e(t_gv *gv, int neg, char *cnota, int ex)
{
	char	*cnotat;

	if (neg)
	{
		cnotat = ft_strjoin("-", cnota);
		free(cnota);
	}
	else
		cnotat = cnota;
	gv->cnotat = cnotat;
	if (ex <= -10)
		cnotat = ft_strjoin_fl("e-", ft_itoa(ex * -1));
	else if (ex < 0)
		cnotat = ft_strjoin_fl("e-0", ft_itoa(ex * -1));
	else if (ex < 10)
		cnotat = ft_strjoin_fl("e+0", ft_itoa(ex));
	else
		cnotat = ft_strjoin_fl("e+", ft_itoa(ex));
	return (cnotat);
}
