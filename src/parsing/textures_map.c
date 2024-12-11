/*













*/
#include "../../include/cub3d.h"

// Fonction pour trouver le chemin des textures et 
// les mettre dans la structure t_map
int	texturs_paths_no_so(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
		{
			data->map->no = remove_sup_space(skip_space(map[i] + 3));
			if (!data->map->no)
				return (-1);
		}
		if (ft_strncmp(map[i], "SO", 2) == 0)
		{
			data->map->so = remove_sup_space(skip_space(map[i] + 3));
			if (!data->map->so)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	texturs_paths_we_ea(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "WE", 2) == 0)
		{
			data->map->we = remove_sup_space(skip_space(map[i] + 3));
			if (!data->map->we)
				return (-1);
		}
		if (ft_strncmp(map[i], "EA", 2) == 0)
		{
			data->map->ea = remove_sup_space(skip_space(map[i] + 3));
			if (!data->map->ea)
				return (-1);
		}
		i++;
	}
	return (0);
}

// Fonction pour mettre les valeur rgb du sol a color_floor
int	color_floor(t_data *data, char **map)
{
	int		i;
	char	**rgb_value;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "F ", 2) == 0)
		{
			rgb_value = ft_split(map[i] + 2, ',');
			if (!rgb_value)
				return (-1);
			if (check_rgb_values(rgb_value) == -1)
				return (ft_free_array(rgb_value));
			data->map->floor_color->r = ft_atoi(rgb_value[0]);
			data->map->floor_color->g = ft_atoi(rgb_value[1]);
			data->map->floor_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
	if (check_color_number(data) == -1)
		return (error_msg("Error\nNumber too high or too low\n"));
	return (0);
}

// Fonction pour mettre les valeur rgb du sol a ceiling_floor
int	color_ceiling(t_data *data, char **map)
{
	int		i;
	char	**rgb_value;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "C ", 2) == 0)
		{
			rgb_value = ft_split(map[i] + 2, ',');
			if (!rgb_value)
				return (-1);
			if (check_rgb_values(rgb_value) == -1)
				return (ft_free_array(rgb_value));
			data->map->ceilling_color->r = ft_atoi(rgb_value[0]);
			data->map->ceilling_color->g = ft_atoi(rgb_value[1]);
			data->map->ceilling_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
	if (check_color_number(data) == -1)
		return (error_msg("Error\nNumber too high or too low\n"));
	return (0);
}

/* fonction principal pour appeler les fonctions
qui remplisse la structure map */
int	parse_all(t_data *data, char **map)
{
	if (texturs_paths_no_so(data, map) != 0)
		return (-1);
	if (texturs_paths_we_ea(data, map) != 0)
		return (-1);
	if (color_floor(data, map) == -1)
		return (-1);
	if (color_ceiling(data, map) == -1)
		return (-1);
	if (fill_map_array(data, map) != 0)
		return (-1);
	return (0);
}
