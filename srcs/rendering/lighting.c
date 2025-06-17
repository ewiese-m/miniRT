/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:21:14 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 13:58:55 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

bool	in_shadow(t_scene *scene, t_point point)
{
	t_vector		v;
	t_vector		direction;
	t_ray			ray;
	t_list			*intersections;
	t_intersection	*hit;

	v = subtract(((t_light *)scene->lights->content)->position, point);
	direction = normalize(v);
	ray = ray_new(point, direction);
	intersections = ft_intersect(scene->objects, ray);
	hit = get_closest_hit(intersections);
	if (hit != NULL && hit->t < length(v))
	{
		ft_lstclear(&intersections, intersec_free);
		return (true);
	}
	ft_lstclear(&intersections, intersec_free);
	return (false);
}

t_color	get_diffuse_and_spec(t_shading_data	*lighting_info,
	t_vector	lightv, double light_dot_normal)
{
	t_color		diffuse;
	t_color		specular;
	t_vector	reflectv;
	double		reflect_dot_eye;
	double		factor;

	diffuse = mult_colors(lighting_info->object->material->color,
			lighting_info->light->color);
	diffuse = scale_color(diffuse, lighting_info->object->material->diffuse
			* light_dot_normal * lighting_info->light->brightness);
	reflectv = reflect(negate(lightv), lighting_info->normal);
	reflect_dot_eye = dot_product(reflectv, lighting_info->eye);
	if (reflect_dot_eye <= 0)
		specular = new_color(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye,
				lighting_info->object->material->shininess);
		specular = scale_color(lighting_info->light->color,
				lighting_info->object->material->specular
				* factor * lighting_info->light->brightness);
	}
	return (add_colors(diffuse, specular));
}

t_color	lighting(t_shading_data	*lighting_info, bool	shadowed)
{
	t_color		ambient;
	t_vector	lightv;
	double		light_dot_normal;

	lightv = normalize(subtract(lighting_info->light->position,
				lighting_info->point));
	ambient = mult_colors(lighting_info->object->material->color,
			lighting_info->object->material->ambient->color);
	if (shadowed)
		return (ambient);
	light_dot_normal = dot_product(lightv, lighting_info->normal);
	if (light_dot_normal < 0 || lighting_info->light->brightness <= 0)
		return (ambient);
	else
		return (add_colors(ambient,
				get_diffuse_and_spec(lighting_info, lightv, light_dot_normal)));
}
