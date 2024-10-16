/*













*/

#include "../../include/cub3d.h"

int get_real_line(char *line)
{
    int len = ft_strlen(line);

    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
        len--;
    return (len);
}
// Fonction pour mettre la taille de la map dans t_map
void calculate_map_dimensions(t_map *map)
{
    int height;
    int max_width;
    int current_width;

    height = 0;
    max_width = 0;
    current_width = 0;

    while (map->map_array[height] != NULL)
    {
        current_width = ft_strlen(map->map_array[height]);
        if (current_width > max_width)
            max_width = current_width;
        height++;
    }

    map->height = height;
    map->width = max_width;
}

// Fonction qui dessine les tres vertical de la grille 
void draw_vertical_line(t_data *data, int x, int y_start, int length)
{
	int y;

	y = 0;
	while (y < length)
	{
		mlx_pixel_put(data->mlx, data->win, x, y_start + y, NOIR);
		y++;
	}
}

// Fonction qui dessine les tres horizontal de la grille 
void draw_horizontal_line(t_data *data, int x_start, int y, int length)
{
	int x;

	x = 0;
	while (x < length)
	{
		mlx_pixel_put(data->mlx, data->win, x_start + x, y, NOIR);
		x++;
	}
}
