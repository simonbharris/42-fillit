/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:03:16 by sharris           #+#    #+#             */
/*   Updated: 2018/07/27 19:53:59 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int ft_fillit(char *file)
{
	t_list *start = ft_readfile(file);
	char **box;
	int i;

	i = 0;
	if(ft_validateshapes(start))
	{
		optimize_shapes(start);
		box = get_solution(start);
		while (box[i][0])
			ft_putendl(box[i++]);
		ft_lstdel(&start, ft_lstdelone_f);
		ft_delbox(&box);
		return (1);
	}
	return (0);
}
