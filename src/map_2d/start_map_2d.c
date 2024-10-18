/*













*/

#include "../../include/cub3d.h"

void	test_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->add + (y * data->line_length + x * (data->bits_p_pixels / 8));
	*(unsigned int *)dst = color;
}

void	loop_tilesize(t_data *data, int x, int y, int color)
{
	int	i;
	int	saved_x;
	int	saved_y;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		test_pixel(data, x * SQUARE_SIZE + i, y * SQUARE_SIZE, color);
		test_pixel(data, x * SQUARE_SIZE, y * SQUARE_SIZE + i, color);
		i++;
	}
	saved_x = x * SQUARE_SIZE + i;
	saved_y = y * SQUARE_SIZE + i;
	while (i > 0)
	{
		test_pixel(data, saved_x - i, saved_y, color);
		test_pixel(data, saved_x, saved_y - i, color);
		test_pixel(data, saved_x - i, saved_y - i, color);
		i--;
	}
}

void	test_img_output(t_data *data, char **map, int turn)
{
	int	y;
	int	x;

	y = -1;
	x = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (turn == 1)
			{
				if (map[y][x] == '0')
					loop_tilesize(data, x, y, WHITE);
			}
			else
			{
				if (map[y][x] == '1')
						loop_tilesize(data, x, y, ORANGE);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
}

// Fonction principale de la gestion graphique 2D
int	start_map_2d(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_msg("Error\nMlx init crashed\n"));
    calculate_map_dimensions(data->map);
	data->win_width = (data->map->width * SQUARE_SIZE);
	data->win_height = (data->map->height * SQUARE_SIZE);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->player->m_y = data->player->y;
	data->player->m_x = data->player->x;
	data->add = mlx_get_data_addr(data->img, &data->bits_p_pixels, &data->line_length,
		&data->endian);
	if (!data->win)
		return (error_msg("Error\nMlx win crashed\n"));
	// draw_grid(data, data->map);
	// games_loop(data);
	test_img_output(data, data->map->map_array, 1);
	test_img_output(data, data->map->map_array, 0);
	mlx_loop(data->mlx);
	return (0);
}
