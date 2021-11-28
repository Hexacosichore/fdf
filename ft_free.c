/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:25:59 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/28 18:03:32 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_free(t_doc *data)
{
    free(data->ovect->scale_v);
    free(data->ovect->teta);
    free(data->ovect->trans_v);
    free(data->ovect);
    free(data->map_pf);
    free(data->map_point);
	free(data);
}