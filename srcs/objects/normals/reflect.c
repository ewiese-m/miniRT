/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:21:21 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/17 13:55:06 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vector	reflect(t_vector in, t_vector normal)
{
	return (subtract(in, multiply(normal, 2 * dot_product(in, normal))));
}
