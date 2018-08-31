/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fromo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:57:15 by fromo             #+#    #+#             */
/*   Updated: 2018/08/11 05:25:17 by sharris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_fillit(argv[1]))
			ft_putendl("error");
	}
	else
		fillit_usage();
	return (0);
}
