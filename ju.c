/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ju.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:19:32 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 18:09:43 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static void	set_j(t_julia *data)
{
	data->y = 0;
	data->x = 0;
	data->i = 0;
}

static void	cn(t_julia *data, double size)
{
	data->z_real = (double)data->x * size / (double)PIXEL - size / 2;
	data->z_imge = (double)data->y * size / (double)PIXEL - size / 2;
	data->i = 0;
}

static void	julia_init(t_julia *data, double real, double imge)
{
	double	z_real_new;
	double	z_imge_new;

	z_real_new = data->z_real * data->z_real
		- data->z_imge * data->z_imge + real;
	z_imge_new = 2.0 * data->z_real * data->z_imge + imge;
	data->z_real = z_real_new;
	data->z_imge = z_imge_new;
	data->i ++;
}

void	julia_i(t_vars *vars)
{
	t_julia	data;

	set_j(&data);
	while (data.y < PIXEL)
	{
		data.x = 0;
		while (data.x < PIXEL)
		{
			cn(&data, vars->size);
			while (data.i < vars->attempts
				&& data.z_real * data.z_real + data.z_imge * data.z_imge < 4.0)
			{
				julia_init(&data, vars->real, vars->imge);
				if (data.z_real * data.z_real + data.z_imge * data.z_imge > 4)
				{
					my_mlx_pixel_put(vars, data.x, data.y, to_rgb(data.i));
					break ;
				}
			}
			if (data.i == vars->attempts)
				my_mlx_pixel_put(vars, data.x, data.y, 0x00000000);
			data.x ++;
		}
		data.y ++;
	}
}

int	ju(double real, double imge)
{
	t_vars	vars;

	vars.real = real;
	vars.imge = imge;
	reset(&vars);
	vars.mlx = mlx_init ();
	vars.win = mlx_new_window(vars.mlx, PIXEL, PIXEL, "julia");
	vars.img = mlx_new_image(vars.mlx, PIXEL, PIXEL);
	vars.addr = mlx_get_data_addr(vars.img,
			&vars.bits_per_pixel, &vars.line_length, &vars.endian);
	julia_i(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook (vars.win, 2, 1L << 0, key_close, &vars);
	mlx_hook (vars.win, 17, 0L, botton_close, &vars);
	mlx_mouse_hook (vars.win, scroll_j, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
