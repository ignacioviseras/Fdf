/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/19 22:01:31 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "./utils/utils.h"
# include "./colors/colors.h"
# include "./utils/utils.h"

typedef struct	s_map {
	char	**map;
    char    *colum;
    char    *row;
    //crear en colors un t_color para asi poder aceder a r g b directamente
    char    *color;
}				t_map;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

void	parsing();
void	extract_content();
void	insert_matrix(char *str);
int     load_map(char *file_name);


#endif