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

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "fillit.h"
#include <errno.h>
static char	*ft_append_str(void *ptr, size_t size)
{
	void *newptr;
	size_t old_size;

	newptr = (char*)malloc(sizeof(char) * size);
	ft_memset(newptr, 0, size);
	old_size = ft_strlen(ptr);
	ft_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}

t_list *ft_readfile(char *filename)
{
	int fd;
	int	ret;
	int size;
	char *temp;
	t_list *lst;

	lst = NULL;
	size = 22;
	fd = open(filename, O_RDONLY);
	temp = ft_strnew(21);
	while ((ret = read(fd, temp, 21)))
	{
		ft_lstadd(&lst, ft_lstnew(temp, sizeof(char) * 22));
		ft_memset(temp, 0, 21);
		if (lst->content == NULL)
		{
			ft_lstdel(&lst, ft_lstdelone_f);
			break;
		}
	}	
	return (lst);
}


int main(int argc, char **argv)
{
	char *file;
	file = argv[1];
	t_list *start = ft_readfile(file);
	//printf("##### Begin displaying list contents, must start on next line #######\n");
	/*
	while (lst->next)
	{
		
		printf("%s\n", (char *)lst->content);
		printf("-------list split---------\n");
		printf("\n############ Plugging into validate shapes ############\n\n");
		lst = lst->next;
	}*/
	printf("Validating file... %s\n", ft_validateshapes(start) ? "SUCCESS!" : "FAIL!");
	return (0);
}
