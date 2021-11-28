/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:17:31 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:29:20 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 42
# define WIN_L 1080
# define WIN_H 1080
//hooks

# define ZOOM 126
# define DEZOOM 125
# define RIGHT 2
# define LEFT 0
# define UP 13
# define DOWN 1
# define ROT_Z_R 14 //E
# define ROT_Z_L 12 //Q
# define ROT_X_R 15 //R
# define ROT_X_L 17 //T
# define ROT_Y_R 16 //Y
# define ROT_Y_L 32 //U
# define ESC 53

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

//All structures

typedef struct s_plot_line
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_plot_line;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	t;
}				t_vector;

typedef struct s_ovect
{
	t_vector	*scale_v;
	t_vector	*trans_v;
	t_vector	*teta;
}				t_ovect;

typedef struct s_doc
{
	int			*map;
	t_vector	*map_point;
	t_vector	*map_pf;
	void		*mlx_win;
	t_ovect		*ovect;
	int			size_line;
	int			nbr_line;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
}				t_doc;

//error.c

int		ft_error(int nbr);

//get_next_line.c

char	*ft_calloc(int size);
char	*get_next_line(int fd);

//all parsing

int		ft_parse(char *doc, t_doc *data);

int		ft_isspace(int c);
int		ft_size_line(char *doc);
int		ft_nb_line(char *doc);
int		ft_sizeofnumb(char *line);

int		ft_atoi(char *nptr);
int		ft_strlen(const char *s);

//lib3D

typedef struct s_matrix
{
	double	x[4];
	double	y[4];
	double	z[4];
	double	t[4];
}				t_matrix;

void		matrix_bzero(t_matrix *matrix);
void		matrix_identity(t_matrix *matrix);
void		matrix_x_vector(t_matrix *m, t_vector *v);
void		matrix_x_matrix(t_matrix *m, t_matrix *v);
void		matrix_projection(t_matrix *m, double fov, double near, double far);
void		matrix_rotation_x(t_matrix *matrix, double teta);
void		matrix_rotation_y(t_matrix *matrix, double teta);
void		matrix_rotation_z(t_matrix *matrix, double teta);
void		matrix_scale(t_matrix *matrix, t_vector *scale_v);
void		matrix_translation(t_matrix *matrix, t_vector *trans_v);
void		ft_translate(t_matrix *matrix, t_doc *data);
void		ft_rotate(t_matrix *matrix, t_doc *data);
void		ft_rescale(t_matrix *matrix, t_doc *data);

//For drawing

t_matrix	*origin_vector(t_doc *data);
int			ft_draw(t_doc *d);
int			ft_init_ovect(t_doc *data);
void		ft_free(t_doc *data);
void		my_mlx_pixel_put(t_doc *data, int x, int y, int color);
void		plot_line(t_vector pt0, t_vector pt1, t_doc *data, int color);

#endif
