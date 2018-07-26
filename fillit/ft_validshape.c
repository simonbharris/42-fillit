/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:23:47 by sharris           #+#    #+#             */
/*   Updated: 2018/07/25 21:23:47 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Gets the number of adjacent tiles of a tetrimino block.
**   ...
**   #X. used on X, will == 2;
**	 .#.
*/

// TODO int		get_adjcnt()

/*
** adds number of touching sides of each individual block up (tsides)
** checks if that number is 6 or 8 (all valid tetriminos will follow this rule)
**
** numblk checks number of blocks inside each string valid must == 4
** cnt is char count of string for shape (Should == 20 + (\n || EOF)) for 21.
*/
t_shape *new_shape(void)
{
	t_shape *new;

	if (NULL == (new = (t_shape *)malloc(sizeof(t_shape))))
		return (NULL);
	new->len = 0;
	new->numblk = 0;
	new->tsides = 0;
	return (new);
}

t_shape		*ft_validshape(char **shape)
{
	int i;
	int j;
	t_shape *new;

	if (NULL == (new = new_shape()))
		return (NULL);
	i = -1;
	while (*shape[++i] != '\0' || *shape[i] != '\n')
	{
		j = -1;
		while (shape[i][++j] && j < 5)
		{
			if (VALID_CHAR(shape[i][j]) && !(j == 4 && shape[i][j] != '\n') &&
				*shape[4] == '\0' || *shape[4] != '\n')
			{
				if (shape[i][j] == '#')
				{
					new->numblk++;
					new->tsides += get_adjcnt(shape[i][j]);
				}
			}
			else
			{
				free(new);
				return (NULL);
			}	
			new->len++;
		}
	}
}
