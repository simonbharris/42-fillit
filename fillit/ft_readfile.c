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

char *ft_readfile(char *filename)
{
	int fd;
	int	ret;
	int size;
	char *file;
	char *temp;

	size = 22;
	fd = open(filename, O_RDONLY);
	file = ft_strnew(21);
	temp = ft_strnew(21);
	while (ret = read(fd, temp, 21))
	{
		ft_strcat(file, temp);
		size += 21;
		file = ft_append_str(file, size);
		ft_memset(temp, 0, 21);
	}	
	return (file);

}


int main(int argc, char **argv)
{
	char *file;
	file = argv[1];
	
	printf("%s\n", file);
	return (0);
}
