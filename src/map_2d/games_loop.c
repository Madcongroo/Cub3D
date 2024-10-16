/*













*/
#include "../../include/cub3d.h"
// Fonction pour fermer la fenetre
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

// Fonction pour afficher la fenetre et gestion des evenement dans une boucle
void	games_loop(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

void draw_grid(t_data *data)
{
    int x;
    int y;
    int num_lines;
    int num_columes;
    int colors;
    int i = 0;

    num_columes = 0;
    num_lines = 0;
    colors = 0;
    while (data->map->map_array[num_lines])
        num_lines++;
    y = 0;
    while (y < num_lines)
    {
        num_columes = ft_strlen(data->map->map_array[y]);
        x = 0;
        while (x < num_columes)
        {
            if (data->map->map_array[y][x] == '1' || data->map->map_array[y][x] == '0')
                colors = 0xFFFFFF; // Blanc
            else if (data->map->map_array[y][x] == ' ')
                colors = 0x000000; // Rouge
            i = 0;
            if (x < num_columes - 1)
            {
                if (data->map->map_array[y][x + 1] == ' ')
                    colors = 0x000000;
                else
                    colors = 0xFFFFFF;
            }
            else if (data->map->map_array[y][x] == ' ')
                colors = 0xFFFFFF;
            i = 0;
            while (i < TILE_SIZE)
            {
                mlx_pixel_put(data->mlx, data->win, x * TILE_SIZE + i, y * TILE_SIZE, colors);
                i++;
            }
            if (y < num_lines - 1)
            {
                if (data->map->map_array[y + 1][x] == ' ')
                    colors = 0x000000;
                else
                    colors = 0xFFFFFF;
            }
            else if (data->map->map_array[y][x] == ' ')
                colors = 0xFFFFFF;
            i = 0;
            while (i < TILE_SIZE)
            {
                mlx_pixel_put(data->mlx, data->win, x * TILE_SIZE, y * TILE_SIZE + i, colors);
                i++;
            }
            x++;
        }
        y++;
    }
}
