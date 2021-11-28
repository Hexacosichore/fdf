/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:37:34 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 20:45:43 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_ovect(t_doc *data)
{
	data->ovect = (t_ovect *)ft_calloc(sizeof(t_vector) * 3);
	if (!data->ovect)
		return (0);
	data->ovect->scale_v = (t_vector *)ft_calloc(sizeof(t_vector));
	data->ovect->teta = (t_vector *)ft_calloc(sizeof(t_vector));
	data->ovect->trans_v = (t_vector *)ft_calloc(sizeof(t_vector));
	if (!data->ovect->scale_v || !data->ovect->trans_v || !data->ovect->teta)
		return (0);
	data->ovect->scale_v->x = 1;
	data->ovect->scale_v->y = 1;
	data->ovect->scale_v->z = 10;
	data->ovect->teta->x = 0;
	data->ovect->teta->y = 0;
	data->ovect->teta->z = 0;
	data->ovect->trans_v->x = WIN_L / 2;
	data->ovect->trans_v->y = WIN_H / 2;
	data->ovect->trans_v->z = 1;
	return (1);
}
