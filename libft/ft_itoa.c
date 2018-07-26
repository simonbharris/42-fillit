/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 23:23:48 by aalhomai          #+#    #+#             */
/*   Updated: 2018/07/03 12:15:49 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchars(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	else
	{
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	x;
	int				sign;
	char			*buf;

	buf = ft_strnew(ft_countchars(n));
	if (!buf)
		return (NULL);
	x = n;
	if ((sign = n) < 0)
		x = -n;
	i = 0;
	if (x == 0)
		buf[i++] = '0';
	while (x > 0)
	{
		buf[i++] = x % 10 + '0';
		x /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
