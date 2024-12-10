/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:52:19 by proton            #+#    #+#             */
/*   Updated: 2024/12/10 11:32:27 by proton           ###   ########.fr       */
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
		puts("start y section");
		x = 1;
		while (x < data->mini_map->mini_width)
		{
			puts("start loop x section");
			map_y = (int)data->player->y - 10;
			puts("loop before player x");
			map_x = (int)data->player->x - 13;
			puts("in loop before first check");
			printf("y = %d, x = %d\n", y + map_y, x + map_x);
			if ((y + map_y) < 0 || (x + map_x) < 0)
			{
				puts("in check x_y < 0");
				data->mini_map->color = BLACK;
			}
			else if ((y + map_y) > data->map->height || (x + map_x) > data->map->width)
			{
				puts("in check x_y height, width");
				data->mini_map->color = BLACK;
			}
			else if (data->map->map_array[y + map_y][x + map_x] == '1')
			{
				puts("in check wall");
				data->mini_map->color = BLUE;
			}
			else if (ft_is_whitespace(data->map->map_array[y + map_y][x + map_x]))
			{
				puts("in check whitespace");
				data->mini_map->color = BLACK;
			}
			else if (data->map->map_array[y + map_y][x + map_x] == '0'
				|| is_player(data->map->map_array[y + map_y][x + map_x]))
				{
					puts("in check floor or player");						
				data->mini_map->color = GRAY;
				}
			puts("loop x section before draw map");
			draw_mini_map(data, x, y);
			puts("loop x section after draw map");
			x++;
		}
		puts("end y section");
		y++;
	}
	puts("before draw player");
	draw_player_in_mini_map(data, data->mini_map);
	puts("after draw player");
}
