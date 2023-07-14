/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:17:57 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/09 16:34:15 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

double	ft_atof(char *str)
{
	t_atof	vars;

	vars.res = 0.0;
	vars.div = 10.0;
	vars.sign = 1;
	vars.i = 0;
	if (!str)
		return (100);
	if (str[vars.i] == '-')
	{
		vars.sign = -1;
		vars.i++;
	}
	while (ft_isdigit(str[vars.i]))
		vars.res = vars.res * 10.0 + (double)(str[vars.i ++] - '0');
	if (str[vars.i] == '.')
		vars.i++;
	while (ft_isdigit(str[vars.i]))
	{
		vars.res = vars.res + (double)(str[vars.i ++] - '0') / vars.div;
		vars.div *= 10.0;
	}
	if (str[vars.i] != '\0')
		return (100);
	return (vars.res * vars.sign);
}
