/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:32:53 by arthur            #+#    #+#             */
/*   Updated: 2025/06/15 00:06:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_tuple	tuple_new(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	point_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 1.0));
}

t_tuple	vector_new(double x, double y, double z)
{
	return (tuple_new(x, y, z, 0.0));
}
