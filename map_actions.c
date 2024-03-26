/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:54:35 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/26 19:08:12 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_bresenham *b, int zoom)
{
	// printf("Zoom '%i'", zoom);
	// if (zoom <= 11)
	// 	return ;
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
