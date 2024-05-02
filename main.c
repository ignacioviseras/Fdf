/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:41:21 by igvisera          #+#    #+#             */
/*   Updated: 2024/04/14 20:05:06 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Program main
*/
// int	main(int argc, char **argv)
// {
//     t_pixel **map;
// 	if (argc == 2)
// 	{
// 		map = validate_file(argv[1]);
//         if (map == NULL)
//             return (0);
        
//         free_all((void **)map);
//         return (0);
// 	}
// 	else
// 	{
// 		ft_printf("\t####  Error  ####\nThe program need only 2 params\n");
// 		return (0);
// 	}
// }

int	main(void)
{
    t_pixel **map;

    map = validate_file("maps/t1.fdf");
    if (map == NULL)
        return (0);
    ft_printf("Numero de filas %i y numero de columns %i\n",
		 map[0]->number_row,
		 map[0][0].number_col);
	open_window(map);
    free_all((void **)map);
    return (0);
}
