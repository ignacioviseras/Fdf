/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:41:21 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/01 20:19:38 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Program main
*/
int	main(int argc, char **argv)
{
    t_pixel **map;
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

// int	main(void)
// {
//     t_pixel **map;

//     map = validate_file("maps/42.fdf");
//     if (map == NULL)
//         return (0);
//     printf("Numero de filas %i y numero de columns %i\n",
// 		 map[0]->number_row,
// 		 map[0][0].number_col);
// 	open_window(map);
//     free_all((void **)map);
//     return (0);
// }
