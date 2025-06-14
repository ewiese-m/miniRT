/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:08:57 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 23:15:37 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_ray	get_ray(t_scene *scene, int x, int y)
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
	pixel = tuple_transform(point_new(world_x_y[0], world_x_y[1], -1),
			matrix_inverse(*scene->camera->transform));
	origin = tuple_transform(point_new(0, 0, 0),
			matrix_inverse(*scene->camera->transform));
	ray = ray_new(origin, tuple_norm(tuple_sub(pixel, origin)));
	return (ray);
}

t_shading_data	prepare_computations(t_intersection *intersection, t_ray ray)
{
	t_shading_data	comps;

	comps.object = intersection->obj;
	comps.point = ft_point_at(ray, intersection->t);
	comps.eye = tuple_negate(ray.direction);
	comps.normal = normal_at(comps.object, comps.point);
	if (tuple_dot(comps.normal, comps.eye) < 0)
	{
		comps.normal = tuple_negate(comps.normal);
		comps.inside = true;
		comps.over_point = tuple_sub(comps.point,
				tuple_mult(comps.normal, EPSILON));
	}
	else
	{
		comps.inside = false;
		comps.over_point = tuple_add(comps.point,
				tuple_mult(comps.normal, EPSILON));
	}
	return (comps);
}

int	ray_color(t_renderer *data, t_ray ray)
{
	t_shading_data	comps;
	t_intersection	*intersection;
	t_list			*intersections;
	t_color			color;
	int				result;

	intersections = ft_intersect(data->scene->objects, ray);
	intersection = ft_hit(intersections);
	result = 0;
	if (intersection)
	{
		comps = prepare_computations(intersection, ray);
		comps.light = data->scene->lights->content;
		comps.scene = data->scene;
		ft_lstclear(&intersections, intersec_free);
		color = lighting(&comps, is_shadowed(data->scene, comps.over_point));
		result = color_to_int(color);
	}
	if (intersections)
		ft_lstclear(&intersections, intersec_free);
	return (result);
}

int	get_pixel_color(t_renderer *data, int x, int y)
{
	t_ray	ray;
	int		color;

	ray = get_ray(data->scene, x, y);
	color = ray_color(data, ray);
	return (color);
}

void	render_scene(t_renderer *data)
{
	int	x;
	int	y;

	y = data->pxl_rendered / data->mlx->win_width;
	while (y < data->mlx->win_height)
	{
		x = data->pxl_rendered % data->mlx->win_width;
		while (x < data->mlx->win_width)
		{
			mlx_add_pixels(data->mlx, x, y, get_pixel_color(data, x, y));
			x++;
			data->pxl_rendered++;
			if (data->pxl_rendered % 10 == 0)
				break ;
		}
		if (data->pxl_rendered % 10 == 0)
			break ;
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->mlx_win, data->mlx->img, 0, 0);
}
