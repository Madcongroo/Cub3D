/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:16:39 by proton            #+#    #+#             */
/*   Updated: 2024/12/06 13:55:17 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_edge_cases(t_data *data, char **map, int y, int x)
{
	if (y == 0 || y == data->map->height - 1 || x == 0
		|| x == data->map->width)
		return (1);
	else if (!map[y + 1][x] || !map[y][x - 1] || !map[y - 1][x]
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

/*fonction to check if the map is surrounded by walls
	each time the pos is '0', checks all pos + 1/ -1.
		if the pos +/- is a whitespace or nothing returns -1*/
/*fonction qui cherche un '0', regarded si pos + 1/-1
	si la pos +/- est un whitespace ou rien retourn -1*/
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
			if (is_player(map[i][j]))
				set_direction(data, map[i][j]);
		}
	}
	return (0);
}

static int	return_for_norm(t_data *data, char **map)
{
	if (!data->player->y && !data->player->x)
		return (error_msg("Error\nPlayer not found\n"));
	if (is_map_wall_surrounded(data, map) == -1)
		return (error_msg("Error\nMap unclosed\n"));
	return (0);
}

/*loops the map to scan all the infos
	boucle sur la map check toutes les infos*/
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
				if (should_it_be_checked(data, map, i, j))
					return (error_msg("Error\nPlayer outside the map\n"));
				if (data->player->y && data->player->x)
					return (error_msg("Error\nMore than 1 player\n"));
				data->player->y = i + 0.5;
				data->player->x = j + 0.5;
			}
		}
	}
	return (return_for_norm(data, map));
}
