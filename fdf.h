/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/07 15:33:30 by igvisera         ###   ########.fr       */
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

typedef struct	s_window {
    void *mlx;
    void *win;
}				t_window;

t_pixel	**load_map(int fd);
t_pixel	**validate_file(char *fl_name);

#endif