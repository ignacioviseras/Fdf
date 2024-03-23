/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:36:54 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/23 22:20:50 by igvisera         ###   ########.fr       */
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

// void	isometric(int height, float *x, float *y, int z)
// {
// 	float	aux;

// 	aux = *x;
// 	*x = (aux - *y) * cos(0.523599);
// 	*y = (aux + *y) * sin(0.523599) - z * height;
// }

void	isometric(int height, int z, t_bresenham *b)
{
	float	aux;

	aux = *b->width_pixels;
	*x = (aux - *y) * cos(0.523599);
	*y = (aux + *y) * sin(0.523599) - z * height;
}

void	zoom(float *width, float *height, float *width_1, float *height_1,
		int zoom)
{
	*width *= zoom;
	*height *= zoom;
	*width_1 *= zoom;
	*height_1 *= zoom;
}

void clean_bresham_estruct(t_bresenham *b)
{
	b->width_pixels = 0;
	b->height_pixels = 0;
	b->width_pixels_1 = 0;
	b->height_pixels_1 = 0;
	b->value = 0;
	b->value_1 = 0;
	b->color = 0;
}
