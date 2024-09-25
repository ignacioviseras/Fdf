/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:16:28 by igvisera          #+#    #+#             */
/*   Updated: 2024/09/25 22:02:50 by igvisera         ###   ########.fr       */
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

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixel_ptr)) = color;
}

/*
    *window -> estructura de la ventana
    width -> donde inicia
    height -> donde termina
    width_1 -> donde como de ancho es
    height_1 -> donde como de largo es
    color -> el color que tiene
    !!!!!!!!!pasar datos a una lista funcion solo 4 argumentos max!!!!!!!!!!
*/
void	bresenham(t_window *window, t_bresenham *b)
{
	float	width_step;
	float	height_step;
	int		max;

	zoom(b, window->zoom);
	move(b, window);
	isometric(b, window->z);
	set_color(b, window);
	width_step = b->width_pixels_1 - b->width_pixels;
	height_step = b->height_pixels_1 - b->height_pixels;
	max = get_max(mod(width_step), mod(height_step));
	width_step /= max;
	height_step /= max;
	while ((int)(b->width_pixels - b->width_pixels_1) || (int)(b->height_pixels
			- b->height_pixels_1))
	{
		if ((b->width_pixels > 0 && b->width_pixels < WIDTH_WIN)
			&& (b->height_pixels > 0 && b->height_pixels < HEIGHT_WIN))
			pixel_put(&(window->img), (int)b->width_pixels,
				(int)b->height_pixels, window->color);
		b->width_pixels += width_step;
		b->height_pixels += height_step;
	}
}

static void	draw(t_window *window)
{
	t_bresenham	b;
	int			width_pixels;
	int			height_pixels;

	height_pixels = -1;
	while (++height_pixels < window->map[0]->number_row)
	{
		width_pixels = -1;
		while (++width_pixels < window->map[0][0].number_col)
		{
			if (width_pixels < window->map[0][0].number_col - 1)
				horizontal_lines(window, &b, width_pixels, height_pixels);
			if (height_pixels < window->map[0]->number_row - 1)
				vertical_lines(window, &b, width_pixels, height_pixels);
		}
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img.img_ptr, 0,
		0);
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
		window->zoom += 1;
	else if (keysym == ZOOM_OUT && window->zoom >= 2)
		window->zoom -= 1;
	else if (keysym == KEY_M)
		window->z += 10;
	else if (keysym == KEY_N)
		window->z -= 10;
	else if (keysym == ESC)
		exit(1);
	mlx_destroy_image(window->mlx, window->img.img_ptr);
	window->img.img_ptr = mlx_new_image(window->mlx, WIDTH_WIN, HEIGHT_WIN);
	window->img.img_pixel_ptr = mlx_get_data_addr(window->img.img_ptr,
			&window->img.bits_per_pixel, &window->img.line_length,
			&window->img.endian);
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
	window.img.img_pixel_ptr = mlx_get_data_addr(window.img.img_ptr,
			&window.img.bits_per_pixel, &window.img.line_length,
			&window.img.endian);
	window.map = map;
	window.z = 1;
	window.zoom = 3;
	window.mv_y = HEIGHT_WIN / 6;
	window.mv_x = WIDTH_WIN / 2.4;
	draw(&window);
	mlx_key_hook(window.win, f, &window);
	mlx_loop(window.mlx);
	return (0);
}
