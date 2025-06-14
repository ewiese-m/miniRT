/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:48:54 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:02:00 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

/* -- */

bool		double_equal(double nb1, double nb2);
bool		double_inf(double nb1, double nb2);
bool		double_sup(double nb1, double nb2);

/* -- */

double		matrix_cofactor(t_matrix m, int row, int col);

bool		matrix_compare(t_matrix m1, t_matrix m2);

t_matrix	*matrix_new(double **m, int size);
t_matrix	*matrix_identity(void);
t_matrix	*vector_to_matrix(t_vector v);

double		matrix_determinant(t_matrix m);

t_matrix	matrix_inverse(t_matrix m);

double		matrix_minor(t_matrix m, int row, int col);

t_matrix	*matrix_mult(t_matrix m1, t_matrix m2);
t_tuple		matrix_tuple_mult(t_matrix m, t_tuple t);

t_matrix	*matrix_rotation_x(double angle);
t_matrix	*matrix_rotation_y(double angle);
t_matrix	*matrix_rotation_z(double angle);
void		matrix_rotation(t_matrix *transform, t_vector vector);

t_matrix	*matrix_scale(double x, double y, double z);

t_matrix	matrix_submatrix(t_matrix m, int row, int col);

void		matrix_transform(t_matrix *matrix, t_matrix *transform);

t_matrix	*matrix_translation(double x, double y, double z);

t_matrix	matrix_transpose(t_matrix m);

/* -- */

t_ray		ray_new(t_point origin, t_vector direction);
t_ray		ray_transform(t_ray ray, t_matrix m);

t_point		ray_position(t_ray ray, double t);

/* -- */

t_matrix	*matrix_shearing(t_shearing x, t_shearing y, t_shearing z);

/* -- */

t_tuple		tuple_new(double x, double y, double z, double w);
t_tuple		point_new(double x, double y, double z);
t_tuple		vector_new(double x, double y, double z);

bool		tuple_equal(t_tuple t1, t_tuple t2);
bool		tuple_inf(t_tuple t1, t_tuple t2);
bool		tuple_sup(t_tuple t1, t_tuple t2);

t_tuple		tuple_add(t_tuple t1, t_tuple t2);
t_tuple		tuple_sub(t_tuple t1, t_tuple t2);
t_tuple		tuple_mult(t_tuple t1, double nb);
t_tuple		tuple_div(t_tuple t1, t_tuple t2);
t_tuple		tuple_negate(t_tuple t1);

double		tuple_mag(t_tuple t1);
t_tuple		tuple_norm(t_tuple t1);
double		tuple_dot(t_tuple t1, t_tuple t2);
t_tuple		tuple_cross(t_tuple t1, t_tuple t2);
t_tuple		tuple_reflect(t_tuple t, t_tuple normal);

t_tuple		tuple_transform(t_tuple tuple, t_matrix matrix);

t_point		ft_point_at(t_ray ray, double t);

t_vector	normal_at(t_object *obj, t_point world_point);
t_vector	reflect(t_vector in, t_vector normal);

#endif
