/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:44:45 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/22 19:13:19 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	free_all(void **str)
{
	void	**pointer_pos;

	pointer_pos = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(pointer_pos);
}
