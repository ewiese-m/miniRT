/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:48:38 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 18:21:28 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	double_equal(double nb1, double nb2)
{
	if (nb1 - nb2 < EPSILON)
		return (true);
	return (false);
}

bool	double_inf(double nb1, double nb2)
{
	if (nb1 - nb2 < EPSILON || nb1 - nb2 > -EPSILON)
		return (true);
	return (false);
}

bool	double_sup(double nb1, double nb2)
{
	if (nb1 - nb2 > EPSILON || nb1 - nb2 < -EPSILON)
		return (true);
	return (false);
}
