/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:05 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 18:02:54 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_init_map(t_doc *d, char *doc)
{
	int		fd;
	int		res;
	char	*line;

	res = 0;
	fd = open(doc, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	d->size_line = ft_size_line(line);
	free(line);
	close(fd);
	d->nbr_line = ft_nb_line(doc);
	fd = open(doc, O_RDONLY);
	if (fd == -1 || !d->nbr_line || !d->size_line)
		return (0);
	d->map = (int *)ft_calloc(sizeof(int) * d->nbr_line * d->size_line + 1);
	if (!d->map)
		return (0);
	close(fd);
	return (1);
}

static int	ft_parse_line(t_doc *data, char *line)
{
	int			i;
	int			j;
	char		*numb;
	static int	index = 0;

	i = 0;
	if (ft_size_line(line) != data->size_line)
		return (0);
	while (line[i] != '\n')
	{
		j = 0;
		numb = (char *)ft_calloc(ft_sizeofnumb(&line[i]) + 1);
		if (!numb)
			return (0);
		numb[ft_sizeofnumb(&line[i])] = '\0';
		while (line[i] && !(ft_isspace(line[i])))
			numb[j++] = line[i++];
		data->map[index] = ft_atoi(numb);
		index++;
		free(numb);
		while (line[i] && ft_isspace(line[i]) && line[i] != '\n')
			i++;
	}
	return (1);
}

static int	ft_parse_point(t_doc *data)
{
	int	index;

	index = 0;
	data->map_point = (t_vector *)ft_calloc(sizeof(t_vector) * (data->nbr_line * data->size_line));
	data->map_pf = (t_vector *)ft_calloc(sizeof(t_vector) * (data->nbr_line * data->size_line));
	if (!data->map_pf || !data->map_point)
		return (0);
	while (index < data->nbr_line * data->size_line)
	{
		data->map_point[index].x = index % data->size_line;
		data->map_point[index].y = index / data->size_line;
		data->map_point[index].z = data->map[index];
		data->map_point[index].t = 1;
		index++;
	}
	return (1);
}

int	ft_parse(char *doc, t_doc *data)
{
	char	*line;
	int		fd;

	if (!ft_init_map(data, doc))
		return (0);
	fd = open(doc, O_RDONLY);
	if (fd == -1 || !data->map)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_parse_line(data, line))
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!ft_parse_point(data))
		return (0);
	free(data->map);
	close(fd);
	return (1);
}

/*

For no leaks don't forget

free(data->map_point);
free(data);

*/