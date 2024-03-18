/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:28 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/18 21:27:00 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// #####  Pinta cuadrados renderizado  ######
/*
    ###  2D image the pixel ###
    line len is in byte.
    witdh 800 line_length 3200
    (can differ for aligment)
*/
static void	pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	// if (x < 0 || y < 0)
	//     return ;
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixel_ptr)) = color;
}

/*
    31m.50
    *window -> estructura de la ventana
    width -> donde inicia
    height -> donde termina
    width_1 -> donde como de ancho es
    height_1 -> donde como de largo es
    color -> el color que tiene
    !!!!!!!!!pasar datos a una lista funcion solo 4 argumentos max!!!!!!!!!!
*/
static void	bresenham(t_window *window, float width, float height,
		float width_1, float height_1, int up, int up_1, int color)
{
	float	width_step;
	float	height_step;
	int		max;

	zoom(&width, &height, &width_1, &height_1, window->zoom);
    window->color = (color) ? color : 0x1eff05;
	isometric(window->z, &width, &height, up);
	isometric(window->z, &width_1, &height_1, up_1);
	width += window->mv_x;
	height += window->mv_y;
	width_1 += window->mv_x;
	height_1 += window->mv_y;
	width_step = width_1 - width;
	height_step = height_1 - height;
	max = get_max(mod(width_step), mod(height_step));
	width_step /= max;
	height_step /= max;
	while ((int)(width - width_1) || (int)(height - height_1))
	{
		if ((width > 0 && width < WIDTH_WIN) && (height > 0
				&& height < HEIGHT_WIN))
			pixel_put(&window->img, width, height, window->color);
		width += width_step;
		height += height_step;
	}
}

static void	draw(t_window *window)
{
	int	width_pixels;
	int	height_pixels;

	height_pixels = 0;
	while (height_pixels < window->map[0]->number_row)
	{
		width_pixels = 0;
		while (width_pixels < window->map[0][0].number_col)
		{
			if (width_pixels < window->map[0][0].number_col - 1)
				bresenham(window, width_pixels, height_pixels, width_pixels + 1,
						height_pixels,
						window->map[height_pixels][width_pixels].value,
						window->map[height_pixels][width_pixels + 1].value,
						window->map[height_pixels][width_pixels + 1].color);
			if (height_pixels < window->map[0]->number_row - 1)
				bresenham(window, width_pixels, height_pixels, width_pixels,
						height_pixels + 1,
						window->map[height_pixels][width_pixels].value,
						window->map[height_pixels + 1][width_pixels].value,
						window->map[height_pixels + 1][width_pixels].color);
			width_pixels++;
		}
		height_pixels++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img.img_ptr, 0,
			0); //lanzamos lo generedo a la pantalla
}

/*
    funcion q siempre esta a la escucha de cualquier tecla q se pulsa
*/
static int	f(int keysym, t_window *window)
{
	if (keysym == KEYRIGHT)
		window->mv_x += 10;
	else if (keysym == KEYLEFT)
		window->mv_x -= 10;
	else if (keysym == KEYUP)
		window->mv_y -= 10;
	else if (keysym == KEYDOWN)
		window->mv_y += 10;
	else if (keysym == ZOOM_IN)
		window->zoom += 10;
	else if (keysym == ZOOM_OUT)
		window->zoom -= 10;
	else if (keysym == KEY_M)
		window->z += 10;
	else if (keysym == KEY_N)
		window->z -= 10;
	else if (keysym == ESC)
		exit(1);
	mlx_destroy_image(window->mlx, window->img.img_ptr);
	window->img.img_ptr = mlx_new_image(window->mlx, WIDTH_WIN, HEIGHT_WIN);
	window->img.img_pixel_ptr = mlx_get_data_addr(
		window->img.img_ptr, &window->img.bits_per_pixel,
			&window->img.line_length, &window->img.endian);
	draw(window);
	return (0);
}

/*
    controlador de la ventana
*/
int	open_window(t_pixel **map)
{
	t_window	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WIDTH_WIN, HEIGHT_WIN, "Fdf");
	window.img.img_ptr = mlx_new_image(window.mlx, WIDTH_WIN, HEIGHT_WIN);
	window.img.img_pixel_ptr = mlx_get_data_addr(
		window.img.img_ptr,
		&window.img.bits_per_pixel,
		&window.img.line_length,
		&window.img.endian);
	window.map = map;
	window.z = 1;
	window.zoom = 10;
	window.mv_y = HEIGHT_WIN / 6;
	window.mv_x = WIDTH_WIN / 2.4;
	draw(&window);
	mlx_key_hook(window.win, f, &window);
	mlx_loop(window.mlx);
	return (0);
}
