/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:47:06 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/20 21:13:37 by igvisera         ###   ########.fr       */
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

static char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len_word;
	char	**str;

	i = 0;
	str = ft_calloc(n_colum(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s && *s != '\0')
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (str[i] = NULL, str);
		if (!ft_strchr(s, c))
			len_word = ft_strlen(s);
		else
			len_word = ft_strchr(s, c) - s;
		str[i] = ft_substr(s, 0, len_word);
		if (!str[i++])
			return (free_all(str), NULL);
		s += len_word;
	}
	return (str[i] = NULL, str);
}

/*

    0   1   2   3   +1 para el \0
0   h   o   l   a
1   {q, color}   u   e   s
3   t   a   l   s
4   c   o   m   o
5   e   s   t   a

*/
/*
1
2
3
4
5
6
7

[0][0][0] 1 [0][0][1] color
[0][1][0] 2
[0][2][0] 3
[0][3][0] 4

[1][0][0] 1

*/

char    ***load_map(char *line)
{
    int i;
    int x;
    int y;
    char    **line_extract;
    char    ***map;

    line_extract = ft_split(line, ' ');
    while ()
    {
        ***map = ft_strdup(li)
        while (/* condition */)
        {
            // if (hay com)
            // {
            //     /* code */
            // }
            
        }
        
    }
    

}