/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:19:53 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_add(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 + c2.chan_1;
	color.chan_2 = c1.chan_2 + c2.chan_2;
	color.chan_3 = c1.chan_3 + c2.chan_3;
	return (color);
}

t_color	color_sub(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 - c2.chan_1;
	color.chan_2 = c1.chan_2 - c2.chan_2;
	color.chan_3 = c1.chan_3 - c2.chan_3;
	return (color);
}

t_color	color_mult(t_color c1, t_color c2)
{
	t_color	color;

	color.chan_1 = c1.chan_1 * c2.chan_1;
	color.chan_2 = c1.chan_2 * c2.chan_2;
	color.chan_3 = c1.chan_3 * c2.chan_3;
	return (color);
}

t_color	color_scalar(t_color c, double scalar)
{
	t_color	color;

	color.chan_1 = c.chan_1 * scalar;
	color.chan_2 = c.chan_2 * scalar;
	color.chan_3 = c.chan_3 * scalar;
	return (color);
}

int	color_to_int(t_color color)
{
	int		r;
	int		g;
	int		b;

	if (color.chan_1 > 1)
		color.chan_1 = 1;
	if (color.chan_2 > 1)
		color.chan_2 = 1;
	if (color.chan_3 > 1)
		color.chan_3 = 1;
	r = 255 * color.chan_1;
	g = 255 * color.chan_2;
	b = 255 * color.chan_3;
	return (r << 16 | g << 8 | b);
}
