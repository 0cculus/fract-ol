/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:02:44 by brheaume          #+#    #+#             */
/*   Updated: 2023/03/02 11:05:49 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rgb_to_uint32t(double r, double g, double b)
{
	return ((r * 16777216) + (g * 65536) + (b * 256) + 0xFF);
}

double	ft_atof(const char *src)
{
	int		i;
	double	res;
	double	point;
	int		negativ;

	point = 0.1;
	res = 0.0;
	i = ;
	while (src[i] && ft_isdigit(src[i]) && src[i] != '.')
	{
		res = (res * 10.0) + (src[i] - '0');
		i++;
	}
	if (src[i] == '.' && src[i])
		i++;
	while (src[i] && ft_isdigit(src[i]))
	{
		res = res + ((src[i] - '0') * point);
		point *= 0.1;
		i++;
	}
	if (src[i] && !ft_isdigit(src[i]))
		return (0);
	return (res * negativ);
}
