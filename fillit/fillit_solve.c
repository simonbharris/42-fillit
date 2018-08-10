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
** (If all pieces successfully place, "sf" turns "true" and recurses up stack
**
** If a place_piece fails
** it removes the blocks that may have successfully been placed in the grid
** then moves this iteration's piece to the next step, and tries again.
**
** Eventually, if the first piece has tried every possible location
** then the solver fails.
** If all pieces are successfully placed; it returns a 1 up the chain and tells
** the initial resursive_solver call that a solution was gound.
*/

int recursive_solver(char **box, t_list *pieces)
{
	int x;
	int y;
	int sf;

	sf = 0;
	x = -1;
	while (box[++x][0] && pieces != NULL && sf == 0)
	{
		y = -1;
		while (box[x][++y] && sf == 0)
		{
			if (place_piece(box, pieces->content, x, y) == 1)
				if (recursive_solver(box, pieces->next))
					sf = 1;
			if (sf == 0)
				remove_piece(box, pieces->content, x, y);
		}
	}
	if (pieces == NULL || sf)
		return (1);
	return (0);
}


/*
** Generates a box to store the solution (Is freed if box is not large
** enough, and remakes one size larger)
**
** Recursiver solver is the back-tracking algorithm,
**    returns a 1 if solution found,
**    returns a 0 if not found,
** upon finding a solution, it returns the layout.
*/

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
