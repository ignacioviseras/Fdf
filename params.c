/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/05 22:06:11 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int validate_map(t_pixel **map, int map_long)
{
	int n_columns;
	int x;

	x = 0;
	n_columns = map[0][0].number_col;
	// printf("%i longma \n", map_long);
	// printf("%i n_col \n", n_columns);

	while (x < map_long)
	{
		// printf("iteracion %i, %i n_col \n", x, map[x][0].number_col);

		if(n_columns != map[x][0].number_col)
		{
			printf("mapa de distinto tamaño\n");
			return (0);
		}
		x++;
	}
	printf("esta perfe\n");
	return (1);
}

t_pixel	**load_map(int fd)
{
	char	*file_content;
	t_pixel	**map;
	int		x;
	x = 0;
	map = ft_calloc(2, sizeof(t_pixel *));
	if (!map)
			return (NULL);
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
	// esto retorna map cuado se termine el programa se tendria que liberar map
	printf("'%i'", map[0][0].value);
	printf("'%i'", map[0][1].value);
	printf("'%i'\n", map[0][2].value);
	printf("'%i'", map[1][0].value);
	printf("'%i'", map[1][1].value);
	printf("'%i'\n", map[1][2].value);
	//---------------------
	printf("NUMEE'%i'\n", map[0][0].number_col);
	printf("NUMEE'%i'\n", map[1][0].number_col);
	if (validate_map(map, x) == 0)
		return(free_all((void **) map), NULL);
	free_all((void **) map);
	return (NULL);
}

// int		size_map() {
	
// 	return (size_map);
// }

// char	***load_map(int fd)
// {
// 	char	*file_content;
// 	t_pixel	**map;
// 	int		x;

// 	x = 0;
// 	map = ft_calloc((2 + x) * sizeof(t_pixel *), sizeof(t_pixel *));
// 	while (1)
// 	{
// 		if (map)
// 			map = ft_realloc(map, (2 + x) * sizeof(t_pixel *));
// 		if (!map)
// 			return (NULL);
// 		file_content = get_next_line(fd);
// 		if (!file_content)
// 			break ;
// 		map = struct_map(map, file_content, ' ', x);
// 		free(file_content);
// 		x++;
// 	}
// 	close(fd);
// 	return (NULL);
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
