/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_helper6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:16:08 by vascovaras        #+#    #+#             */
/*   Updated: 2019/03/15 10:49:11 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pl_top(t_gv *gv)
{
	gv->leng[0] = 'L';
	gv->format++;
	return (1);
}

void	pl_mid(t_gv *gv)
{
	gv->format++;
	if (*gv->format)
	{
		if (*gv->format == 'h')
			gv->leng[1] = 'h';
		else if (*gv->format == 'l')
			gv->leng[1] = 'l';
	}
}

void	setupkeycodes(t_gv *gv)
{
	gv->keycodes[0] = "NUL";
	gv->keycodes[1] = "SOH";
	gv->keycodes[2] = "STX";
	gv->keycodes[3] = "ETX";
	gv->keycodes[4] = "EOT";
	gv->keycodes[5] = "ENQ";
	gv->keycodes[6] = "ACK";
	gv->keycodes[7] = "BEL";
	gv->keycodes[8] = "BS";
	gv->keycodes[9] = "HT";
	gv->keycodes[10] = "NL";
	gv->keycodes[11] = "VT";
	gv->keycodes[12] = "NP";
	gv->keycodes[13] = "CR";
	gv->keycodes[14] = "SO";
	gv->keycodes[15] = "SI";
	gv->keycodes[16] = "DLE";
	gv->keycodes[17] = "DC1";
	gv->keycodes[18] = "DC2";
	gv->keycodes[19] = "DC3";
	setupkeycodes2(gv);
}

void	setupkeycodes2(t_gv *gv)
{
	gv->keycodes[20] = "DC4";
	gv->keycodes[21] = "NAK";
	gv->keycodes[22] = "SYN";
	gv->keycodes[23] = "ETB";
	gv->keycodes[24] = "CAN";
	gv->keycodes[25] = "EM";
	gv->keycodes[26] = "SUB";
	gv->keycodes[27] = "ESC";
	gv->keycodes[28] = "FS";
	gv->keycodes[29] = "GS";
	gv->keycodes[30] = "RS";
	gv->keycodes[31] = "US";
	gv->keycodes[127] = "DEL";
}

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
