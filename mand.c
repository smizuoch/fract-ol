/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:40:44 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 16:35:11 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	setzero(t_mandelbrot *data)
{
	data->k = 0;
	data->a = 0;
	data->b = 0;
}

static void	set(t_mandelbrot *data)
{
	data->i = 0;
	data->j = 0;
	data->k = 0;
}

static void	mandelbrot_init(t_mandelbrot *data, double size)
{
	double	x;
	double	y;

	x = data->i * size / PIXEL - size / 2;
	y = data->j * size / PIXEL - size / 2;
	data->_a = data->a * data->a - data->b * data->b + x;
	data->_b = 2 * data->a * data->b + y;
	data->a = data->_a;
	data->b = data->_b;
}

void	mandelbrot_i(t_vars *vars)
{
	t_mandelbrot	data;

	set(&data);
	while (PIXEL > data.i)
	{
		data.j = 0;
		while (PIXEL > data.j)
		{
			setzero(&data);
			while (data.k < vars->attempts)
			{
				mandelbrot_init(&data, vars->size);
				if (data.a * data.a + data.b * data.b > 4)
				{
					my_mlx_pixel_put(vars, data.i, data.j, to_rgb(data.k));
					break ;
				}
				data.k ++;
			}
			if (data.k == vars->attempts)
				my_mlx_pixel_put(vars, data.i, data.j, 0x00000000);
			data.j ++;
		}
		data.i ++;
	}
}

int	mand(void)
{
	t_vars	vars;

	reset(&vars);
	vars.mlx = mlx_init ();
	vars.win = mlx_new_window(vars.mlx, PIXEL, PIXEL, "mandelbrot");
	vars.img = mlx_new_image(vars.mlx, PIXEL, PIXEL);
	vars.addr = mlx_get_data_addr(vars.img,
			&vars.bits_per_pixel, &vars.line_length, &vars.endian);
	mandelbrot_i(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook (vars.win, 2, 1L << 0, key_close, &vars);
	mlx_hook (vars.win, 17, 0L, botton_close, &vars);
	mlx_mouse_hook (vars.win, scroll, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
