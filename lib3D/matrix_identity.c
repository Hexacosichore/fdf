/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:45:21 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/24 13:36:10 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_identity(t_matrix *matrix)
{
	matrix_bzero(matrix);
	matrix->x[0] = 1;
	matrix->y[1] = 1;
	matrix->z[2] = 1;
	matrix->t[3] = 1;
}
