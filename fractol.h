/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:44:43 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 18:16:55 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>

# define PIXEL 1000

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	size;
	double	attempts;
	double	real;
	double	imge;
}	t_vars;

typedef struct s_mandelbrot
{
	double	x;
	double	y;
	double	a;
	double	b;
	double	_a;
	double	_b;
	double	k;
	double	i;
	double	j;
}	t_mandelbrot;

typedef struct s_julia
{
	int		x;
	int		y;
	double	z_real;
	double	z_imge;
	double	z_real_new;
	double	z_imge_new;
	int		i;
}	t_julia;

typedef struct s_atof
{
	int		sign;
	int		i;
	double	res;
	double	div;
}	t_atof;

void	error_printf(void);

int		key_close(int keycode, t_vars *vars);
int		botton_close(t_vars *vars);

double	ft_atof(char *str);

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		scroll(int mouse_scroll, int x, int y, t_vars *vars);
int		to_rgb(int h);

void	mandelbrot_i(t_vars *vars);
int		mand(void);

int		reset(t_vars *vars);

int		scroll_j(int mouse_scroll, int x, int y, t_vars *vars);
int		ju(double real, double imge);
void	julia_i(t_vars *vars);

#endif
