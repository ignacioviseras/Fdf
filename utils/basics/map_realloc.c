/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:47:25 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/03 16:58:04 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_pixel	**map_realloc(t_pixel **ptr, size_t len)
{
	t_pixel	**new_ptr;
	long unsigned int x;

	x = 0;
	if (len == 0)
		return (free(ptr), NULL);
	new_ptr = ft_calloc(1, len);
	if (!new_ptr)
	{
		free(*ptr);
		return (NULL);
	}
	if (*ptr)
	{
		while (x < sizeof(ptr) / sizeof(t_pixel))
		{
			new_ptr[x] = ptr[x];
			x++;
		}
	}
	free(ptr);
	return (new_ptr);
}

// int main()
// {
// 	t_pixel **mapa;

// 	mapa = ft_calloc(2, sizeof(t_pixel *));
// 	*mapa = ft_calloc(1, sizeof(t_pixel *));
// 	mapa[0][0].value = 2;
// 	mapa[0][0].color = 0xFFFFFF;
// 	mapa = ft_realloc(mapa, (2 + 1) * sizeof(t_pixel *));
// 	printf("Pos 0x0->'%i'\n", mapa[0][0].value);
// 	printf("Pos 0x0->'%i'\n", mapa[0][0].color);
// 	free(*mapa);
// 	free(mapa);
// 	return(0);
// }