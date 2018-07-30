/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhomai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:57:15 by aalhomai          #+#    #+#             */
/*   Updated: 2018/07/27 19:54:17 by aalhomai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	if (argc == 2)
		if(!ft_fillit(argv[1]))
		{
			ft_putstr("Error\n");
		} 
		else //! DEBUG REMOVE SUCCESS / ELSE MESSAGE
			ft_putstr("Success!\n");
	else
		fillit_usage();
	return (0);
}
