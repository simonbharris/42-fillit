/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharris <sharris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 19:40:14 by sharris           #+#    #+#             */
/*   Updated: 2018/08/11 05:13:10 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_nullterm(t_list *lst)
{
	int		i;
	char	*str;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst->next)
		lst = lst->next;
	str = lst->content;
	while (str[i] && i <= 20)
		i++;
	if (str[i] != 0)
		return (0);
	return (1);
}

t_list		*ft_readfile(char *filename)
{
	int		fd;
	int		ret;
	int		size;
	char	temp[21];
	t_list	*lst;

	lst = NULL;
	size = 22;
	ft_memset(temp, 0, 21);
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, temp, 21)))
	{
		ft_lstpush(&lst, ft_lstnew(temp, sizeof(char) * 22));
		ft_memset(temp, 0, 21);
		if (lst->content == NULL)
		{
			ft_lstdel(&lst, ft_lstdelone_f);
			break ;
		}
	}
	ft_memdel((void *)&temp);
	return ((check_nullterm(lst) ? lst : NULL));
}
