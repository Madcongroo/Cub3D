/*













*/

#include "../../include/cub3d.h"

// Fonction principale de la gestion graphique 2D
int	start_map_2d(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (-1);
	data->win_width = 2176;
	data->win_height = 896;
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3D");
	if (!data->win)
		return (-1);
	calculate_map_dimensions(data->map);
	draw_grid(data, data->map);
	games_loop(data);
	return (0);
}
