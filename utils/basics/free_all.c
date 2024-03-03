/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:45 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/02 23:47:21 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	free_all(void **str)
{
	void **pointer_pos;

	pointer_pos = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(pointer_pos);
}
