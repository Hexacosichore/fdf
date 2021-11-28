/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:20:16 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 09:51:17 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_projection(t_matrix *m, double fov, double near, double far)
{
    int scale;

    matrix_identity(m);
    scale = 1 / (tan((fov / 2) * (M_PI / 180)));
    m->x[0] = scale;
    m->y[1] = scale;
    m->z[2] = - (far / (far - near));
    m->t[2] = - ((far * near) / (far - near));
    m->z[3] = -1;
    m->t[3] = 0;
}
