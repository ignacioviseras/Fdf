/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:28 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/07 17:52:15 by igvisera         ###   ########.fr       */
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

void pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
    *((unsigned int *)(offset + img->img_pixel_ptr)) = color;
}

void    screen_pixels(t_window *window, int color)
{
    for ( int y = HEIGHT_WIN * 0.1; y < HEIGHT_WIN * 0.9; ++y)
    {
        for ( int x = WIDTH_WIN * 0.1; x < WIDTH_WIN * 0.9; ++x)
        {
            pixel_put(&window->img, x, y, color);
        }
    }
}

int f(int keysym, t_window *window)
{
    printf("tecla pulsada %i\n", keysym);
    //ver q han pulsado y sacar color
    if (keysym == N_1)//    inverido
        screen_pixels(window, 0x00ff7f);
    else if (keysym == N_2)//    rosalige
        screen_pixels(window, 0xec53a0);
    else if (keysym == N_3)//    fuchsia
        screen_pixels(window, 0xff00ff);
    else if (keysym == ESC)//    salimos
        exit(1);
    mlx_put_image_to_window(window->mlx, window->win, window->img.img_ptr, 0, 0);
    return (0);
}

int main(void)
{
    t_window window;

    window.mlx = mlx_init();
    window.win = mlx_new_window(window.mlx, WIDTH_WIN, HEIGHT_WIN, "Fdf");
    
    window.img.img_ptr = mlx_new_image(window.mlx, WIDTH_WIN, HEIGHT_WIN);
	window.img.img_pixel_ptr = mlx_get_data_addr(window.img.img_ptr , &window.img.bits_per_pixel, &window.img.line_length,
								&window.img.endian);
    mlx_key_hook(window.win, f, &window);
    mlx_loop(window.mlx);
    return (0);
    // return (free_all((void **)map), 0); culo
}