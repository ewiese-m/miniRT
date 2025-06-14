/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:21:21 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:23:09 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vector	reflect(t_vector in, t_vector normal)
{
	return (tuple_sub(in, tuple_mult(normal, 2 * tuple_dot(in, normal))));
}
