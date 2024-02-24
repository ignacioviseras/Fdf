/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/20 22:15:21 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***load_map(int fd)
{
	char	*file_content;
	t_pixel 	**map;
	int		x;
	int		j;

	x = 0;
	j = 0;
	file_content= "";
	while (file_content != NULL)
	{
		// printf("accedeMain\n");

		file_content = get_next_line(fd);
		map = struct_map(file_content, ' ', x);
		printf("iteracion-Num->%i\n", x);
		while (j < 3)
		{
			printf("'%d'", map[x][j].value);
			j++;
			printf("j-Num->%i\n", j);

		}
		printf("\n");
		j=0;
		x++;
		// ft_realloc(map, x);
	}
	
	
	// while (*map != NULL)
	// {
		// 	printf("asd->'%d'", *map->value);
		// 	map++;
	// }
	

	
	close(fd);
	printf("CANCER\n");
	
	return (NULL);
	// return (map);
}

	// x = 0;
	// while (file_content != NULL)
	// {
	// 	file_content = get_next_line(fd);
	// 	*map = struct_map(file_content, ' ');
	// 	// ft_realloc(file_content, x++);
	// 	// printf("%s", **map);
	// }

char	*validate_file(char *file_name)
{
	char	*type_extension;
	int		len_extension;
	int		len_file;
	int		fd;

	type_extension = ".fdf";
	len_file = ft_strlen(file_name);
	len_extension = len_file - 4;
	if (ft_strcmp(file_name + len_extension, type_extension) == 0
		&& len_file > 4)
	{
		fd = open(file_name, O_RDONLY);
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
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		validate_file(argv[1]);
		// system("leaks fdf");
	}
	else
	{
		ft_printf("#########  Error  #########\n");
		ft_printf("The program need only 2 params\n");
		return (0);
	}
}
