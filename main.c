/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:43:36 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/15 19:37:07 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int main(int argc, char *argv[])
// {
//     char *file;
    
//     if (argc != 2)
//         return (0);
//     else
//     {
//         file = argv[1];
//         char *x = ft_strjoin("cat ", file);
//     	system(x);

//     }
//         // printf("%s", argv[1]);
//     return (0);
// }


//-------------------pintamos una lilnea de pixeles-------------------
// int	main(void)
// {
// 	void	*mlx;
//     void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 500, 500, "Fdf");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	mlx_pixel_put(mlx, mlx_win, 5, 250, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 6, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 7, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 8, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 9, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 10, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 11, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 12, 5, 0x0000FFFF);
// 	mlx_pixel_put(mlx, mlx_win, 13, 5, 0x0000FFFF);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     mlx_loop(mlx);
// }





// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Fdf");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
