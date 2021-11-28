/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:16:30 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:41:52 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isom(t_doc *d)
{
	t_matrix	mat;
	t_vector	ref;
	int			i[2];

	matrix_identity(&mat);
	ft_rescale(&mat, d);
	ft_translate(&mat, d);
	i[1] = -1;
	while (++i[1] < d->nbr_line)
	{
		i[0] = -1;
		while (++i[0] < d->size_line)
		{
			ref = d->map_point[i[0] + i[1] * d->size_line];
			matrix_x_vector(&mat, &ref);
			d->map_pf[i[0] + i[1] * d->size_line].x = (ref.x * d->ovect->scale_v->z)
					- (ref.y * d->ovect->scale_v->z);
			d->map_pf[i[0] + i[1] * d->size_line].y = (ref.y * d->ovect->scale_v->z / 2)
					+ (ref.x * d->ovect->scale_v->z / 2);
			d->map_pf[i[0] + i[1] * d->size_line].y -= ref.z * 0.03f;
		}
	}
}

int	ft_draw(t_doc *d)
{
	int	i[2];

	ft_isom(d);
	i[1] = -1;
	while (++i[1] < d->nbr_line)
	{
		i[0] = -1;
		while (++i[0] < d->size_line)
		{
			//my_mlx_pixel_put(d, (int)d->map_pf[i[0] + i[1] * d->size_line].x, (int)d->map_pf[i[0] + i[1] * d->size_line].y, 0x00FF0000);
			if (i[1] + 1 < d->nbr_line && i[0] + 1 <= d->size_line)
				plot_line(d->map_pf[i[0] + i[1] * d->size_line], d->map_pf[i[0] + i[1] * d->size_line + d->size_line], d, 0x00FF0000);
			if (i[0] + 1 < d->size_line)
				plot_line(d->map_pf[i[0] + i[1] * d->size_line], d->map_pf[i[0] + i[1] * d->size_line + 1], d, 0x00FF0000);
			
		}
	}
	// while (i < d->size_line * d->nbr_line)
	// {
	// 	dprintf(1, "x: %f, y: %f, z: %f, t: %f\n", d->map_point[i].x, d->map_point[i].y, d->map_point[i].z, d->map_point[i].t);
	// 	i++;
	// }
	return (1);
}