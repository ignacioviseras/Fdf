/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:04:05 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/21 19:49:59 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void *ft_realloc(void *ptr, size_t len)
{
    void *new_ptr;

    if (len == 0)
        return (free(ptr), NULL);
    new_ptr = ft_calloc(1, len);
    if (!new_ptr)
        return (NULL);
    if (ptr)
	{
        ft_memcpy(new_ptr, ptr, len);
        free(ptr);
    }
    return (new_ptr);
}
