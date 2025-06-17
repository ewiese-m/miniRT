/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:26:52 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/16 13:58:55 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

t_intersection	*create_intersect(double t, t_object *obj);
t_list			*ft_intersect(t_list *objects, t_ray ray);
double			*sphere_intersect(t_ray ray);
double			*cylinder_intersect(t_object *cy, t_ray ray, double c,
					double d);
double			*plane_intersect(t_ray ray);
t_intersection	*get_closest_hit(t_list *intersections);

#endif
