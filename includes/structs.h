/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:42:03 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 02:42:04 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MATRIX 4

# include "./miniRT_include.h"

typedef struct s_tuple
{
	double					x;
	double					y;
	double					z;
	double					w;
}							t_tuple;

typedef t_tuple				t_point;
typedef t_tuple				t_vector;

typedef struct s_ray
{
	t_point					origin;
	t_vector				direction;
}							t_ray;

typedef struct s_matrix
{
	double					matrix[MATRIX][MATRIX];
	int						size;
}							t_matrix;

typedef struct s_shearing
{
	double					p1;
	double					p2;
}							t_shearing;

typedef struct s_vars
{
	void					*mlx;
	void					*win;
}							t_vars;

typedef struct s_color
{
	double					chan_1;
	double					chan_2;
	double					chan_3;
}							t_color;

typedef struct s_material	t_material;

typedef struct s_hittable
{
	int						id;
	int						type;
	double					radius;
	double					height;
	t_material				*material;
	t_matrix				*transform;
}							t_hittable;

typedef struct s_camera
{
	t_matrix				*transform;
	double					fov;
	double					pixel_size;
	double					half_view;
	double					half_width;
	double					half_height;
}							t_camera;

typedef struct s_light
{
	t_point					position;
	double					brightness;
	t_color					color;
}							t_light;

typedef struct s_ambient
{
	double					brightness;
	t_color					color;
}							t_ambient;

typedef struct s_scene
{
	t_ambient				*ambient;
	t_list					*lights;
	t_list					*objects;
	t_camera				*camera;
}							t_scene;

typedef struct s_intersection
{
	double					t;
	t_hittable				*obj;
}							t_intersection;

typedef struct s_computation
{
	t_hittable				*object;
	t_light					*light;
	t_point					point;
	t_point					over_point;
	t_vector				eye;
	t_vector				normal;
	t_scene					*scene;
	bool					inside;
}							t_computation;

typedef struct s_material
{
	t_color					color;
	t_ambient				*ambient;
	double					diffuse;
	double					specular;
	double					shininess;
}							t_material;
typedef struct s_mlx
{
	void					*mlx;
	void					*mlx_win;
	void					*img;
	char					*addr;
	int						screen_width;
	int						screen_height;
	int						win_width;
	int						win_height;
	int						line_length;
	int						endian;
	int						bpp;
}							t_mlx;

typedef struct s_minirt
{
	t_mlx					*mlx;
	t_scene					*scene;
	unsigned int			pxl_rendered;
}							t_minirt;

#endif
