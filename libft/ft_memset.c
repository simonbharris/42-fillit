/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:43:09 by aalhomai          #+#    #+#             */
/*   Updated: 2018/07/02 16:46:50 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *in, int data, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)in;
	while (len-- > 0)
		*ptr++ = (unsigned char)data;
	return (in);
}
