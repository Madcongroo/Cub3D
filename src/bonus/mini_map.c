/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:52:19 by proton            #+#    #+#             */
/*   Updated: 2024/12/10 13:54:19 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../include/cub3d.h"

static void	init_mini_map(t_data *data, t_mini_map *mini_map)
{
	// int	largeur_mini_map;
	(void)data;

	mini_map->mini_size = 10;
	mini_map->mini_width = 27;
	mini_map->mini_height = 21;
	mini_map->offset_x = 1;
	mini_map->offset_y = 1;
	mini_map->color = GRAY;
	mini_map->player_x = 0;
	mini_map->player_y = 0;
}

static void	draw_mini_map(t_data *data, int x, int y)
{
	int	i;
	int	j;
	int	color;

	color = data->mini_map->color;
	i = 0;
	while (i < data->mini_map->mini_size)
	{
		j = 0;
		while (j < data->mini_map->mini_size)
		{
			my_pixel_put(data, x * data->mini_map->mini_size + i,
				y * data->mini_map->mini_size + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_player_in_mini_map(t_data *data, t_mini_map *mini_map)
{
	int	mini_player_x;
	int	mini_player_y;
	int	size;
	int	i;
	int	j;

	mini_player_x = mini_map->mini_width * data->mini_map->mini_size / 2;
	mini_player_y = mini_map->mini_height * data->mini_map->mini_size / 2;
	size = 8;
	i = -size / 2;
	while (i <= size / 2)
	{
		j = -size / 2;
		while (j <= size / 2)
		{
			my_pixel_put(data, mini_player_x + i, mini_player_y + j, RED);
			j++;
		}
		i++;
	}
}

void	mini_map(t_data *data)
{
	int	y;
	int	x;
	int	map_y;
	int	map_x;

	init_mini_map(data, data->mini_map);
	y = 1;
	while (y < data->mini_map->mini_height)
	{
		x = 1;
		while (x < data->mini_map->mini_width)
		{
			map_y = (int)data->player->y - 10;
			map_x = (int)data->player->x - 13;
			if ((y + map_y) < 0 || (x + map_x) < 0)
				data->mini_map->color = BLACK;
			else if ((y + map_y) > data->map->height - 1 || (x + map_x) > data->map->width)
				data->mini_map->color = BLACK;
			else if (data->map->map_array[y + map_y][x + map_x] == '1')
				data->mini_map->color = BLUE;
			else if (ft_is_whitespace(data->map->map_array[y + map_y][x + map_x]))
				data->mini_map->color = BLACK;
			else if (data->map->map_array[y + map_y][x + map_x] == '0'
				|| is_player(data->map->map_array[y + map_y][x + map_x]))
				data->mini_map->color = GRAY;
			draw_mini_map(data, x, y);
			x++;
		}
		y++;
	}
	draw_player_in_mini_map(data, data->mini_map);
}
