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
	ft_putendl("Starting Program!");
	if (argc == 2)
		if(!ft_fillit(argv[1]))
			ft_putendl("Error");
		else
			ft_putendl("Success!");
	else
	{
		//! Debugging '.' square generator.

		//! End debug
		fillit_usage();
	}
	return (0);
}
