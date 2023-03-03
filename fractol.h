/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:20:38 by brheaume          #+#    #+#             */
/*   Updated: 2023/03/03 09:34:48 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 900
# endif
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1500
# endif
# ifndef ERR_ARG
#  define ERR_ARG 1
# endif
# ifndef MAX_ZOOM
#  define MAX_ZOOM 2.5
# endif

typedef struct	s_data
{
	int				x;
	int				y;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			ca;
	double			cb;
	double			zoom;
	mlx_image_t*	img;
}				data_t;

void		julia(data_t *d);
void		mandelbrot(data_t *d);
double		ft_atof(const char *src);
uint32_t	rgb_to_uint32t(double r, double g, double b);

#endif
