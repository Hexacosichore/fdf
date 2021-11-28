/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:57:04 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:37:06 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_translation(t_matrix *matrix, t_vector *trans_v)
{
	matrix->x[3] = trans_v->x;
	matrix->y[3] = trans_v->y;
	matrix->z[3] = trans_v->z;
	matrix->t[3] = 1;
}

void	ft_translate(t_matrix *matrix, t_doc *data)
{
	t_matrix	mat;

	matrix_identity(&mat);
	matrix_translation(&mat, data->ovect->trans_v);
	matrix_x_matrix(&mat, matrix);
}