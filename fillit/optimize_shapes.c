/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:21:25 by sharris           #+#    #+#             */
/*   Updated: 2018/07/29 15:21:25 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Moves the shape (hashtags) so that the top-left corner of the shape 
** begins on the first character of the string.
*/

static void shift_shape(char *str)
{
	int start;
	int i;

	start = 0;
	i = 0;
	i = ft_strchr(str, '#');
	ft_strncpy(str[start],str[i], ft_strlen(str[i] - 1));
}

void	optimize_shapes(t_list *lst)
{
	while (lst)
	{
		shift_shape(lst->content);
		lst = lst->next;
	}
}