/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:59:52 by kbarbry           #+#    #+#             */
/*   Updated: 2021/11/22 19:19:23 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	result;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	if (!nptr)
		return (result);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (nptr[i] >= '0' && nptr <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	ft_atoihexa_fdf(const char *nptr)
{
	unsigned int	i;
	unsigned int	result;
    char            *base;
    char            *base2;

	i = 0;
	result = 0;
    base = "0123456789ABCDEF";
    base2 = "0123456789abcdef"
}

void    ft_atoi_fdf(char *numb, int *map, int index)
{
    int         i;
    int    res;

    i = 0;
    if (ft_strlen(numb) > 2 && numb[1] == 'x')
        res = ft_atoihexa_fdf((const char *)&numb[2]);
    else
        res = ft_atoi((const char *)numb);
    map[index] = res;
}
