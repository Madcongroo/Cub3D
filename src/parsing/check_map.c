/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:16:39 by proton            #+#    #+#             */
/*   Updated: 2024/10/16 16:26:22 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	good_char(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0'
		&& c != '1' && !ft_is_whitespace(c))
		return (1);
	return (0);
}

static int	check_edge_cases(t_data *data, char **map, int y, int x)
{
	if (y == 0 || y == data->map->height || x == 0
		|| x == data->map->width)
		return (1);
	else if (!map[y + 1] || !map[y][x - 1] || !map[y - 1]
		|| !map[y][x + 1])
		return (1);
	return (0);
}

int	should_it_be_checked(t_data *data, char **map, int y, int x)
{
	if (check_edge_cases(data, map, y, x) == 1)
		return (1);
	if (map[y][x + 1])
	{
		if (ft_is_whitespace(map[y][x + 1]))
			return (1);
	}
	if (map[y][x - 1])
	{
		if (ft_is_whitespace(map[y][x - 1]))
			return (1);
	}
	if (map[y + 1])
	{
		if (ft_is_whitespace(map[y + 1][x]))
			return (1);
	}
	if (map[y - 1])
	{
		if (ft_is_whitespace(map[y - 1][x]))
			return (1);
	}
	return (0);
}

int	is_map_wall_surrounded(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (should_it_be_checked(data, map, i, j))
					return (-1);
			}
		}
		data->map->width = j;
	}
	return (0);
}

int	check_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (good_char(map[i][j]))
				return (error_msg("Error\nUnknown caracter\n"));
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->player->y = i;
				data->player->x = j;
			}
		}
	}
	if (!data->player->y && !data->player->x)
		return (-1);
	if (is_map_wall_surrounded(data, map) == -1)
		return (error_msg("Error\nMap unclosed\n"));
	return (0);
}
