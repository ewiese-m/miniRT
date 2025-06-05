/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:18:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	error_message(char *message)
{
	if (message)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (false);
}

void	error_exit(char *message)
{
	if (message)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

void	usage_error(void)
{
	ft_putstr_fd(MSG_USAGE, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ERR_USAGE);
}

void	file_error(char *filename)
{
	ft_putstr_fd("Error: Could not open file '", STDERR_FILENO);
	if (filename)
		ft_putstr_fd(filename, STDERR_FILENO);
	else
		ft_putstr_fd("(null)", STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	exit(ERR_FILE);
}

void	parse_error(char *line, int line_num)
{
	ft_putstr_fd("Parse Error", STDERR_FILENO);
	if (line_num > 0)
	{
		ft_putstr_fd(" at line ", STDERR_FILENO);
		ft_putnbr_fd(line_num, STDERR_FILENO);
	}
	if (line)
	{
		ft_putstr_fd(": '", STDERR_FILENO);
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd("'", STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ERR_PARSE);
}

void	memory_error(void)
{
	ft_putstr_fd(MSG_MEMORY_ERROR, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ERR_MEMORY);
}

void	mlx_error(void)
{
	ft_putstr_fd(MSG_MLX_ERROR, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(ERR_MLX);
}

void	warning_message(char *message)
{
	if (message)
	{
		ft_putstr_fd("Warning: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}

void	debug_message(char *message)
{
#ifdef DEBUG
	if (message)
	{
		ft_putstr_fd("Debug: ", STDOUT_FILENO);
		ft_putstr_fd(message, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
#else
	(void)message;
#endif
}

void	print_error_details(int error_code)
{
	ft_putstr_fd("Error Code: ", STDERR_FILENO);
	ft_putnbr_fd(error_code, STDERR_FILENO);
	ft_putstr_fd(" - ", STDERR_FILENO);
	if (error_code == ERR_SUCCESS)
		ft_putstr_fd("Success", STDERR_FILENO);
	else if (error_code == ERR_USAGE)
		ft_putstr_fd("Usage error", STDERR_FILENO);
	else if (error_code == ERR_FILE)
		ft_putstr_fd("File error", STDERR_FILENO);
	else if (error_code == ERR_PARSE)
		ft_putstr_fd("Parse error", STDERR_FILENO);
	else if (error_code == ERR_MEMORY)
		ft_putstr_fd("Memory error", STDERR_FILENO);
	else if (error_code == ERR_MLX)
		ft_putstr_fd("MLX error", STDERR_FILENO);
	else
		ft_putstr_fd("Unknown error", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

bool	validate_file_extension(char *filename, char *extension)
{
	int	filename_len;
	int	ext_len;

	if (!filename || !extension)
		return (false);
	filename_len = ft_strlen(filename);
	ext_len = ft_strlen(extension);
	if (filename_len < ext_len)
		return (false);
	return (ft_strcmp(filename + filename_len - ext_len, extension) == 0);
}

void	assert_condition(bool condition, char *message)
{
	if (!condition)
	{
		if (message)
			error_exit(message);
		else
			error_exit("Assertion failed");
	}
}
