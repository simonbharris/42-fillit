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
		else
		{
			ft_putstr("Success!\n");
		}
	else
	{
		//! Debugging '.' square generator.
			char **box = malloc_fillit_box(4);
			while (*box[0])
				printf("%s\n", *box++);
		//! End debug
		fillit_usage();
	}
	return (0);
}
