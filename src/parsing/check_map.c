/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:16:39 by proton            #+#    #+#             */
/*   Updated: 2024/10/14 18:09:31 by proton           ###   ########.fr       */
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

static int	is_map_closed(char **map, int y, int x)
{
	if (map[y + 1][x])
	{
		if (ft_is_whitespace(map[y][x]) && map[y + 1][x] == '0')
			return (-1);
	}
	if (map[y - 1][x])
	{
		if (ft_is_whitespace(map[y][x]) && map[y - 1][x] == '0')
			return (-1);
	}
	if (map[y][x + 1])
	{
		if (ft_is_whitespace(map[y][x]) && map[y][x + 1] == '0')
			return (-1);
	}
	if (map[y][x - 1])
	{
		if (ft_is_whitespace(map[y][x]) && map[y][x - 1] == '0')
			return (-1);
	}
	return (0);
}

static int recursive_search(char **map, int y, int x)
{
	if (map[y][x])
	{
		if (is_map_closed(map, y, x) == -1)
			return (-1);
		if (map[y][x] == '0' || map[y][x] == '1')
		{
			if (recursive_search(map, y + 1, x) == -1)
				return (-1);
			if (recursive_search(map, y + 1, x) == -1)
				return (-1);
			if (recursive_search(map, y, x + 1) == -1)
				return (-1);
			if (recursive_search(map, y, x - 1) == -1)
				return (-1);
		}
		return (0);
	}
	return (-1);
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
				return (-1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->player->y = i;
				data->player->x = j;
			}
		}
	}
	if (!data->player->y || !data->player->x)
		return (-1);
	if (recursive_search(map, data->player->y, data->player->x) == -1)
		return (-1);
	return (0);
}
