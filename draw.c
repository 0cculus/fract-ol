/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:01:37 by brheaume          #+#    #+#             */
/*   Updated: 2023/03/03 11:19:03 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



static int		mandelbrot_compute(data_t d)
{
	int		p;
	double	a;
	double	b;
	double	real;
	double	imagine;

	p = 0;
	a = d.min_r + d.x * (d.max_r - d.min_r) / WIN_WIDTH;
	b = d.max_i + d.y * (d.min_i - d.max_i) / WIN_HEIGHT;
	d.ca = a;
	d.cb = b;
	while (p < 1)
	{
		if ((a * a) + (b * b) > 16)
			 break;
		p++;
	}
	return (p);
}

void	mandelbrot(data_t data)
{
	int pixel_val;
	
	data.y = 0;
	data.x = 0;
	while (data.y < WIN_HEIGHT)
	{
		while (data.x < WIN_WIDTH)
		{
			pixel_val = mandelbrot_compute(data);
			if (pixel_val)
				mlx_put_pixel(data.img, data.x, data.y, \
							rgb_to_uint32t(255, 0, 255));
			else
				mlx_put_pixel(data.img, data.x, data.y, \
							rgb_to_uint32t(0, 0, 0));
			x++;
		}
		y++;
	}
}

static int		julia_compute(data_t data)
{}

void	julia(data_t data)
{
	int	pixel_val;

	data.y = 0;
	data.x = 0;
	while (data.y < WIN_HEIGHT)
	{
		while (data.x < WIN_WIDTH)
		{
				pixel_val = julia_compute(data);
				mlx_put_pixel(img, x, y, rgb_to_uint32t(255, 0, 255));
				x++;
		}
		y++;
	}
}
