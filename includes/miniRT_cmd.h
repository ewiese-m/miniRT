/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_cmd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:40:18 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:06:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CMD_H
# define MINIRT_CMD_H

int				args_check(int argc, char **argv, char **envp);

void			data_free(t_renderer *data);
void			free_scene(t_scene *scene);

void			data_initialize(t_renderer *data);

int				event_key(int keycode, void *data);

int				event_resize(t_renderer *data);

void			file_check_ext(char *path);
void			file_check_path(char *path);

void			file_save(t_renderer *data, char *path);

void			mlx_free(t_renderer *data);
void			mlx_exit(t_renderer *data, int status);
void			mlx_error(t_renderer *data);
int				mlx_hook_exit(t_renderer *data);
void			my_mlx_pixel_put(t_mlx_context *data, int x, int y, int color);

void			mlx_initialize_win(t_renderer *data);

void			mlx_hook_loop(t_renderer *data);

int				mlx_render_frame(t_renderer *data);
void			render_scene(t_renderer *data);

void			ft_exit(char *msg, int status);

void			ft_free(char **tab);

void			test_tick(t_renderer *minirt);
void			test_maths(t_renderer *minirt);

// parsing
int				ft_parse_rt_file(t_scene *scene, char *file);
int				ft_parse_sphere(t_scene *scene, char *line);
int				ft_parse_plane(t_scene *scene, char *line);
int				ft_parse_cylinder(t_scene *scene, char *line);
int				ft_parse_camera(t_scene *scene, char *line);
int				ft_parse_light(t_scene *scene, char *line);
int				ft_parse_ambient(t_scene *scene, char *line);
int				ft_parse_color(char *line, t_color *color);
int				ft_parse_translation(char *line, t_matrix *transform);
int				ft_parse_rotation(char *line, t_matrix *transform);
int				ft_parse_scale(double x, double y, double z, t_matrix *matrix);
int				ft_parse_point(char *line, t_point *point);
int				ft_parse_vector(char *line, t_vector *vector);

// inits
t_material		*material_init(void);
t_camera		*ft_init_camera(void);
int				init_minirt(t_renderer *minirt);

// utils
void			ft_print_scene(t_scene *scene);
void			ft_print_matrix(t_matrix matrix);
void			ft_print_point(t_point point);
void			ft_print_vector(t_vector vector);

// intersect
t_intersection	*create_intersect(double t, t_object *obj);
t_list			*ft_intersect(t_list *objects, t_ray ray);
double			*intersect_with_sphere(t_ray ray);
double			*intersect_with_cylinder(t_object *cy, t_ray ray,
					double c, double d);
double			*intersect_with_plane(t_ray ray);
t_intersection	*ft_hit(t_list *intersections);

// lighting
t_color			lighting(t_shading_data	*lighting_info, bool	shadowed);
bool			is_shadowed(t_scene *scene, t_point point);

//free
void			free_intersection(void *content);
void			free_hittable(void *hittable);
void			free_parse_camera(t_camera *camera, char **tab);
void			free_parse_hittable(t_object *hittable, char **tab, int id);
void			free_parse_light(t_light *light, char **tab);
void			free_parse_ambient(t_ambient_light *ambient, char **tab);
void			free_light(void *light);
void			free_ambient(t_ambient_light *ambient);
void			free_camera(t_camera *camera);
void			free_scene(t_scene *scene);

#endif
