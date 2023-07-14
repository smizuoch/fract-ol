/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:21:31 by smizuoch          #+#    #+#             */
/*   Updated: 2023/07/14 17:22:52 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	reset(t_vars *date)
{
	date->bits_per_pixel = 0;
	date->line_length = 0;
	date->endian = 0;
	date->size = 4;
	date->attempts = 100;
	return (0);
}
