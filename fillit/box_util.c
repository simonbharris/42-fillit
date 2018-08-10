/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:40:14 by sharris           #+#    #+#             */
/*   Updated: 2018/08/09 19:10:34 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Generates a square char** filled with '.' char
** Deals with memory leaks in case of bad malloc
*/

char **malloc_fillit_box(int size)
{
	char **box;
	int i;

	i = 0;
	if (NULL == (box = (char **)ft_memalloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (NULL == (box[i] = (char *)ft_memalloc(sizeof(char) * size + 1)))
			while (--i >= 0)
			{
				free(box[i]);
				return (NULL);
			}
		box[i] = ft_memset(box[i], '.', size);
		i++;
	}
	box[i] = ft_strnew(size + 1);
	return (box);
}

/*
** Deletes a (char **) from memory.
** The array must be terminated by an empty string.
*/

void ft_delbox(char ***box)
{
	int i;

	i = 0;
	while (box[0][i][0])
		ft_memdel((void **)&(box[0][i++]));
	ft_memdel((void **)&(box[0][i++]));
	ft_memdel((void **)*box);
	*box = NULL;
}
