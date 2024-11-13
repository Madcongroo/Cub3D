/*













*/

#include "../../include/cub3d.h"

int	is_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	get_real_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	return (len);
}

// Fonction pour mettre la taille de la map dans t_map
void	calculate_map_dimensions(t_map *map)
{
	int	height;
	int	max_width;
	int	current_width;

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
	map->width = max_width + 1;
}

// touche presser
int	handle_keypress_on(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		close_window(data);
	}
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = 1;
	return (0);
}

// touche relacher
int	handle_keypress_off(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = 0;
	return (0);
}
