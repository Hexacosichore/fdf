/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:39:48 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 17:24:41 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_rotation_x(t_matrix *matrix, double teta)
{
	matrix->y[1] = cos(teta);
	matrix->y[2] = -sin(teta);
	matrix->z[1] = sin(teta);
	matrix->z[2] = cos(teta);
}

void	matrix_rotation_y(t_matrix *matrix, double teta)
{
	matrix->x[0] = cos(teta);
	matrix->z[0] = -sin(teta);
	matrix->x[2] = sin(teta);
	matrix->z[2] = cos(teta);
}

void	matrix_rotation_z(t_matrix *matrix, double teta)
{
	matrix->x[0] = cos(teta);
	matrix->x[1] = -sin(teta);
	matrix->y[0] = sin(teta);
	matrix->y[1] = cos(teta);
}

void	ft_rotate(t_matrix *matrix, t_doc *data)
{
	t_matrix	mat;

	matrix_identity(&mat);
	matrix_rotation_x(&mat, data->ovect->teta->x);
	matrix_rotation_y(&mat, data->ovect->teta->y);
	matrix_rotation_z(&mat, data->ovect->teta->z);
	matrix_x_matrix(&mat, matrix);
}