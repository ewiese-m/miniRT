/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:58:20 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:22:16 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_point	ray_position(t_ray ray, double t)
{
	return (tuple_add(ray.origin, tuple_mult(ray.direction, t)));
}
