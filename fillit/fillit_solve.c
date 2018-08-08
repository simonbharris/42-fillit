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
	box[i] = ft_strnew(size + 1);
	return (box);
}

/*
** Places a pieces, represented by a (char *) into a char ** grid of '.'
** and other alphabetical chars, the top left of the piece starts at x,y 
** coordinates. 
** Example of  (char *) piece: "....\n...#\n..##\n...#\0"
** (By this point in the program, the '#' symbols are replaced with
** a latter)
**
** Attempts to place the shape into the larger 2D box grid.
** If shape collides with wall or another piece, it fails in placing return(0)
** otherwise, return (1)
*/

int	place_piece(char **box, char *piece, int x,  int y)
{
	int ycur;
	int h;

	h = 0;
	while (*piece && box[x][0])
	{
		ycur = y;
		while (*piece && ycur < y + 4 && *piece != '\n' && h < 4)
		{
			if (box[x][ycur] != '.' && (*piece >= 'A' && *piece <= 'Z'))
				return (0);
			else if (box[x][ycur] == '\0')
				break;
			if (box[x][ycur] == '.' && (*piece >= 'A' && *piece <= 'Z'))
			{
				box[x][ycur] = *piece;
				h++;
			}
			if (*piece)
				piece++;
			ycur++;
		}
		while (*piece && ycur++ < 5 + y)
			piece++;
		x++;
	}
	if (h != 4)
		return (0);
	return (1);
}

/*
** Called after trying to place a piece and failing. It removes any pieces
** or blocksthat were placed by the given char* piece at x,y coordinates 
** in char** box
*/

void remove_piece(char **box, char *piece, int x, int y)
{
	int ycur;

	// while (box[x][0])
	// 	ft_putendl(*box++);
	// ft_putendl(piece);
	while (*piece && box[x][0])
	{
		ycur = y;
		while (*piece && ycur < y + 4 && *piece != '\n' &&
			box[x][ycur] != '\0')
		{
			if (*piece != '.' && box[x][ycur] == *piece)
				box[x][ycur] = '.';
			piece++;
			ycur++;
		}
		while (*piece && ycur++ < 5 + y)
			piece++;
		x++;
	}
}

/*
** Attempts to place a (t_list *piece) inside of a (char** box) by 
** brute forcing using a recursive backtracking method.
**
** x, y are coordinates to place, sf == bool-like flag for "Solution found"
** Algorithm attempts to place a piece in top-left corner, and works it's
** way right, then down.
**
** If a piece is successfully placed
** Algorithm recurses and attempts to place the next piece.
**
** If a place_piece fails
** it removes the blocks that may have successfully been placed in the grid
** then moves this iteration's piece to the next step, and tries again.
**
** Eventuakky, if not all pieces first (the first piece has been tried in every
** position) then the solver fails.
** If all pieces are successfully placed; it returns a 1 up the chain and tells
** the initial resursive_solver call that a solution was gound.
*/

int recursive_solver(char **box, t_list *pieces)
{
	int x;
	int y;
	int sf;

	sf = 0;
	x = 0;
	while (box[x][0] && pieces != NULL && sf == 0)
	{
		y = 0;
		while (box[x][y] && sf == 0)
		{
			if (place_piece(box, pieces->content, x, y) == 1)
			{
				if (recursive_solver(box, pieces->next))
					sf = 1;
				break;
			}
			else
			{
				remove_piece(box, pieces->content, x, y);
				y++;
			}
		}
		x++;
	}
	if (pieces == NULL || sf)
		return (1);
	return (0);
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
		ft_memdel((void *)&box[0][i++]);
	ft_memdel((void *)box[0][i]);
	ft_memdel((void **)*box);
	*box = NULL;
}

char **get_solution(t_list *pieces)
{
	int size;
	char **box;

	size = 1;
	box = NULL;
	while (box == NULL)
	{
		box = malloc_fillit_box(++size);
		if (!recursive_solver(box,pieces))
			ft_delbox(&box);
	}
	return (box);
}

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