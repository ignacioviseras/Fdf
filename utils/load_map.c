/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:06 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/20 22:12:47 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	n_colum(char const *s, char c)
{
	int	words;
	int	index;

	index = 0;
	words = 0;
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
			words++;
		}
		else
			index++;
	}
	if (s[index - 1] && s[index - 1] != c)
		words++;
	return (words);
}

/*

    0   1   2   3   +1 para el \0
0   h   o   l   a
1   {q, color}   u   e   s
3   t   a   l   s
4   c   o   m   o
5   e   s   t   a

    0   1   2   3   +1 para el \0
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

char    ***struct_map(char *line, int c)
{
    int i;
    int x;
    int y;
    char    **line_extract;
    char    ***map;

	**map = ft_calloc(n_colum(line, c) + 1, sizeof(char *));
    line_extract = ft_split(line, ' ');
    while (*line_extract)
    {
        **map = ft_strdup(*line_extract);
		**map++;
        *line_extract++;
    }
	return(***map);
}