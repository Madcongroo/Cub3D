/*













*/

#include "../../include/cub3d.h"

void my_pixel_put(t_data *data, int x, int y, int color)
{
    // Vérifier que les coordonnées sont dans les limites de l'image
    if (x < 0 || x >= data->win_width || y < 0 || y >= data->win_height)
    {
        return; // Ne rien faire si les coordonnées sont hors limites
    }

    // Calculer l'adresse du pixel
    char *dst = data->address + (y * data->line_len + x * (data->bits_p_pix / 8));
    
    // Écrire la couleur à l'adresse calculée
    *(unsigned int *)(dst) = color;
}


void	loop_square_size(t_data *data, int x, int y, int color)
{
	int	j;
	int	i;

	j = 0;
	while (j < SQUARE_SIZE)
	{
		i = 0;
		while (i < SQUARE_SIZE)
		{
			my_pixel_put(data, x * SQUARE_SIZE + j, y * SQUARE_SIZE + i, color);
			i++;
		}
		j++;
	}
}

void	map_img_output(t_data *data, char **map, int turn)
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
				if (map[y][x] == '0' || is_player(map[y][x]))
					loop_square_size(data, x, y, WHITE);
			}
			else
			{
				if (map[y][x] == '1')
					loop_square_size(data, x, y, ORANGE);
			}
		}
	}
	//draw_grid(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_msg("Error\nMlx init crashed\n"));
	calculate_map_dimensions(data->map);
	data->win_width = (data->map->width * SQUARE_SIZE + SQUARE_SIZE);
	data->win_height = (data->map->height * SQUARE_SIZE + SQUARE_SIZE);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->player->y_cam = data->player->y;
	data->player->x_cam = data->player->x;
	data->address = mlx_get_data_addr(data->img, &data->bits_p_pix,
			&data->line_len, &data->endian);
	if (!data->win)
		return (error_msg("Error\nMlx win crashed\n"));
	map_img_output(data, data->map->map_array, 1);
	map_img_output(data, data->map->map_array, 0);
	return (0);
}

// Fonction principale de la gestion graphique 2D
int	start_map_2d(t_data *data)
{
	if (init_mlx(data) == -1)
		return (-1);
	initialize_keys(data->keys, 65536);
	if (init_textures(data) == -1)
		{
			free_all(data);
			exit (EXIT_FAILURE);
		}
	games_loop(data);
	return (0);
}
