/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:41:21 by igvisera          #+#    #+#             */
/*   Updated: 2024/05/02 20:12:31 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Program main
*/
int	main(int argc, char **argv)
{
	t_pixel	**map;

	if (argc == 2)
	{
		map = validate_file(argv[1]);
		if (map == NULL)
			return (0);
		open_window(map);
		free_all((void **)map);
		return (0);
	}
	else
	{
		ft_printf("\t####  Error  ####\nThe program need only 2 params\n");
		return (0);
	}
}
