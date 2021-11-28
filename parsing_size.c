/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:48:21 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/23 17:39:13 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_size_line(char *line)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (line[i] != '\n')
	{
		size++;
		while (!(ft_isspace(line[i])))
			i++;
		while (ft_isspace(line[i]) && line[i] != '\n')
			i++;
	}
	return (size);
}

int	ft_nb_line(char *doc)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close (fd);
	return (nb_line);
}

int	ft_sizeofnumb(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !(ft_isspace(line[i])))
		i++;
	return (i);
}
