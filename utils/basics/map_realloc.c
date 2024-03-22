/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:47:25 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/22 19:15:40 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_pixel	**map_realloc(t_pixel **ptr, size_t len)
{
	t_pixel				**new_ptr;
	long unsigned int	x;

	x = 0;
	if (len == 0)
		return (free(ptr), NULL);
	new_ptr = ft_calloc(1, len);
	if (!new_ptr)
	{
		free(*ptr);
		return (NULL);
	}
	if (ptr[0])
	{
		while (ptr[x])
		{
			new_ptr[x] = ptr[x];
			x++;
		}
	}
	free(ptr);
	return (new_ptr);
}
