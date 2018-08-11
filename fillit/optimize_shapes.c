/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:21:25 by sharris           #+#    #+#             */
/*   Updated: 2018/08/11 05:26:12 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	shift_shape(char **str, int c)
{
	char *start;
	char *seek;

	start = *str;
	seek = ft_strchr(start, (int)'#');
	if ((seek - start + 4 < 20 && seek[4] == '#') || (seek - start + 9 < 20 &&
		seek[9] == '#'))
		seek -= (seek[3] == '#') ? 2 : 1;
	while (*seek)
	{
		if (*seek == '\n')
			seek++;
		if (*start == '\n')
			start++;
		if ((*start == '.' && *seek == '#') || (*start == '#' && *seek == '#'))
		{
			*start = (char)c;
			if (*seek == '#')
				*seek = '.';
		}
		start++;
		seek++;
	}
}

/*
** Iterates through the shift_shapes call, re-organizing the string structure.
** Places "blocks" in most top-left position. Accepts input from t_lists
** validated via ft_validateshapes();
*/

void		optimize_shapes(t_list *lst)
{
	int alpha;

	alpha = 'A';
	while (lst)
	{
		shift_shape((char **)&lst->content, alpha);
		lst = lst->next;
		alpha = alpha + 1;
	}
}
