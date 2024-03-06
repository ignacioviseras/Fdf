/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/06 19:16:06 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "./colors/colors.h"
# include "./utils/utils.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# ifndef WIDTH_WIN
#  define WIDTH_WIN 500
# endif

# ifndef HEIGHT_WIN
#  define HEIGHT_WIN 500
# endif

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


t_pixel	**load_map(int fd);
t_pixel	**validate_file(char *fl_name);

#endif