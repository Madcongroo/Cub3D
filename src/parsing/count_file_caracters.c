/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file_caracters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:41:24 by proton            #+#    #+#             */
/*   Updated: 2024/12/11 15:50:01 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_file_chars(char *file)
{
	int		fd;
	int		len;
	int		check;
	char	*line;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	check = 1;
	while (check != 0)
	{
		line = get_next_line(fd);
		if (!line)
			check = 0;
		if (line)
			len += ft_strlen(line);
		if (line)
			free (line);
	}
	close (fd);
	return (len);
}

size_t	find_end(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && ft_isinset(s[i - 1], set))
		i--;
	return (i);
}

int	check_rgb_trimmed(char *value)
{
	size_t	start;
	size_t	end;

	start = ft_findstart(value, " \t");
	end = find_end(value, " \t");
	while (start < end)
	{
		if (ft_is_whitespace(value[start]))
			return (error_msg("Error\nCeilling or floor error\n"));
		start++;
	}
	return (0);
}

int	check_rgb_values(char **values)
{
	int		i;

	i = 0;
	while (values[i])
	{
		if (check_rgb_trimmed(values[i]) == -1)
			return (-1);
		i++;
	}
	if (i != 3)
		return (error_msg("Error\nCeilling or floor error\n"));
	return (0);
}
