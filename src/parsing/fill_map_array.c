/*












*/
#include "../../include/cub3d.h"

// Fonction pour trouver le début de la carte
int	get_map_start(char **map)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (map[i])
	{
		trimmed_line = skip_space(map[i]);
		if (ft_isdigit(trimmed_line[0]))
			return (i);
		i++;
	}
	return (-1);
}

// Fonction pour calculer la hauteur de la carte
int	get_map_height(char **map, int map_start)
{
	int	map_height;
	int	i;

	map_height = 0;
	i = map_start;
	while (map[i])
	{
		map_height++;
		i++;
	}
	return (map_height);
}

int	get_max_width(char **map, int map_start)
{
	int	i;
	int	j;
	int	width;

	i = map_start;
	width = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (width < j)
			width = j;
		i++;
	}
	return (width);
}

// Fonction pour copier chaque ligne de la map dans map_array
void	copy_map_array(t_data *data, char **map, int map_start, int map_height)
{
	int	i;
	int	j;
	int	width;

	width = get_max_width(map, map_start);
	data->map->map_array = ft_calloc((map_height + 1), sizeof(char *));
	if (!data->map->map_array)
		return ;
	data->map->height = map_height;
	i = map_start;
	j = 0;
	while (j < map_height)
	{
		data->map->map_array[j] = ft_calloc(width + 2, sizeof(char));
		if (!data->map->map_array[j])
			return ;
		data->map->map_array[j] = ft_strncpy(data->map->map_array[j],
				map[i], width + 2);
		if (!data->map->map_array[j])
			return ;
		i++;
		j++;
	}
	data->map->map_array[j] = NULL;
}

// Fonction principale pour remplir map_array
int	fill_map_array(t_data *data, char **map)
{
	int	map_start;
	int	map_height;

	map_start = get_map_start(map);
	if (map_start == -1)
		return (-1);
	map_height = get_map_height(map, map_start);
	copy_map_array(data, map, map_start, map_height);
	return (0);
}
