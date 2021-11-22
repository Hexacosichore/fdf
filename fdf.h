/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:17:31 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 19:11:32 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 42


# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//All structures

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_plot_line
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_plot_line;

typedef struct s_doc
{
	int		*map;
	int		size_line;
	int		nbr_line;
}				t_doc;

typedef struct s_pts
{
	int	x;
	int	y;
	int	z;
}				t_pts;

//error.c

int		ft_error(int nbr);

//get_next_line.c

char	*ft_calloc(int size);
char	*get_next_line(int fd);

//parsing_size.c && parsing.c && parsing_atoi.c

int		ft_isspace(int c);
void	ft_parse(char *doc, t_doc *data);
void	ft_size_line(char *doc, t_doc *data);
void	ft_nb_line(char *doc, t_doc *data);
int		ft_sizeofnumb(char *line);
void    ft_atoi_fdf(char *numb, int *map, int index);

#endif