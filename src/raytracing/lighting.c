/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/06/05 06:59:26 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static t_color	apply_ambient_light(t_color object_color, t_ambient ambient)
{
	t_color	result;

	result.r = (int)(object_color.r * ambient.ratio * (ambient.color.r
				/ 255.0));
	result.g = (int)(object_color.g * ambient.ratio * (ambient.color.g
				/ 255.0));
	result.b = (int)(object_color.b * ambient.ratio * (ambient.color.b
				/ 255.0));
	return (result);
}

static double	calculate_diffuse_intensity(t_vec3 normal, t_vec3 light_dir)
{
	double	dot_product;

	dot_product = vec3_dot(normal, light_dir);
	if (dot_product < 0)
		return (0);
	return (dot_product);
}

static bool	is_in_shadow(t_scene *scene, t_vec3 point, t_vec3 light_pos)
{
	t_ray	shadow_ray;
	t_vec3	to_light;
	double	light_distance;
	t_hit	shadow_hit;

	to_light = vec3_subtract(light_pos, point);
	light_distance = vec3_length(to_light);
	to_light = vec3_normalize(to_light);
	shadow_ray = create_ray(vec3_add(point, vec3_multiply(to_light, EPSILON)),
			to_light);
	shadow_hit = find_closest_hit(scene, shadow_ray);
	return (shadow_hit.hit && shadow_hit.distance < light_distance);
}

static t_color	add_diffuse_light(t_color base, t_color object_color,
		double intensity, t_light light)
{
	t_color	result;

	double r, g, b;
	r = base.r + object_color.r * intensity * light.brightness * (light.color.r
			/ 255.0);
	g = base.g + object_color.g * intensity * light.brightness * (light.color.g
			/ 255.0);
	b = base.b + object_color.b * intensity * light.brightness * (light.color.b
			/ 255.0);
	result.r = (r > 255) ? 255 : (int)r;
	result.g = (g > 255) ? 255 : (int)g;
	result.b = (b > 255) ? 255 : (int)b;
	return (result);
}

t_color	calculate_lighting(t_scene *scene, t_hit *hit, t_ray ray)
{
	t_color	final_color;
	t_vec3	light_dir;
	double	diffuse_intensity;

	(void)ray;
	final_color = apply_ambient_light(hit->color, scene->ambient);
	if (!scene->has_light || is_in_shadow(scene, hit->point,
			scene->light.position))
		return (final_color);
	light_dir = vec3_normalize(vec3_subtract(scene->light.position,
				hit->point));
	diffuse_intensity = calculate_diffuse_intensity(hit->normal, light_dir);
	if (diffuse_intensity > 0)
		final_color = add_diffuse_light(final_color, hit->color,
				diffuse_intensity, scene->light);
	return (final_color);
}
