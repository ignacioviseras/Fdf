/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:26:30 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/19 22:01:52 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"


// void	insert_matrix(char *str)
// {
// 	// char **aux;
// 	// char **matrix;
// 	t_map mapa;
	
// 	//aux = matrix;
// 	//*matrix = str;
// 	//matrix++;
// 	//free(aux);
// 	printf("insert_matrix\n", str);
// 	// printf("insert_matrix\n%s", *aux);
// }

// void	extract_content()
// {
// 	char file[] = "./maps/42.fdf";
// 	int fd;
// 	char *str;

// 	fd = open(file, O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		if (str == NULL)
// 			ft_printf("Error al abrir el archivo.\n");
// 		else
// 		{
// 			// printf("%s", str);
// 			insert_matrix(str);
// 			free(str);
// 		}
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	close(fd);
// }



// // void	parsing()
// // {
// // 	extract_content
// // }

// void leaks() {
// 	system("leaks fdf");
// }

// int	main()
// {
// 	atexit(leaks);
// 	extract_content();
// }

// int	main (void)
// {
// 	char file[] = "./maps/42.fdf";
// 	int a;
// 	char *str;

// 	a = open(file, O_RDONLY);

// 	if (BUFFER_SIZE > 100) {
// 		char *temp;
// 		do {
// 			temp = get_next_line(a);

// 			free(temp);
// 		} while (temp != NULL);
// 	}

// 	close(a);
// 	a = open(file, O_RDONLY);

// 	while((str = get_next_line(a)) != NULL)
// 	{
// 		printf("%s", str);
// 		free(str);
// 	}
// 	free(str);
// 	// printf("%s\n", get_next_line(a));
// 	// printf("%s", get_next_line(a));
// 	close(a);
// 	system("leaks a.out");
// 	return (0);
// }

int	load_map(char *file_name)
{
	
	return(0);
}
