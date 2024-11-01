/*













*/

#include "../../include/cub3d.h"

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
	mlx_hook(data->win, 2, 1L << 0, handle_keypress_on, data);
	mlx_hook(data->win, 3, 1L << 1, handle_keypress_off, data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, data);
	mlx_loop_hook(data->mlx, render_game, data);
	mlx_loop(data->mlx);
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
