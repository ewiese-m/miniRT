/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:33:36 by arthur            #+#    #+#             */
/*   Updated: 2025/06/15 00:05:23 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRT.h"

t_tuple	vector_add(t_tuple t1, t_tuple t2)
{
	return (tuple_new(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z, t1.w + t2.w));
}

t_tuple	vector_sub(t_tuple t1, t_tuple t2)
{
	return (tuple_new(t1.x - t2.x, t1.y - t2.y, t1.z - t2.z, t1.w - t2.w));
}

t_tuple	vector_mult(t_tuple t1, double nb)
{
	return (tuple_new(t1.x * nb, t1.y * nb, t1.z * nb, t1.w * nb));
}

t_tuple	vector_div(t_tuple t1, t_tuple t2)
{
	return (tuple_new(t1.x / t2.x, t1.y / t2.y, t1.z / t2.z, t1.w / t2.w));
}

t_tuple	vector_negate(t_tuple t1)
{
	return (tuple_new(-t1.x, -t1.y, -t1.z, -t1.w));
}
