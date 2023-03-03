/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:34 by brheaume          #+#    #+#             */
/*   Updated: 2023/03/03 09:33:58 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

data_t init(void)
{
	mlx_image_t	 *img;
	data_t data;

	data.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data.x = 0;
	data.y = 0;
	data.min_r = -2;
	data.max_r = 2;
	data.max_i = 2;
	data.min_i = -2;
	return data;
}

int	main(int ac, char** av)
{
	if (ac > 1 && ac < 5)
	{
		mlx_t	*mlx;
		data_t	d;

		mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "fractol", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		d = init();
		ft_memset(d.img->pixels, 1, d.img->width * d.img->height * sizeof(int));
		mlx_image_to_window(mlx, img, 0, 0);
		if (!ft_strncmp(av[1], "m", 1))
			mandelbrot(&data);
		else if (!ft_strncmp(av[1], "j", 1))
			julia(&data);
		mlx_loop_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	return (ERR_ARG);
}
