/*













*/

#include "../../include/cub3d.h"

void	init_mini_map(t_data *data, t_mini_map *mini_map)
{
	int	largeur_mini_map;

	mini_map->mini_size = 10;
	largeur_mini_map = mini_map->mini_size * data->map->width;
	mini_map->offset_x = data->win_width - largeur_mini_map - 10;
	mini_map->offset_y = 10;
	mini_map->color = GRAY;
	mini_map->player_x = 0;
	mini_map->player_y = 0;
}

void	draw_mini_map(t_data *data, int x, int y)
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
			my_pixel_put(data,
					data->mini_map->offset_x + x * data->mini_map->mini_size
					+ i,
					data->mini_map->offset_y + y * data->mini_map->mini_size
					+ j,
					color);
			j++;
		}
		i++;
	}
}

void	draw_player_in_mini_map(t_data *data)
{
	int	mini_player_x;
	int	mini_player_y;
	int	size;
	int	i;
	int	j;

	mini_player_x = data->mini_map->offset_x + (int)(data->player->x *
					data->mini_map->mini_size);
	mini_player_y = data->mini_map->offset_y + (int)(data->player->y *
					data->mini_map->mini_size);
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

	init_mini_map(data, data->mini_map);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map_array[y][x] == '1')
				data->mini_map->color = BLUE;
			else if (data->map->map_array[y][x] == '0')
				data->mini_map->color = GRAY;
			draw_mini_map(data, x, y);
			x++;
		}
		y++;
	}
	draw_player_in_mini_map(data);
}
