/*













*/

#include "../../include/cub3d.h"

void	draw_grid(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x <= data->map->width)
	{
		y = 0;
		while (y <= data->map->height)
		{
			//draw_vertical_line(data, x, y, SQUARE_SIZE);
			y++;
		}
		x++;
	}
	y = 0;
	while (y <= data->map->height)
	{
		x = 0;
		while (x <= data->map->width)
		{
			//draw_horizontal_line(data, x, y, SQUARE_SIZE);
			x++;
		}
		y++;
	}
}

// Fonction qui dessine les tres vertical de la grille 
void	draw_vertical_line(t_data *data, int x, int y, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		my_pixel_put(data, x * SQUARE_SIZE, y * SQUARE_SIZE + i, BLACK);
		i++;
	}
}

// Fonction qui dessine les tres horizontal de la grille 
void	draw_horizontal_line(t_data *data, int x, int y, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		my_pixel_put(data, x * SQUARE_SIZE + i, y * SQUARE_SIZE, BLACK);
		i++;
	}
}
