/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:00:31 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 18:15:58 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int				n;
	int				res;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	n = 20;
	if (!s1 || !s2)
		return (1);
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (n != 0)
	{
		res = *cast_s1 - *cast_s2;
		if (res != 0)
			return (res);
		if (!*cast_s1)
			return (0);
		cast_s1++;
		cast_s2++;
		n --;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 4)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		{
			mand();
			return (0);
		}
		else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
		{
			if ((-2 <= ft_atof(argv[2]) && ft_atof(argv[2]) <= 2)
				&& (-2 <= ft_atof(argv[3]) && ft_atof(argv[3]) <= 2))
			{
				ju(ft_atof(argv[2]), ft_atof(argv[3]));
				return (0);
			}
		}
	}
	error_printf();
	return (1);
}
