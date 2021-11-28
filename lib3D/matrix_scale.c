/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:29:51 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:43:50 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_scale(t_matrix *matrix, t_vector *scale_v)
{
	matrix->x[0] = scale_v->x;
	matrix->y[1] = scale_v->y;
	matrix->z[2] = scale_v->z;
}

void	ft_rescale(t_matrix *matrix, t_doc *data)
{
	t_matrix	mat;

	matrix_identity(&mat);
	matrix_scale(&mat, data->ovect->scale_v);
	matrix_x_matrix(&mat, matrix);
}