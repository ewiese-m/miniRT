/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 07:08:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static t_color	get_background_color(void)
{
	t_color	bg;

	bg.r = 0;
	bg.g = 0;
	bg.b = 0;
	return (bg);
}

t_color	ray_color(t_scene *scene, t_ray ray)
{
	t_hit	hit;
	t_color	color;

	hit = find_closest_hit(scene, ray);
	if (!hit.hit)
		return (get_background_color());
	color = calculate_lighting(scene, &hit, ray);
	return (color);
}

static void	render_pixel(t_scene *scene, t_mlx *mlx, int x, int y)
{
	t_ray	ray;
	t_color	color;
	int		pixel_color;

	ray = camera_ray(&scene->camera, x, y, WINDOW_WIDTH, WINDOW_HEIGHT);
	color = ray_color(scene, ray);
	pixel_color = color_to_int(color);
	put_pixel_to_image(mlx->image, x, y, pixel_color);
}

void	render_scene(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;
	int	progress;
	int	last_progress;

	if (!scene || !mlx || !mlx->image)
		return ;
	last_progress = -1;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			render_pixel(scene, mlx, x, y);
			x++;
		}
		progress = (y * 100) / WINDOW_HEIGHT;
		if (progress != last_progress && progress % 10 == 0)
		{
			ft_putstr_fd("Rendering: ", 1);
			ft_putnbr_fd(progress, 1);
			ft_putstr_fd("%\r", 1);
			last_progress = progress;
		}
		y++;
	}
	ft_putstr_fd("Rendering: 100%\n", 1);
}
