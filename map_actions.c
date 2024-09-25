/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:54:35 by igvisera          #+#    #+#             */
/*   Updated: 2024/09/25 22:02:30 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_bresenham *b, int zoom)
{
	b->width_pixels *= zoom;
	b->height_pixels *= zoom;
	b->width_pixels_1 *= zoom;
	b->height_pixels_1 *= zoom;
}

void	move(t_bresenham *b, t_window *window)
{
	b->width_pixels += window->mv_x;
	b->height_pixels += window->mv_y;
	b->width_pixels_1 += window->mv_x;
	b->height_pixels_1 += window->mv_y;
}

int get_color(int value)
{
	if (value < -40)
		return (0x0000FF);
	else if (value < -30)
		return (0x0055FF);
	else if (value < -20)
		return (0x00AAFF);
	else if (value < -10)
		return (0x55FFFF);
	else if (value < -5)
		return (0xAAFFFF);
	else if (value < 0)
		return (0xFFFFAA);
	else if (value == 0)
		return (0xFFFFFF);
	else if (value > 0 && value <= 10)
		return (0x55FF55);
	else if (value > 10 && value <= 20)
		return (0xAAFF00);
	else if (value > 20 && value <= 30)
		return (0xFFFF00);
	else if (value > 30 && value <= 40)
		return (0xFFAA00);
	else if (value > 40)
		return (0xFF0000);
	return (0xFFFFFF);
}

void set_color(t_bresenham *b, t_window *win)
{
	if (b->color)
		win->color = b->color;
	else
		win->color = get_color(b->value);
}

