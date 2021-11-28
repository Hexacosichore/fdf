/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:45:41 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:39:22 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_doc *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_L - 1 || y > WIN_H - 1)
		return ;
	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line(t_vector pt0, t_vector pt1, t_doc *data, int color)
{
	t_plot_line	line;

	line.dx = fabs(pt1.x - pt0.x);
	line.sx = (pt0.x < pt1.x) - (pt0.x >= pt1.x);
	line.dy = -fabs(pt1.y - pt0.y);
	line.sy = (pt0.y < pt1.y) - (pt0.y >= pt1.y);
	line.err = line.dx + line.dy;
	if (pt0.x == pt1.x)
		pt1.x += 1;
	if (pt0.y == pt1.y)
		pt1.y += 1;
	while (pt0.x != pt1.x && pt0.y != pt1.y)
	{
		my_mlx_pixel_put(data, pt0.x, pt0.y, color);
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			line.err += line.dy;
			pt0.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.err += line.dx;
			pt0.y += line.sy;
		}
	}
}

void	ft_draw_modif(t_doc *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_L, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	ft_draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	ft_key_hook(int keycode, t_doc *data)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		data->ovect->trans_v->y -=5;
	else if (keycode == DOWN)
		data->ovect->trans_v->x += 5;
	else if (keycode == RIGHT)
		data->ovect->trans_v->x += 5;
	else if (keycode == LEFT)
		data->ovect->trans_v->x -= 5;
	else if (keycode == ZOOM)
		data->ovect->scale_v->z += 1;
	else if (keycode == DEZOOM)
		if (data->ovect->scale_v->z > 1.0f)
			data->ovect->scale_v->z -= 1.0f;
	dprintf(1, "%f ", data->ovect->trans_v->x);
	ft_draw_modif(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_doc	*data;

	if (argc != 2)
		return (ft_error(1));
	data = malloc(sizeof(t_doc));
	if (!data || !ft_parse(argv[1], data) || !ft_init_ovect(data))
		return (ft_error(2));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1080, 1080, "MA BITE");
	data->img = mlx_new_image(data->mlx, WIN_L, WIN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
			&data->endian);
	ft_draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_key_hook(data->mlx_win, ft_key_hook, data);
	mlx_loop(data->mlx);
	ft_free(data);
}
