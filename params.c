/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/05/12 13:06:46 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_map(t_pixel **map, int map_long)
{
	int	n_columns;
	int	x;

	x = 0;
	n_columns = map[0][0].number_col;
	while (x < map_long)
	{
		if (n_columns != map[x][0].number_col)
		{
			ft_printf("\t### Error ###\nThe map have different size.\n");
			return (0);
		}
		x++;
	}
	return (1);
}

t_pixel	**load_map(int fd)
{
	char	*file_content;
	t_pixel	**map;
	int		x;

	x = 0;
	map = ft_calloc(2, sizeof(t_pixel *));
	while (1)
	{
		file_content = get_next_line(fd);
		if (!file_content)
			break ;
		if (map)
			map = map_realloc(map, (2 + x) * sizeof(t_pixel *));
		if (!map)
			return (NULL);
		map[x] = struct_map(file_content, ' ');
		free(file_content);
		x++;
	}
	close(fd);
	map[0]->number_row = x;
	if (validate_map(map, x) == 0)
		return (free_all((void **)map), NULL);
	return (map);
}

t_pixel	**validate_file(char *fl_name)
{
	char	*tp_extension;
	int		l_extension;
	int		len_fl;
	int		fd;

	tp_extension = ".fdf";
	len_fl = ft_strlen(fl_name);
	l_extension = len_fl - 4;
	if (ft_strcmp(fl_name + l_extension, tp_extension) == 0 && len_fl > 4)
	{
		fd = open(fl_name, O_RDONLY);
		if (fd < 0 || BUFFER_SIZE <= 0)
		{
			ft_printf("\t### Error ###\nReading file error.\n");
			return (close(fd), NULL);
		}
		else
			return (load_map(fd));
	}
	else
	{
		ft_printf("\t####  Error  ####\nThe program need .fdf extension\n");
		return (NULL);
	}
	return (NULL);
}
