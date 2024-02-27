/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:48:22 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***load_map(int fd)
{
	char	*file_content;
	t_pixel	**map;
	int		x;
	int		j;

	x = 0;
	j = 0;
	map = ft_calloc((2 + x) * sizeof(t_pixel *), sizeof(t_pixel *));
	while (1)
	{
		if (map)
			map = ft_realloc(map, (2 + x) * sizeof(t_pixel *));
		if (!map)
			return (NULL);
		file_content = get_next_line(fd);
		if (!file_content)
			break ;
		map = struct_map(map, file_content, ' ', x);
		while (j < 3)
		{
			printf("%d ", map[x][j].value);
			j++;
		}
		free(file_content);
		printf("\n");
		j = 0;
		x++;
	}
	close(fd);
	return (NULL);
}

// x = 0;
// while (file_content != NULL)
// {
// 	file_content = get_next_line(fd);
// 	*map = struct_map(file_content, ' ');
// 	// ft_realloc(file_content, x++);
// 	// printf("%s", **map);
// }

char	*validate_file(char *fl_name)
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
			ft_printf("### Error en la lectura ###\n");
			return (close(fd), NULL);
		}
		else
			load_map(fd);
	}
	else
	{
		ft_printf("####  Error  ####\nThe program need .fdf extension\n");
		return (NULL);
	}
	return (NULL);
}

/*
	Program main
*/
// int	main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		validate_file(argv[1]);
// 		// system("leaks fdf");
// 	}
// 	else
// 	{
// 		ft_printf("#########  Error  #########\n");
// 		ft_printf("The program need only 2 params\n");
// 		return (0);
// 	}
// }

int	main(void)
{
	validate_file("maps/qwe.fdf");
	// system("leaks fdf");
}
