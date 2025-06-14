/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:46:09 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:23:32 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_intersection	*create_intersect(double t, t_object *obj)
{
	t_intersection	*inter;

	inter = malloc(sizeof(t_intersection));
	if (!inter)
		return (NULL);
	inter->t = t;
	inter->obj = obj;
	return (inter);
}

double	*intersect_with(t_object *obj, t_ray ray)
{
	t_ray		ray_transformed;
	t_matrix	invert_transform;

	invert_transform = matrix_inverse(*obj->transform);
	ray_transformed = ray_transform(ray, invert_transform);
	if (obj->type == SPHERE)
		return (intersect_with_sphere(ray_transformed));
	else if (obj->type == CYLINDER)
		return (intersect_with_cylinder(obj, ray_transformed, 0, 0));
	else if (obj->type == PLANE)
		return (intersect_with_plane(ray_transformed));
	return (NULL);
}

void	add_intersections(t_list **intersections, t_object *obj, t_ray ray)
{
	t_list	*new;
	double	*inter;

	inter = intersect_with(obj, ray);
	if (inter)
	{
		new = ft_lstnew(create_intersect(inter[0], obj));
		ft_lstadd_back(intersections, new);
		if (inter[0] != inter[1])
		{
			new = ft_lstnew(create_intersect(inter[1], obj));
			ft_lstadd_back(intersections, new);
		}
		free(inter);
	}
}

void	ft_lstsort(t_list **intersections)
{
	t_list			*tmp;
	t_list			*tmp2;
	t_intersection	*inter;
	t_intersection	*inter2;

	tmp = *intersections;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			inter = tmp->content;
			inter2 = tmp2->content;
			if (inter->t > inter2->t)
			{
				tmp->content = inter2;
				tmp2->content = inter;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

t_list	*ft_intersect(t_list *objects, t_ray ray)
{
	t_list		*intersections;
	t_list		*tmp;
	t_object	*obj;

	intersections = NULL;
	tmp = objects;
	while (tmp)
	{
		obj = tmp->content;
		add_intersections(&intersections, obj, ray);
		tmp = tmp->next;
	}
	ft_lstsort(&intersections);
	return (intersections);
}
