/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:38:32 by ewiese-m        #+#    #+#             */
/*   Updated: 2025/06/15 11:37:02 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

double	length(t_tuple t1)
{
	return (sqrt(pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2)));
}

t_tuple	normalize(t_tuple t1)
{
	double	magnitude;

	magnitude = sqrt(pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2));
	t1.x /= magnitude;
	t1.y /= magnitude;
	t1.z /= magnitude;
	t1.w /= magnitude;
	return (t1);
}

double	dot_product(t_tuple t1, t_tuple t2)
{
	return (t1.x * t2.x + t1.y * t2.y + t1.z * t2.z);
}

t_tuple	vector_cross(t_tuple t1, t_tuple t2)
{
	return (vector_new(t1.y * t2.z - t1.z * t2.y, t1.z * t2.x - t1.x * t2.z,
			t1.x * t2.y - t1.y * t2.x));
}

t_tuple	vector_reflect(t_tuple t, t_tuple normal)
{
	return (subtract(t, multiply(normal, 2 * dot_product(t, normal))));
}
