/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:38:32 by arthur            #+#    #+#             */
/*   Updated: 2025/06/13 21:08:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

double	tuple_mag(t_tuple t1)
{
	return (sqrt(pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2)));
}

t_tuple	tuple_norm(t_tuple t1)
{
	double	magnitude;

	magnitude = sqrt(pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2));
	t1.x /= magnitude;
	t1.y /= magnitude;
	t1.z /= magnitude;
	t1.w /= magnitude;
	return (t1);
}

double	tuple_dot(t_tuple t1, t_tuple t2)
{
	return (t1.x * t2.x + t1.y * t2.y + t1.z * t2.z);
}

t_tuple	tuple_cross(t_tuple t1, t_tuple t2)
{
	return (vector_new(t1.y * t2.z - t1.z * t2.y,
			t1.z * t2.x - t1.x * t2.z,
			t1.x * t2.y - t1.y * t2.x));
}

t_tuple	tuple_reflect(t_tuple t, t_tuple normal)
{
	return (tuple_sub(t, tuple_mult(normal, 2 * tuple_dot(t, normal))));
}
