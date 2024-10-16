/*













*/

#include "../../include/cub3d.h"
// Fonction pour fermer la fenetre
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
    free_all(data);
	exit(0);
}

// Fonction pour afficher la fenetre et gestion des evenement dans une boucle
void	games_loop(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

// Fonction pour dessiner la grille dans la map
void	draw_grid(t_data*data, t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
        while (j < map->width)
        {
            x = j * SQUARE_SIZE;
            y = i * SQUARE_SIZE;

            if (map->map_array[i][j] == '1' || map->map_array[i][j] == '0')
                draw_square(data, x, y, WHITE);
			else if (map->map_array[i][j] == ' ')
                draw_square(data, x, y, BLACK);
			draw_vertical_line(data, x + SQUARE_SIZE - 1, y, SQUARE_SIZE);
			draw_horizontal_line(data, x, y + SQUARE_SIZE - 1, SQUARE_SIZE);
			j++;
		}
		i++;
	}
}

/* Fonction qui recois les differente taille de 
 draw_grid pour dessiner chaque pixel*/
void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			mlx_pixel_put(data->mlx, data->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
