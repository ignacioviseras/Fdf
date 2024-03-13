/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/13 22:32:38 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include "./mlx_linux/mlx.h"
# include "./colors/colors.h"
# include "./events/linux_key_dictorionary.h"
// # include "./events/mac_key_dictionary.h"
# include "./utils/utils.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# ifndef WIDTH_WIN
#  define WIDTH_WIN 800
# endif

# ifndef HEIGHT_WIN
#  define HEIGHT_WIN 800
# endif

typedef struct	s_img {
	void	*img_ptr;//puntero de la estructura de imagen
	char	*img_pixel_ptr;//pixel actual
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_window {
    void *mlx;
    void *win;
	t_img	img;
	t_pixel	**map;
	int		zoom;
	int color;
}				t_window;

t_pixel	**load_map(int fd);
t_pixel	**validate_file(char *fl_name);
int open_window(t_pixel **map);
void bresenham(t_window *window, float width, float height, float width_1, float height_1, int up, int up_1);
void draw(t_window *window);

#endif