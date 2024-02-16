/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:37:14 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/16 17:15:19 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

/*
* It calculate de color of 1point betwwen 2 points
*/
double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

// int get_color(t_point current, t_point start, t_point end, t_point delta)
// {
//     int     red;
//     int     green;
//     int     blue;
//     double  percentage;

//     if (current.color == end.color)
//         return (current.color);
//     if (delta.x > delta.y)
//         percentage = percent(start.x, end.x, current.x);
//     else
//         percentage = percent(start.y, end.y, current.y);
//     red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
//     green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
//     blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
//     return ((red << 16) | (green << 8) | blue);
// }