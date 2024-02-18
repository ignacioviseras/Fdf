/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:00:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/18 17:05:07 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*validate_file(char *file_name)
{
	char *type_extension;
	int len_extension;
	int len_file;

	type_extension = ".fdf";
	len_file = ft_strlen(file_name);
	len_extension = len_file - 4;
	if (ft_strcmp(file_name + len_extension, type_extension) == 0 && len_file > 4)
		ft_printf("es .fdf'\n");
	else
	{
		ft_printf("#########  Error  #########\n");
		ft_printf("The program need .fdf extension\n");
	}
	return ("asd");
}

int	main(int argc, char **argv)
{

	if (argc == 2)
	{
		// ft_printf("param->'%s'\n", argv[1]);
		validate_file(argv[1]);
	}
	else
	{
		ft_printf("#########  Error  #########\n");
		ft_printf("The program need only 2 params\n");
		return (0);
	}
}
