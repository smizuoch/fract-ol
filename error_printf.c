/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:14:59 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 15:36:15 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static size_t	ft_strlens(const char *s)
{
	size_t	c;

	c = 0;
	if (s == NULL)
		return (0);
	while (s[c])
	{
		c ++;
	}
	return (c);
}

static void	ft_putendl(char *s)
{
	if (s == NULL)
	{
		write (0, "\n", 1);
		return ;
	}
	write (0, s, ft_strlens(s));
	write (0, "\n", 1);
}

void	error_printf(void)
{
	ft_putendl("usage: ./fractol [fractal name]");
	ft_putendl("fractal name:");
	ft_putendl("  - mandelbrot");
	ft_putendl("  - julia");
	ft_putendl("If you choose julia, you can add parameters.");
	ft_putendl("usage: ./fractol julia [real number] [imaginary number]");
	ft_putendl("example: ./fractol julia 0.285 0.01");
	ft_putendl("The real number and the imaginary number");
	ft_putendl("                  must be between -2 and 2.");
}
