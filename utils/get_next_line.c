/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:41:10 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:41:10 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	char	*extract(char *buffer)
{
	char	*sentence;
	int		len_sentence;
	int		len_all;

	if (!buffer || !*buffer)
		return (NULL);
	len_all = 0;
	len_sentence = 0;
	len_all = ft_strlen(buffer);
	len_sentence = ft_strlen(ft_strchr(buffer, '\n'));
	sentence = ft_substr(buffer, 0, len_all - len_sentence);
	return (sentence);
}

static	char	*line(char **txt)
{
	char	*aux;
	char	*finder;
	char	*t;

	if (!*txt)
		return (NULL);
	finder = ft_strchr(*txt, '\n');
	if (finder)
	{
		aux = extract(*txt);
		t = *txt;
		*txt = ft_strdup(finder + 1);
		free(t);
		return (aux);
	}
	else
	{
		aux = ft_strdup(*txt);
		free(*txt);
		*txt = NULL;
		return (aux);
	}
	return (aux);
}

static	char	*read_file(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			status;
	static char	*txt;
	char		*aux;

	status = read(fd, buffer, BUFFER_SIZE);
	while (status > 0)
	{
		buffer[status] = '\0';
		if (!txt || !*txt)
			txt = ft_strdup(buffer);
		else
		{
			aux = txt;
			txt = ft_strjoin(txt, buffer);
			free(aux);
		}
		if (ft_strchr(txt, '\n') || !(ft_strchr(txt, '\0')))
			break ;
		status = read(fd, buffer, BUFFER_SIZE);
	}
	if (status < 0)
		return (free(txt), txt = NULL, txt);
	return (line(&txt));
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd);
	return (line);
}
