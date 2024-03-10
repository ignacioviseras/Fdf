/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:06 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/10 16:52:07 by igvisera         ###   ########.fr       */
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

t_pixel	*struct_map(char *line, int c)
{
	int		i;
	char	**line_extract;
	t_pixel	*map;

	map = ft_calloc(n_colum(line, c) + 1, sizeof(t_pixel));
	if (!map)
		return (NULL);
	line_extract = ft_split(line, ' ');
	i = -1;
	while (line_extract[++i])
	{
		if (ft_strchr(line_extract[i], ','))
		{
			map[i].value = ft_atoi(line_extract[i]);
			map[i].color = atoi_base(ft_strchr(line_extract[i], ',')
					+ 1, 16);
		}
		else
		{
			map[i].value = ft_atoi(line_extract[i]);
			map[i].color = 0xFFFFFF;
		}
	}
	map[0].number_col = i;
	return (free_all((void **)line_extract), map);
}
