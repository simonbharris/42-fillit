/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 02:31:56 by aalhomai          #+#    #+#             */
/*   Updated: 2018/06/30 03:17:44 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *newdst;
	char *newsrc;

	newdst = (char*)dst;
	newsrc = (char*)src;
	if (newsrc < newdst)
	{
		newsrc = newsrc + len - 1;
		newdst = newdst + len - 1;
		while (len > 0)
		{
			*newdst-- = *newsrc--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*newdst++ = *newsrc++;
			len--;
		}
	}
	return (dst);
}
