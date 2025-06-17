/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:08:57 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 14:19:14 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static t_ray	get_ray(t_scene *scene, int x, int y)
{
	t_ray	ray;
	double	x_y_offset[2];
	double	world_x_y[2];
	t_point	pixel;
	t_point	origin;

	x_y_offset[0] = (x + 0.5) * scene->camera->pixel_size;
	x_y_offset[1] = (y + 0.5) * scene->camera->pixel_size;
	world_x_y[0] = scene->camera->half_width - x_y_offset[0];
	world_x_y[1] = scene->camera->half_height - x_y_offset[1];
	pixel = transform_vector(point_new(world_x_y[0], world_x_y[1], -1),
			matrix_inverse(*scene->camera->transform));
	origin = transform_vector(point_new(0, 0, 0),
			matrix_inverse(*scene->camera->transform));
	ray = ray_new(origin, normalize(subtract(pixel, origin)));
	return (ray);
}

static t_shading_data	prepare_hit(t_intersection *intersection, t_ray ray)
{
	t_shading_data	comps;

	comps.object = intersection->obj;
	comps.point = ray_position(ray, intersection->t);
	comps.eye = negate(ray.direction);
	comps.normal = surface_normal(comps.object, comps.point);
	if (dot_product(comps.normal, comps.eye) < 0)
	{
		comps.normal = negate(comps.normal);
		comps.inside = true;
		comps.over_point = subtract(comps.point, multiply(comps.normal,
					EPSILON));
	}
	else
	{
		comps.inside = false;
		comps.over_point = add(comps.point, multiply(comps.normal, EPSILON));
	}
	return (comps);
}

static int	trace_ray(t_renderer *data, t_ray ray)
{
	t_shading_data	comps;
	t_intersection	*intersection;
	t_list			*intersections;
	t_color			color;
	int				result;

	intersections = ft_intersect(data->scene->objects, ray);
	intersection = get_closest_hit(intersections);
	result = 0;
	if (intersection)
	{
		comps = prepare_hit(intersection, ray);
		comps.light = data->scene->lights->content;
		comps.scene = data->scene;
		ft_lstclear(&intersections, intersec_free);
		color = lighting(&comps, in_shadow(data->scene, comps.over_point));
		result = color_to_rgb(color);
	}
	if (intersections)
		ft_lstclear(&intersections, intersec_free);
	return (result);
}

static int	compute_pixel(t_renderer *data, int x, int y)
{
	t_ray	ray;
	int		color;

	ray = get_ray(data->scene, x, y);
	color = trace_ray(data, ray);
	return (color);
}

void	render(t_renderer *data)
{
	int	x;
	int	y;

	y = data->pxl_rendered / data->mlx->win_width;
	while (y < data->mlx->win_height)
	{
		x = data->pxl_rendered % data->mlx->win_width;
		while (x < data->mlx->win_width)
		{
			put_pixel(data->mlx, x, y, compute_pixel(data, x, y));
			x++;
			data->pxl_rendered++;
			if (data->pxl_rendered % 10 == 0)
				break ;
		}
		if (data->pxl_rendered % 10 == 0)
			break ;
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->img,
		0, 0);
}
