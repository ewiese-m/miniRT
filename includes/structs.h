/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:36:27 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/04 22:40:54 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/libft.h"
# include "constants.h"

/* ************************************************************************** */
/*                              BASIC TYPES                                  */
/* ************************************************************************** */
typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

/* ************************************************************************** */
/*                                SCENE                                      */
/* ************************************************************************** */
typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}				t_ambient;

typedef struct s_camera
{
	t_vec3		position;
	t_vec3		orientation;
	double		fov;
	t_vec3		up;
	t_vec3		right;
	t_vec3		forward;
}				t_camera;

typedef struct s_light
{
	t_vec3		position;
	double		brightness;
	t_color		color;
}				t_light;

/* ************************************************************************** */
/*                               OBJECTS                                     */
/* ************************************************************************** */
typedef struct s_sphere
{
	t_vec3		center;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct s_plane
{
	t_vec3		point;
	t_vec3		normal;
	t_color		color;
}				t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		axis;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct s_object
{
	int			type;
	void		*shape;
}				t_object;

/* ************************************************************************** */
/*                              RAY TRACING                                  */
/* ************************************************************************** */
typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct s_hit
{
	bool		hit;
	double		distance;
	t_vec3		point;
	t_vec3		normal;
	t_color		color;
	t_object	*object;
}				t_hit;

/* ************************************************************************** */
/*                               GRAPHICS                                    */
/* ************************************************************************** */
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
}				t_mlx;

/* ************************************************************************** */
/*                               MAIN SCENE                                  */
/* ************************************************************************** */
typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*objects;
	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
}				t_scene;

#endif
