/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/09/25 21:52:33 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx_linux/mlx.h"
# include "./utils/utils.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef WIDTH_WIN
#  define WIDTH_WIN 800
# endif

# ifndef HEIGHT_WIN
#  define HEIGHT_WIN 800
# endif

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_pixel	**map;
	int		zoom;
	int		color;
	int		mv_x;
	int		mv_y;
	int		z;
}			t_window;

typedef struct s_bresenham
{
	float	width_pixels;
	float	height_pixels;
	float	width_pixels_1;
	float	height_pixels_1;
	int		value;
	int		value_1;
	int		color;
}			t_bresenham;

enum e_linux_key_dictionary
{
	KEYLEFT = 65361,
	KEYRIGHT = 65363,
	KEYDOWN = 65364,
	KEYUP = 65362,
	KEY_1 = 65436,
	KEY_2 = 65433,
	KEY_3 = 65435,
	ZOOM_IN = 65451,
	ZOOM_OUT = 65453,
	KEY_M = 109,
	KEY_N = 110,
	ESC = 65307,
};

t_pixel		**load_map(int fd);
t_pixel		**validate_file(char *fl_name);
int			open_window(t_pixel **map);
float		get_max(float num_1, float num_2);
float		mod(float num_1);
void		isometric(t_bresenham *b, int z);
void		zoom(t_bresenham *b, int zoom);
void		move(t_bresenham *b, t_window *window);
void		bresenham(t_window *window, t_bresenham *b);
void		horizontal_lines(t_window *window, t_bresenham *b, int width_pixels,
				int height_pixels);
void		vertical_lines(t_window *window, t_bresenham *b, int width_pixels,
				int height_pixels);
int get_color(int value);
void set_color(t_bresenham *b, t_window *win);

#endif