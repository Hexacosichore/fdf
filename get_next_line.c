/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:14:18 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 14:34:49 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_calloc(int size)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	return (str);
}

static char	*ft_strlcatgnl(char *str1, char *str2)
{
	char	*dest;
	int		i[4];

	i[0] = 0;
	while (str1 && str1[i[0]])
		i[0]++;
	i[1] = 0;
	while (str2 && str2[i[1]])
		i[1]++;
	if (i[0] + i[1] == 0)
		return (NULL);
	dest = (char *)ft_calloc(i[0] + i[1] + 1);
	if (!dest)
		return (str1);
	i[2] = 0;
	while (str1 && str1[i[2]] && i[2]++ >= 0)
		dest[i[2] - 1] = str1[i[2] - 1];
	i[3] = 0;
	while (str2 && str2[i[3]] && i[3]++ >= 0)
		dest[i[2] + i[3] - 1] = str2[i[3] - 1];
	dest[i[2] + i[3]] = '\0';
	free(str1);
	return (dest);
}

static int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

static char	*ft_read(int fd, char *buff_save, int buff_size, char **line)
{
	char	actual_buff[BUFFER_SIZE + 1];
	int		pos_nl;
	int		res;

	*line = ft_strlcatgnl(NULL, buff_save);
	while (ft_find_nl(*line) == -1)
	{
		res = read(fd, actual_buff, buff_size);
		if (res <= 0)
		{
			if (buff_save)
				free(buff_save);
			return (NULL);
		}
		actual_buff[res] = '\0';
		*line = ft_strlcatgnl(*line, actual_buff);
	}
	pos_nl = ft_find_nl(*line);
	if (buff_save)
		free(buff_save);
	buff_save = ft_strlcatgnl(NULL, &(*line)[pos_nl + 1]);
	(*line)[pos_nl + 1] = '\0';
	return (buff_save);
}

char	*get_next_line(int fd)
{
	char static	*buff_save = NULL;
	char		*line;

	if (!buff_save)
	{
		buff_save = (char *)ft_calloc(BUFFER_SIZE + 1);
		if (!buff_save)
			return (NULL);
	}
	buff_save = ft_read(fd, buff_save, BUFFER_SIZE, &line);
	return (line);
}
