/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:26:30 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/16 21:42:54 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    parsing()
{
    
}

// int	main (void)
// {
// 	char file[] = "./maps/42.fdf";
// 	int a;
// 	char *str;

// 	a = open(file, O_RDONLY);

// 	if (BUFFER_SIZE > 100) {
// 		char *temp;
// 		do {
// 			temp = get_next_line(a);

// 			free(temp);
// 		} while (temp != NULL);
// 	}

// 	close(a);
// 	a = open(file, O_RDONLY);

// 	while((str = get_next_line(a)) != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	free(str);
// 	// printf("%s\n", get_next_line(a));
// 	// printf("%s", get_next_line(a));
// 	close(a);
// 	system("leaks a.out");
// 	return (0);
// }