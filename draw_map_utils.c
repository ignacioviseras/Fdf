/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:36:54 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/26 19:08:06 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_max(float num_1, float num_2)
{
	if (num_1 > num_2)
		return (num_1);
	return (num_2);
}

float	mod(float num_1)
{
	if (num_1 < 0)
		return (-num_1);
	return (num_1);
}

void	isometric(t_bresenham *b, int z)
{
	float	aux;
	float	aux_1;

	aux = b->width_pixels;
	aux_1 = b->width_pixels_1;
	b->width_pixels = (aux - b->height_pixels) * cos(0.523599);
	b->height_pixels = (aux + b->height_pixels) * sin(0.523599) - z * b->value;
	b->width_pixels_1 = (aux_1 - b->height_pixels_1) * cos(0.523599);
	b->height_pixels_1 = (aux_1 + b->height_pixels_1) * sin(0.523599) - z
		* b->value_1;
}

void	horizontal_lines(t_window *window, t_bresenham *b, int width_pixels,
		int height_pixels)
{
	b->width_pixels_1 = width_pixels + 1;
	b->height_pixels_1 = height_pixels;
	b->width_pixels = width_pixels;
	b->height_pixels = height_pixels;
	b->value = window->map[height_pixels][width_pixels].value;
	b->value_1 = window->map[height_pixels][width_pixels + 1].value;
	b->color = window->map[height_pixels][width_pixels + 1].color;
	bresenham(window, b);
}

void	vertical_lines(t_window *window, t_bresenham *b, int width_pixels,
		int height_pixels)
{
	b->width_pixels_1 = width_pixels;
	b->height_pixels_1 = height_pixels + 1;
	b->width_pixels = width_pixels;
	b->height_pixels = height_pixels;
	b->value = window->map[height_pixels][width_pixels].value;
	b->value_1 = window->map[height_pixels + 1][width_pixels].value;
	b->color = window->map[height_pixels + 1][width_pixels].color;
	bresenham(window, b);
}
