/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:48:21 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 18:49:35 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

void	ft_size_line(char *doc, t_doc *data)
{
	int		i;
	int		fd;
	char	*buffer;
	int		size;

	i = 0;
	size = 0;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return ;
	buffer = get_next_line(fd);
	while (buffer[i] != '\n')
	{
		size++;
		while (!(ft_isspace(buffer[i])))
			i++;
		while (ft_isspace(buffer[i]) && buffer[i] != '\n')
			i++;
	}
	data->size_line = size;
	free(buffer);
	close(fd);
}

void	ft_nb_line(char *doc, t_doc *data)
{
	int		fd;
	char	*line;
	int		nb_line;

	nb_line = 0;
	fd = open(doc, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	line = NULL;
	close (fd);
	data->nbr_line = nb_line;
}

int		ft_sizeofnumb(char *line)
{
	int	i;

	i = 0;
	while (!(ft_isspace(line[i])))
		i++;
	return (i);
}