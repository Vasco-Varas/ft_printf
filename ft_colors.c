/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:09:35 by vvaras            #+#    #+#             */
/*   Updated: 2019/03/15 10:33:56 by vascovaras       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_notcolor(t_gv *gv)
{
	gv->format--;
	while (*gv->format != '{')
		gv->format--;
	addstrtobuff(gv, "{");
}

void	parse_colors(t_gv *gv)
{
	char	color[MAX_COLSIZE + 1];
	int		colidx;

	ft_bzero(&color, MAX_COLSIZE);
	colidx = 0;
	while (*gv->format != '{' && *gv->format != '}'
	&& *gv->format && colidx < MAX_COLSIZE)
		color[colidx++] = *gv->format++;
	if (*gv->format == '}')
		parse_iscolor(gv, color);
	else
		parse_notcolor(gv);
}

void	parse_iscolor(t_gv *gv, char *color)
{
	parse_iscolor_txt(gv, color);
}

void	parse_iscolor_txt(t_gv *gv, char *color)
{
	if (ft_strncmpcolor(color, "black"))
		addstrtobuff(gv, TXT_BLACK);
	else if (ft_strncmpcolor(color, "red"))
		addstrtobuff(gv, TXT_RED);
	else if (ft_strncmpcolor(color, "green"))
		addstrtobuff(gv, TXT_GREEN);
	else if (ft_strncmpcolor(color, "yellow"))
		addstrtobuff(gv, TXT_YELLOW);
	else if (ft_strncmpcolor(color, "blue"))
		addstrtobuff(gv, TXT_BLUE);
	else if (ft_strncmpcolor(color, "purple"))
		addstrtobuff(gv, TXT_PURPLE);
	else if (ft_strncmpcolor(color, "cyan"))
		addstrtobuff(gv, TXT_CYAN);
	else if (ft_strncmpcolor(color, "white"))
		addstrtobuff(gv, TXT_WHITE);
	else if (ft_strncmpcolor(color, "aqua"))
		addstrtobuff(gv, TXT_AQUA);
	else
		parse_iscolor_spec(gv, color);
}

void	parse_iscolor_spec(t_gv *gv, char *color)
{
	if (ft_strncmpcolor(color, "italic"))
		addstrtobuff(gv, SPC_ITALICS);
	else if (ft_strncmpcolor(color, "underline"))
		addstrtobuff(gv, SPC_UNDERLINE);
	else if (ft_strncmpcolor(color, "background"))
		addstrtobuff(gv, SPC_BACKGROUND);
	else if (ft_strncmpcolor(color, "bold"))
		addstrtobuff(gv, SPC_BOLD);
	else if (ft_strncmpcolor(color, "eoc"))
		addstrtobuff(gv, SPEC_RESET);
	else if (ft_strncmpcolor(color, "reset"))
		addstrtobuff(gv, SPEC_RESET);
	else if (ft_strncmpcolor(color, "notacolor"))
		addstrtobuff(gv,
		" did you mean that i should not print anything at all? ");
	else
		parse_notcolor(gv);
}
