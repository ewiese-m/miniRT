/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:00:00 by ewiese-m          #+#    #+#             */
/*   Updated: 2025/06/05 18:18:19 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

char	*trim_whitespace(char *str)
{
	char	*start;
	char	*end;
	char	*trimmed;
	int		len;

	if (!str)
		return (NULL);
	start = str;
	while (*start && ft_isspace(*start))
		start++;
	if (*start == '\0')
		return (safe_strdup(""));
	end = start + ft_strlen(start) - 1;
	while (end > start && ft_isspace(*end))
		end--;
	len = end - start + 1;
	trimmed = safe_malloc(len + 1);
	ft_strncpy(trimmed, start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

bool	is_empty_line(char *line)
{
	if (!line)
		return (true);
	while (*line)
	{
		if (!ft_isspace(*line))
			return (false);
		line++;
	}
	return (true);
}

bool	is_comment_line(char *line)
{
	char	*trimmed;
	bool	result;

	if (!line)
		return (false);
	trimmed = trim_whitespace(line);
	result = (trimmed && trimmed[0] == '#');
	free(trimmed);
	return (result);
}

bool	starts_with(const char *str, const char *prefix)
{
	if (!str || !prefix)
		return (false);
	return (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0);
}

bool	ends_with(const char *str, const char *suffix)
{
	int	str_len;
	int	suffix_len;

	if (!str || !suffix)
		return (false);
	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
		return (false);
	return (ft_strcmp(str + str_len - suffix_len, suffix) == 0);
}

bool	contains_only_digits(const char *str)
{
	if (!str || !*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_valid_number(const char *str)
{
	bool	has_digit;
	bool	has_dot;

	if (!str || !*str)
		return (false);
	has_digit = false;
	has_dot = false;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = true;
		else if (*str == '.' && !has_dot)
			has_dot = true;
		else
			return (false);
		str++;
	}
	return (has_digit);
}

int	count_tokens(char *str, char delimiter)
{
	int		count;
	bool	in_token;

	if (!str)
		return (0);
	count = 0;
	in_token = false;
	while (*str)
	{
		if (*str != delimiter)
		{
			if (!in_token)
			{
				count++;
				in_token = true;
			}
		}
		else
			in_token = false;
		str++;
	}
	return (count);
}

char	**split_by_delimiter(char *str, char delimiter)
{
	char	**tokens;
	int		token_count;
	int		i;
	int		start;
	int		end;

	if (!str)
		return (NULL);
	token_count = count_tokens(str, delimiter);
	tokens = safe_malloc(sizeof(char *) * (token_count + 1));
	i = 0;
	start = 0;
	while (i < token_count)
	{
		while (str[start] && str[start] == delimiter)
			start++;
		end = start;
		while (str[end] && str[end] != delimiter)
			end++;
		tokens[i] = safe_substr(str, start, end - start);
		start = end;
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

char	*join_strings(char **strings, char *separator)
{
	char	*result;
	char	*temp;
	int		i;

	if (!strings || !strings[0])
		return (safe_strdup(""));
	result = safe_strdup(strings[0]);
	i = 1;
	while (strings[i])
	{
		if (separator)
		{
			temp = safe_strjoin(result, separator);
			free(result);
			result = temp;
		}
		temp = safe_strjoin(result, strings[i]);
		free(result);
		result = temp;
		i++;
	}
	return (result);
}

char	*to_lowercase(char *str)
{
	char	*lower;
	int		i;

	if (!str)
		return (NULL);
	lower = safe_strdup(str);
	i = 0;
	while (lower[i])
	{
		lower[i] = ft_tolower(lower[i]);
		i++;
	}
	return (lower);
}

char	*to_uppercase(char *str)
{
	char	*upper;
	int		i;

	if (!str)
		return (NULL);
	upper = safe_strdup(str);
	i = 0;
	while (upper[i])
	{
		upper[i] = ft_toupper(upper[i]);
		i++;
	}
	return (upper);
}

int	find_char(const char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	find_last_char(const char *str, char c)
{
	int	i;
	int	last_pos;

	if (!str)
		return (-1);
	last_pos = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			last_pos = i;
		i++;
	}
	return (last_pos);
}

char	*replace_char(char *str, char old_char, char new_char)
{
	char	*result;
	int		i;

	if (!str)
		return (NULL);
	result = safe_strdup(str);
	i = 0;
	while (result[i])
	{
		if (result[i] == old_char)
			result[i] = new_char;
		i++;
	}
	return (result);
}
