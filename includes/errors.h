/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:37:58 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/04 22:37:59 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/* ************************************************************************** */
/*                               ERROR CODES                                 */
/* ************************************************************************** */
# define ERR_SUCCESS        0
# define ERR_USAGE          1
# define ERR_FILE           2
# define ERR_PARSE          3
# define ERR_MEMORY         4
# define ERR_MLX            5

/* ************************************************************************** */
/*                             ERROR MESSAGES                                */
/* ************************************************************************** */
# define MSG_USAGE          "Usage: ./miniRT <scene.rt>"
# define MSG_FILE_NOT_FOUND "Error: File not found"
# define MSG_FILE_EXTENSION "Error: File must have .rt extension"
# define MSG_PARSE_ERROR    "Error: Invalid scene format"
# define MSG_MEMORY_ERROR   "Error: Memory allocation failed"
# define MSG_MLX_ERROR      "Error: MLX initialization failed"
# define MSG_MISSING_ELEM   "Error: Missing required scene element"
# define MSG_DUPLICATE_ELEM "Error: Duplicate scene element"
# define MSG_INVALID_RANGE  "Error: Value out of valid range"

#endif
