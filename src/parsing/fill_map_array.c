/*












*/
#include "../../include/cub3d.h"

// Fonction pour trouver le début de la carte
int	get_map_start(char **map)
{
	int	i;
	char *trimmed_line;

	i = 0;
	while (map[i])
	{
		trimmed_line = jump_space(map[i]);
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
	char *trimmed_line;

	map_height = 0;
	i = map_start;
	while (map[i])
	{
		trimmed_line = jump_space(map[i]);
		if (!ft_isdigit(trimmed_line[0]))
			break;
		map_height++;
		i++;
	}
	return (map_height);
}


// Fonction pour copier chaque ligne de la map dans map_array
void	copy_map_array(t_data *data, char **map, int map_start, int map_height)
{
	int	i;
	int	j;
	char *trimmed_line;

	data->map->map_array = malloc(sizeof(char *) * (map_height + 1));
	if (!data->map->map_array)
		return ;
	i = map_start;
	j = 0;
	while (map[i])
	{
		trimmed_line = jump_space(map[i]);
		if (!ft_isdigit(trimmed_line[0]))
			break;
		data->map->map_array[j] = ft_strdup(map[i]);
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
