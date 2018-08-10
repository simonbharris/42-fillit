/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 20:37:42 by aalhomai          #+#    #+#             */
/*   Updated: 2018/07/27 23:29:13 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static char	*ft_append_str(void *ptr, size_t size)
// {
// 	void *newptr;
// 	size_t old_size;

// 	newptr = (char*)malloc(sizeof(char) * size);
// 	ft_memset(newptr, 0, size);
// 	old_size = ft_strlen(ptr);
// 	ft_memcpy(newptr, ptr, old_size);
// 	free(ptr);
// 	return (newptr);
// }

t_list *ft_readfile(char *filename)
{
	int fd;
	int	ret;
	int size;
	char temp[21];
	t_list *lst;

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
			break;
		}
	}
	ft_memdel((void *)&temp);
	return (lst);
}
