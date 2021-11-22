/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:45:41 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 17:56:26 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line(t_pts pt0, t_pts pt1, t_data *img, int color)
{
	t_plot_line	line;

	line.dx = abs (pt1.x - pt0.x);
	line.sx = (pt0.x < pt1.x) - (pt0.x >= pt1.x);
	line.dy = -abs (pt1.y - pt0.y);
	line.sy = (pt0.y < pt1.y) - (pt0.y >= pt1.y);
	line.err = line.dx + line.dy;
	while (pt0.x != pt1.x && pt0.y != pt1.y)
	{
		my_mlx_pixel_put(img, pt0.x, pt0.y, color);
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

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_pts	pt1;
// 	t_pts	pt2;

// 	pt1.x = 0;
// 	pt1.y = 1079;
// 	pt2.x = 1919;
// 	pt2.y = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "MA BITE");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	plot_line(pt1, pt2, &img, 0x00FFFF00);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

int	main(int argc, char **argv)
{
	t_doc	*data;

	data = malloc(sizeof(t_doc));
	if (argc != 2 || !data)
		return (ft_error(1));
	ft_parse(argv[1], data);
	if (!data->map)
		return (ft_error(2));
	free(data);
}
