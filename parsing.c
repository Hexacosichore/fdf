/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:23:05 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 18:58:49 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_init_map(t_doc *d, char *doc)
{
	int	fd;
	int	res;

	res = 0;
	ft_size_line(doc, d);
	ft_nb_line(doc, d);
	dprintf(1, "%d %d", d->size_line, d->nbr_line);
	fd = open(doc, O_RDONLY);
	if (fd == -1 || !d->nbr_line || d->size_line)
		return (0);
	d->map = (int *)ft_calloc(sizeof(int) * d->nbr_line * d->size_line);
	if (!d->map)
		return (0);
	close(fd);
}

static int	ft_parse_line(int *map, char *line)
{
	int			i;
	int			j;
	char		*numb;
	static int	index = 0;

	i = 0;
	while (line[i] != '\n')
	{
		j = 0;
		numb = ft_calloc(ft_sizeofnumb(&line[i]) + 1);
		if (!numb)
			return (0);
		while (!(ft_isspace(line[i])))
			numb[j++] = line[i++];
		ft_atoi_fdf(numb, map, index);
		index++;
		while (ft_isspace(line[i]))
			i++;
		free(numb);
	}
	return (1);
}

void	ft_parse(char *doc, t_doc *data)
{
	char	*line;
	int		fd;

	ft_init_map(data, doc);
	fd = open(doc, O_RDONLY);
	if (fd == -1 || !data->map)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		ft_parse_line(data->map, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	if (line)
		free(line);
	line = NULL;
	close(fd);
}
