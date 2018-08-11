/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validateshapes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:23:47 by sharris           #+#    #+#             */
/*   Updated: 2018/08/08 17:13:07 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define SHAPELEN 20

/*
** Works on 1D strings only (NOT 2D)
** returns the number of times a # symbol touched another
** Simulated a 2D array in comparison.
*/

static int	get_tsc(char *s, int i)
{
	int c;

	c = 0;
	if (s[i] == '#')
	{
		c += (i - 5 >= 0 && s[i - 5] == '#') ? 1 : 0;
		c += (i + 5 < 20 && s[i + 5] == '#') ? 1 : 0;
		c += (i - 1 >= 0 && s[i - 1] == '#') ? 1 : 0;
		c += (i + 1 < 20 && s[i + 1] == '#') ? 1 : 0;
	}
	return (c);
}

/*
** (h) == Counts the number of # symbols in a string (Must == 4).
** i == gets strlen (must == 20 == 4x4 + 3 * (\n || \0))
** 							  		^  				^
**					  	   (4x4 square)			(3 \n and or \0 chars)
** STRLEN may be 1 less since the shape may be end of file. (No \n on last shape)
** ttsc == total touching sides count. Counts the total number of times a block
** is touching another block (must == 6 || 8)
*/

static int	check_shape_params(char *s)
{
	int i;
	int h;
	int ttsc;

	i = 0;
	h = 0;
	ttsc = 0;
	while (s[i] && i < 20)
	{
		if (s[i] == '#')
			h++;
		if ((ft_mod(i + 1, 5) == 0 && (s[i] != '\n' || (i == 19 && s[i] == '\0')))
			|| ((s[i] != '#' && s[i] != '.' && s[i] != '\n'))
			|| (ft_mod(i + 1, 5) != 0 && (s[i] == '\n' || s[i] == '\0')))
			return (0);
		ttsc += get_tsc(s, i);
		i++;
	}
	if (h != 4 || (i != SHAPELEN && i != SHAPELEN - 1) || (ttsc != 6 && ttsc != 8))
		return (0);
	return (1);
}

/*
** Intakes a t_list link-list containing char * strings.
**
** ideally 20+1 null-terminated strings (Can change this by changing the
** define at the top: SHAPELEN)
*/

int			ft_validateshapes(t_list *shapes)
{
	while (shapes)
	{
		if (!check_shape_params((char *)shapes->content))
			return (0);
		shapes = shapes->next;
	}
	return (1);
}
