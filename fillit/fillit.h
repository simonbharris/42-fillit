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

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"


typedef struct	s_shape
{
	char **shape;
	int tsides;
	int numblk;
	int len;
}				t_shape;

int			ft_validateshapes(t_list *shapes);

#endif
