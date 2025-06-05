/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/06/05 06:58:13 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

static t_vec3	get_pixel_direction(t_camera *camera, double u, double v)
{
	t_vec3	direction;
	double	scale;
	double	aspect_ratio;

	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	scale = tan(degrees_to_radians(camera->fov) / 2.0);
	direction = camera->forward;
	direction = vec3_add(direction, vec3_multiply(camera->right, u * scale
				* aspect_ratio));
	direction = vec3_add(direction, vec3_multiply(camera->up, v * scale));
	return (vec3_normalize(direction));
}

t_ray	camera_ray(t_camera *camera, double x, double y, int width, int height)
{
	double	u;
	double	v;
	t_vec3	direction;

	u = (2.0 * x / width) - 1.0;
	v = 1.0 - (2.0 * y / height);
	direction = get_pixel_direction(camera, u, v);
	return (create_ray(camera->position, direction));
}

void	update_camera_vectors(t_camera *camera)
{
	t_vec3	world_up;
	double	dot;

	world_up = vec3_new(0.0, 1.0, 0.0);
	camera->forward = vec3_normalize(camera->orientation);
	dot = vec3_dot(camera->forward, world_up);
	if (fabs(dot) > 0.99)
	{
		if (camera->forward.y > 0)
			world_up = vec3_new(0.0, 0.0, -1.0);
		else
			world_up = vec3_new(0.0, 0.0, 1.0);
	}
	camera->right = vec3_normalize(vec3_cross(world_up, camera->forward));
	camera->up = vec3_normalize(vec3_cross(camera->forward, camera->right));
}

t_vec3	get_camera_direction(t_camera *camera, int x, int y)
{
	double	u;
	double	v;

	u = (double)x / WINDOW_WIDTH;
	v = (double)y / WINDOW_HEIGHT;
	return (get_pixel_direction(camera, (u * 2.0) - 1.0, 1.0 - (v * 2.0)));
}
