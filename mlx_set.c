/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:49 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 16:36:17 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reload(t_vars *data)
{
	data->img = mlx_new_image(data->mlx, PIXEL, PIXEL);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	mandelbrot_i(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook (data->win, 2, 1L << 0, key_close, data);
	mlx_hook (data->win, 17, 0L, botton_close, data);
	mlx_mouse_hook (data->win, scroll, data);
	mlx_loop(data->mlx);
}

int	scroll(int mouse_scroll, int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	if (mouse_scroll == 4)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->size = vars->size * 1.1;
		if (vars->attempts > 0.00001)
			vars->attempts = vars->attempts * 0.9;
		reload(vars);
	}
	if (mouse_scroll == 5)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->size = vars->size * 0.9;
		vars->attempts = vars->attempts * 1.1;
		reload(vars);
	}
	return (0);
}

int	to_rgb(int h)
{
	if (h < 2)
		return (0x0000FF00);
	else if (h < 3)
		return (0x006633FF);
	else if (h < 4)
		return (0x00CC9999);
	else if (h < 5)
		return (0x0099CCFF);
	if (h > 60)
		h -= 60;
	else if (h < 20)
		return (0x0000FF00);
	else if (h < 30)
		return (0x006633FF);
	else if (h < 40)
		return (0x00CC9999);
	else if (h < 50)
		return (0x0099CCFF);
	return (0x00FFCC99);
}
