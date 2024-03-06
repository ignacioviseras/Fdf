/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:28 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/06 19:21:42 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int open_window(t_pixel **map)
// {
//     void *mlx;
//     void *win;
//     // t_data img;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WIDTH_WIN, HEIGHT_WIN, "Fdf");
    
//     return (0);
//     // return (free_all((void **)map), 0);
// }

int main(void)
{
    void *mlx;
    void *win;
    t_data img;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WIDTH_WIN, HEIGHT_WIN, "Fdf");
    img.img = mlx_new_image(mlx, WIDTH_WIN, HEIGHT_WIN);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    mlx_loop(mlx);
    return (0);
    // return (free_all((void **)map), 0);
}