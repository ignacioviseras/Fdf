/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:06 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/25 20:34:35 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	n_colum(char const *s, char c)
{
	int	colum;
	int	index;

	index = 0;
	colum = 0;
	index = 0;
	if (!s)
		return (0);
	while (s[index] && s[index] == c)
		index++;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			while (s[index] && s[index] == c)
				index++;
			colum++;
		}
		else
			index++;
	}
	if (s[index - 1] && s[index - 1] != c)
		colum++;
	return (colum);
}

/*

    0   1   2   3   +1 para el \0
0   h   o   l   a
1   {q, color}   u   e   s
3   t   a   l   s
4   c   o   m   o
5   e   s   t   a

    0   1   2   3   +1 para el \0         ' '
0	0	0	10	10
1
2
3
4
*/

/*
1
2
3
4
5
6
7
[0][0][0]valor
[0][0][1]color
map[0] = hola
***map = fila
**map = columna
*map = {q, color}
map = valor
*/

t_pixel    **struct_map(t_pixel **map, char *line, int c, int map_pos)
{
    int i;
    char    **line_extract;
    // t_pixel  **map;
	// char	**extract_color;
	
	
	// printf("FT_accede\n");
	map[map_pos] = ft_calloc(n_colum(line, c) + 1, sizeof(t_pixel));
	if (!map[map_pos])
		return (NULL);	
    line_extract = ft_split(line, ' ');
	i = 0;
    while (line_extract[i])
    {
		//este if no funca
		if (ft_strchr(line_extract[i], ','))
		{
			map[map_pos][i].value = ft_atoi(line_extract[i]);
			map[map_pos][i].color = atoi_base(ft_strchr(line_extract[i], ',')+1, 16);
		}
		else
		{
			// printf("accede22222\n");
			map[map_pos][i].value = ft_atoi(line_extract[i]);
			map[map_pos][i].color = 0xFFFFFF;
			// printf("(%i)\n", map[map_pos][i].value);
		}
			i++;
    }
	free_all(line_extract);
	return(map);
}
