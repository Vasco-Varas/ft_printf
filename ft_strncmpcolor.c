/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmpcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaras <vvaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:28:24 by vvaras            #+#    #+#             */
/*   Updated: 2019/01/16 14:11:36 by vvaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmpcolor(const char *col1, const char *col2)
{
	size_t i;

	i = 0;
	while (i < MAX_COLSIZE)
	{
		if (col1[i] == '\0' && col2[i] == '\0')
			return (1);
		if (col1[i] != col2[i])
			return (0);
		i++;
	}
	return (0);
}
