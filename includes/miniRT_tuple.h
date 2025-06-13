/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_tuple.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:23:55 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/13 21:08:45 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TUPLE_H
# define MINIRT_TUPLE_H

# include "./miniRT_struct.h"

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}		t_tuple;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;

#endif
