/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:38:18 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/11 15:46:07 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "constants.h"
# include "errors.h"
# include "structs.h"
# include <math.h>

/* ************************************************************************** */
/*                               INIT FUNCTIONS                              */
/* ************************************************************************** */
t_scene	*init_scene(void);
t_mlx	*init_mlx(void);
void	init_camera(t_camera *camera);

/* ************************************************************************** */
/*                              PARSER FUNCTIONS                             */
/* ************************************************************************** */
t_scene	*parse_scene(char *filename);
bool	parse_line(t_scene *scene, char *line);
bool	parse_ambient(t_scene *scene, char **line);
bool	parse_camera(t_scene *scene, char **line);
bool	parse_light(t_scene *scene, char **line);
bool	parse_sphere(t_scene *scene, char **line);
bool	parse_plane(t_scene *scene, char **line);
bool	parse_cylinder(t_scene *scene, char **line);

/* ************************************************************************** */
/*                             PARSING UTILS                                 */
/* ************************************************************************** */
bool	parse_vector(t_vec3 *vec, char *str);
bool	parse_color(t_color *color, char *str);
double	ft_atof(const char *str);
char	**ft_split_whitespace(char *str);
void	ft_free_split(char **split);

/* ************************************************************************** */
/*                           VALIDATION FUNCTIONS                            */
/* ************************************************************************** */
bool	validate_scene(t_scene *scene);
bool	validate_color(t_color *color);
bool	validate_vector_range(t_vec3 *vec, double min, double max);
bool	validate_range(double value, double min, double max);

/* ************************************************************************** */
/*                            VECTOR OPERATIONS                              */
/* ************************************************************************** */
t_vec3	vec3_new(double x, double y, double z);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_subtract(t_vec3 a, t_vec3 b);
t_vec3	vec3_multiply(t_vec3 v, double scalar);
t_vec3	vec3_divide(t_vec3 v, double scalar);
double	vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
double	vec3_length(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);

/* ************************************************************************** */
/*                              RAY TRACING                                  */
/* ************************************************************************** */
t_ray	create_ray(t_vec3 origin, t_vec3 direction);
t_ray	camera_ray(t_camera *camera, double x, double y, int width, int height);
t_hit	trace_ray(t_scene *scene, t_ray ray);
t_color	calculate_lighting(t_scene *scene, t_hit *hit, t_ray ray);

/* ************************************************************************** */
/*                            INTERSECTIONS                                  */
/* ************************************************************************** */
t_hit	intersect_sphere(t_ray ray, t_sphere *sphere);
t_hit	intersect_plane(t_ray ray, t_plane *plane);
t_hit	intersect_cylinder(t_ray ray, t_cylinder *cylinder);
t_hit	find_closest_hit(t_scene *scene, t_ray ray);

/* ************************************************************************** */
/*                              RENDERING                                    */
/* ************************************************************************** */
void	render_scene(t_scene *scene, t_mlx *mlx);
t_color	ray_color(t_scene *scene, t_ray ray);
int		color_to_int(t_color color);
t_color	int_to_color(int color);

/* ************************************************************************** */
/*                               GRAPHICS                                    */
/* ************************************************************************** */
void	mlx_put_pixel(t_image *img, int x, int y, int color);
void	display_image(t_mlx *mlx, t_image *img);
t_image	*create_image(t_mlx *mlx, int width, int height);

/* ************************************************************************** */
/*                               CLEANUP                                     */
/* ************************************************************************** */
void	cleanup_scene(t_scene *scene);
void	cleanup_mlx(t_mlx *mlx);
void	free_objects(t_list *objects);

/* ************************************************************************** */
/*                             ERROR HANDLING                                */
/* ************************************************************************** */
bool	error_message(char *message);
void	error_exit(char *message);
void	usage_error(void);

#endif
