/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:40:14 by sharris           #+#    #+#             */
/*   Updated: 2018/07/29 19:40:14 by sharris          ###   ########.fr       */
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
	box[i] = ft_strdup("");
	return (box);
}

// char *solve_fillit(t_list *shapes)
// {
// 	int size;
// 	char **solution;
// 	char **box;

// 	size = 2;
// 	while ((solution = solve(size, shapes)) != NULL)
// 	{
// 		size++;
// 	}
// }

/*

* What we have so far:
	Read from file
	Break shapes into a link-list
	Verify + optimize string contents as a valid link-list.

Todo: Create function to drop a piece into a larger pre-alloced box of '.'
Todo: Create backtrack-recursive funciton for solve (Or an alternative algorithm)
	Start with a box of 2x2, increase in size by 1 if no solution is found.
	When being placed, pieces needs to be placed with an alpha character representing their original order.
	Repeat until solution is found.
	return solved puzzle (char**)?	
todo: Print out solved board.

*/