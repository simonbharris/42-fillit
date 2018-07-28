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

#include <unistd.h>
#include "../libft/libft.h"

# define VALID_CHAR(x) (x == '#' || x == '.' | x == '\n')

typedef struct	s_shape
{
	char **shape;
	int tsides;
	int numblk;
	int len;
}				t_shape;

<<<<<<< HEAD
#endif
=======
int		ft_validateshape(char **shapes);

#endif
>>>>>>> 136b8cdf5856672b54d4897444bb6255d5ae1991
