/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	is_valid_fov(double fov)
{
	return (fov >= MIN_FOV && fov <= MAX_FOV);
}


static bool	is_normalized_vector(t_vec3 *vec)
{
	double	length;

	length = vec3_length(*vec);
	return (fabs(length - 1.0) < EPSILON);
}


bool	validate_camera_data(t_camera *camera)
{
	if (!is_valid_fov(camera->fov))
		return (error_message("Camera FOV must be between 0 and 180"));
	if (!is_normalized_vector(&camera->orientation))
		return (error_message("Camera orientation must be normalized"));
	return (true);
}


void	setup_camera_basis(t_camera *camera)
{
	t_vec3	world_up;
	double	dot;

	world_up = vec3_new(0.0, 1.0, 0.0);
	camera->forward = vec3_normalize(camera->orientation);
	dot = vec3_dot(camera->forward, world_up);
	if (fabs(dot) > 0.99)
	{
		if (dot > 0)
			world_up = vec3_new(0.0, 0.0, -1.0);
		else
			world_up = vec3_new(0.0, 0.0, 1.0);
	}
	camera->right = vec3_normalize(vec3_cross(world_up, camera->forward));
	camera->up = vec3_normalize(vec3_cross(camera->forward, camera->right));
}


t_vec3	calculate_ray_direction(t_camera *camera, double u, double v)
{
	t_vec3	direction;
	double	fov_rad;
	double	aspect_ratio;
	double	scale;

	aspect_ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
	fov_rad = camera->fov * PI / 180.0;
	scale = tan(fov_rad / 2.0);
	direction = camera->forward;
	direction = vec3_add(direction, vec3_multiply(camera->right,
		u * scale * aspect_ratio));
	direction = vec3_add(direction, vec3_multiply(camera->up, v * scale));
	return (vec3_normalize(direction));
}
