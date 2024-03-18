/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:36:54 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/18 21:28:36 by igvisera         ###   ########.fr       */
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

void isometric(int height,float *x, float *y, int z)
{
    float aux;

    aux = *x;
    *x = (aux - *y) * cos(0.523599);
    *y = (aux + *y) * sin(0.523599) - z * height;
    
}

void	zoom(float *width, float *height, float *width_1, float *height_1, int zoom)
{
	*width *= zoom;
	*height *= zoom;
	*width_1 *= zoom;
	*height_1 *= zoom;
}

