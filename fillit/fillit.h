/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:44:48 by sharris           #+#    #+#             */
/*   Updated: 2018/07/27 22:38:50 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define VALID_CHAR(x) (x == '#' || x == '.' | x == '\n')

# include <fcntl.h>
# include "../libft/libft.h"

//! PRINTF LIBRARY
#      include <stdio.h>

typedef struct	s_shape
{
	char **shape;
	int tsides;
	int numblk;
	int len;
}				t_shape;

int			ft_validateshapes(t_list *shapes);
void		fillit_usage(void);
t_list		*ft_readfile(char *filename);
int			ft_fillit(char *file);
void		optimize_shapes(t_list *lst);
char		*solve_fillit(t_list *shapes);
char		**get_solution(t_list *pieces);

//! DEBUG Should be static
char		**malloc_fillit_box(int size);
int	place_piece(char **box, char *piece, int x,  int y);
void remove_piece(char **box, char *piece, int x, int y);

#endif
