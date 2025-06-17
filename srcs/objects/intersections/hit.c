/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:33:47 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 13:58:57 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_intersection	*get_closest_hit(t_list *intersections)
{
	t_list			*tmp;
	t_intersection	*hit;

	tmp = intersections;
	hit = NULL;
	while (tmp)
	{
		if (tmp->content
			&& (!hit || ((t_intersection *)tmp->content)->t < hit->t)
			&& ((t_intersection *)tmp->content)->t > 0)
			hit = tmp->content;
		tmp = tmp->next;
	}
	return (hit);
}
