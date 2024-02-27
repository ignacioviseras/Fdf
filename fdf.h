/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:46:15 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:50:47 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include <mlx.h>
# include "./colors/colors.h"
# include "./utils/utils.h"
# include <stdio.h>
# include <stdlib.h>

// typedef struct pixel
// {
// 	int	value;
// 	int color;
// } t_pixel;

void	parsing(void);
void	extract_content(void);
void	insert_matrix(char *str);
char	***load_map(int fd);

#endif