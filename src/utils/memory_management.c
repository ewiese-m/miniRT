/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:17:18 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		memory_error();
	return (ptr);
}

void	*safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (NULL);
	ptr = ft_calloc(count, size);
	if (!ptr)
		memory_error();
	return (ptr);
}

char	*safe_strdup(const char *s)
{
	char	*dup;

	if (!s)
		return (NULL);
	dup = ft_strdup(s);
	if (!dup)
		memory_error();
	return (dup);
}

void	safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	cleanup_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->objects)
		free_objects(scene->objects);
	free(scene);
}

void	cleanup_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->image)
	{
		if (mlx->image->img && mlx->mlx)
			mlx_destroy_image(mlx->mlx, mlx->image->img);
		free(mlx->image);
	}
	if (mlx->window && mlx->mlx)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	free(mlx);
}

void	cleanup_all(t_scene *scene, t_mlx *mlx)
{
	cleanup_scene(scene);
	cleanup_mlx(mlx);
}

void	*safe_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (safe_malloc(new_size));
	new_ptr = safe_malloc(new_size);
	if (old_size > 0)
	{
		if (old_size < new_size)
			ft_memcpy(new_ptr, ptr, old_size);
		else
			ft_memcpy(new_ptr, ptr, new_size);
	}
	free(ptr);
	return (new_ptr);
}

void	*safe_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst || !src)
		return (NULL);
	return (ft_memcpy(dst, src, n));
}

char	*safe_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = ft_strjoin(s1, s2);
	if (!result)
		memory_error();
	return (result);
}

char	*safe_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	result = ft_substr(s, start, len);
	if (!result)
		memory_error();
	return (result);
}

void	zero_memory(void *ptr, size_t size)
{
	if (ptr && size > 0)
		ft_memset(ptr, 0, size);
}

bool	is_valid_pointer(void *ptr)
{
	return (ptr != NULL);
}

size_t	calculate_array_size(void **array)
{
	size_t	size;

	if (!array)
		return (0);
	size = 0;
	while (array[size])
		size++;
	return (size);
}

void	free_pointer_array(void **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
