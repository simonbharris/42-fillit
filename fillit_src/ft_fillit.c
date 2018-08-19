/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 20:03:16 by sharris           #+#    #+#             */
/*   Updated: 2018/08/10 23:12:34 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_fillit(char *file)
{
	t_list	*start;
	char	**box;
	int		i;

	start = ft_readfile(file);
	i = 0;
	if (start != NULL && ft_validateshapes(start) && ft_lstcount(start) <= 26)
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
