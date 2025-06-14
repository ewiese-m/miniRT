/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:40:18 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/14 03:48:33 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define EPSILON 0.00001
# define WIDHT 250
# define HEIGHT 250

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

# define ERROR_MALLOC "Memory allocation error"
# define ERROR_NOT_ENOUGH_ARGS "Not enough arguments"
# define ERROR_WRONG_ARGS_NB "Wrong args numbers"
# define ERROR_PARSING_ROTATION "Parsing rotation error!"
# define ERROR_PARSING_CENTER "Parsing center error!"
# define ERROR_PARSING_COLOR "Parsing color error!"
# define ERROR_PARSING_PLANE "Parsing plane error!"
# define ERROR_PARSING_SPHERE "Parsing sphere error!"
# define ERROR_PARSING_CYLINDER "Parsing cylinder error!"
# define ERROR_PARSING_LIGHT "Parsing light error!"
# define ERROR_PARSING_AMBIENT "Parsing ambient error!"
# define ERROR_PARSING_CAMERA "Parsing camera error!"
# define ERROR_PARSING_POINT "Parsing point error!"
# define ERROR_PARSING_VECTOR "Parsing vector error!"
# define ERROR_ORIENTATION_NORMALIZED "Orientation error not normalized."
# define ERROR_CAMERA_ALREADY_DEFINED "Only one camera can be defined"
# define ERROR_AMBIENT_ALREADY_DEFINED "Only one ambient light can be defined"
# define ERROR_LIGHT_ALREADY_DEFINED "Only one light can be defined"
# define ERROR_VECTOR_NORMALIZED "Vector not normalized"
# define ERROR_CAMERA_NOT_DEFINED "No camera defined"
# define ERROR_AMBIENT_NOT_DEFINED "No ambient light defined"
# define ERROR_OBJECT_NOT_DEFINED "No object defined"
# define ERROR_LIGHT_NOT_DEFINED "No light defined"
# define ERROR_PARSING_FILE "Error while parsing file"
# define ERROR_CAMERA_FOV "Camera FOV must be between 0 and 180"

#endif
