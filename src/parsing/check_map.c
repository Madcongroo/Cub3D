/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:16:39 by proton            #+#    #+#             */
/*   Updated: 2024/10/16 14:25:56 by bproton          ###   ########.fr       */
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

// static int	is_map_closed(char **map, int y, int x)
// {
// 	if (map[y + 1][x])
// 	{
// 		if (ft_is_whitespace(map[y][x]) && map[y + 1][x] == '0')
// 			return (-1);
// 	}
// 	else if (map[y - 1][x])
// 	{
// 		if (ft_is_whitespace(map[y][x]) && map[y - 1][x] == '0')
// 			return (-1);
// 	}
// 	else if (map[y][x + 1])
// 	{
// 		if (ft_is_whitespace(map[y][x]) && map[y][x + 1] == '0')
// 			return (-1);
// 	}
// 	else if (map[y][x - 1])
// 	{
// 		if (ft_is_whitespace(map[y][x]) && map[y][x - 1] == '0')
// 			return (-1);
// 	}
// 	return (0);
// }

// int	check_cond(t_data *data, int y, int x)
// {
// 	if (y < 0 || x < 0 || y >= data->map->height || x >= data->map->width
// 		|| !data->map->map_array[y] || !data->map->map_array[y][x])
// 			return (1);
// 	return (0);
// }

// /*searches if the pos y +/-, x +/- is outside of the map or a whitespace*/
// /*cherche si les positions y +/-, x +/- est en dehors de la map ou un caracetere blanc*/
// static int search_if_outside(char **map, int y, int x)
// {
// 	if (map[y] && map[y][x])
// 	{
// 		if (!map[y + 1] || !map[y][x - 1] || !map[y - 1] || !map[y][x + 1])
// 			return (1);
// 		else if (ft_is_whitespace(map[y][x + 1]) || ft_is_whitespace(map[y][x - 1])
// 			|| ft_is_whitespace(map[y + 1][x]) || ft_is_whitespace(map[y -1][x]))
// 				return (1);
// 	}
// 	return (0);
// }


// static int recursive_search(char **map, int y, int x, t_data *data)
// {
// 	printf("Checking (%d, %d)\n", y, x);
// 	if (search_if_outside(map, y, x))
// 	{
// 		if (map[y][x] == '0' || !map[y][x])
// 		{
// 			puts("is in return");
// 			return (-1);
// 		}
// 	}
// 	else if (!check_cond(data, y, x) && map[y][x] != '1')
// 	{
// 		map[y][x] = '1';
// 		if (recursive_search(map, y + 1, x, data) == -1)
// 			return (-1);
// 		if (recursive_search(map, y, x - 1, data) == -1)
// 			return (-1);
// 		if (recursive_search(map, y - 1, x, data) == -1)
// 			return (-1);
// 		if (recursive_search(map, y, x + 1, data) == -1)
// 			return (-1);
// 	}
// 	return (0);
// }

// char **copy_the_map(char **map)
// {
// 	int i;
// 	char **map_cpy;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	map_cpy = (char **)malloc(sizeof(char *) * (i + 1));
// 	if (!map_cpy)
// 		return (NULL);
// 	i = -1;
// 	while (map[++i])
// 	{
// 		map_cpy[i] = ft_strdup(map[i]);
// 		if (!map_cpy[i])
// 		{
// 			ft_free_array(map_cpy);
// 			return (NULL);
// 		}
// 	}
// 	map_cpy[i] = NULL;
// 	return (map_cpy);
// }
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
				return (-1);
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
		return (-1);
	return (0);
}
