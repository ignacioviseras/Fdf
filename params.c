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

char	*load_map(int fd)
{
	char	*file_content;
	char 	***map;

	// int ***map;
	file_content = "";
	while (file_content != NULL)
	{
		file_content = get_next_line(fd);
		***map = struct_map(file_content);
		ft_strjoin(***map, file_content);
		free(file_content);
	}
	free(file_content);
	close(fd);
    
	return (NULL);
}

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
		ft_printf("accede%s\n", argv[1]);
		validate_file(argv[1]);
	}
	else
	{
		ft_printf("#########  Error  #########\n");
		ft_printf("The program need only 2 params\n");
		return (0);
	}
}
