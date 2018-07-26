/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:31:07 by aalhomai          #+#    #+#             */
/*   Updated: 2018/07/03 10:59:21 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (str == NULL || f == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(str));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = f(i, str[i]);
		i++;
	}
	return (new);
}
