/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:28:43 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/21 19:29:58 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*mem1;
	char	*mem2;

	index = 0;
	if (!src && !dest)
		return (NULL);
	mem1 = ((char *)src);
	mem2 = ((char *)dest);
	if (n == 0)
		return (mem2);
	while (index < n)
	{
		mem2[index] = mem1[index];
		index++;
	}
	return (mem2);
}
