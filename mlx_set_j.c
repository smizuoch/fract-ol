/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_j.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:23:47 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 18:03:54 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	reload_j(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, PIXEL, PIXEL);
	vars->addr = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length, &vars->endian);
	julia_i(vars);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook (vars->win, 2, 1L << 0, key_close, vars);
	mlx_hook (vars->win, 17, 0L, botton_close, vars);
	mlx_mouse_hook (vars->win, scroll_j, vars);
	mlx_loop (vars->mlx);
}

int	scroll_j(int mouse_scroll, int x, int y, t_vars *vars)
{
	x = 0;
	y = 0;
	if (mouse_scroll == 4)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->size = vars->size * 1.1;
		if (vars->attempts > 0.00001)
			vars->attempts = vars->attempts * 0.99;
		reload_j(vars);
	}
	if (mouse_scroll == 5)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		vars->size = vars->size * 0.9;
		vars->attempts = vars->attempts * 1.01;
		reload_j(vars);
	}
	return (0);
}
