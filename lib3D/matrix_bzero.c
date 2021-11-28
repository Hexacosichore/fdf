/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:30:16 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/24 13:56:59 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	matrix_bzero(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix->x[i] = 0;
		matrix->y[i] = 0;
		matrix->z[i] = 0;
		matrix->t[i] = 0;
		i++;
	}
}
