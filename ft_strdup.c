/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:28:23 by vvaras            #+#    #+#             */
/*   Updated: 2019/02/15 16:22:32 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*retstring;

	len = (int)ft_strlen((char *)s1);
	retstring = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (retstring == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strcpy(retstring, s1);
	return (retstring);
}
