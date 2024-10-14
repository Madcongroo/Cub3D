/*













*/
#include "../../include/cub3d.h"

/* fonction principal pour appeler les fonctions
qui remplisse la structure map */
int	pase_all(t_data *data, char **map)
{
	if (texturs_paths_no_so(data, map) != 0)
		return (-1);
	if (texturs_paths_we_ea(data, map) != 0)
		return (-1);
	color_floor(data, map);
	color_ceiling(data, map);
	if (fill_map_array(data, map) != 0)
		return (-1);
	print_map_info(data->map);
	return (0);
}

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
void	color_floor(t_data *data, char **map)
{
	int		i;
	char	**rgb_value;
	int		check_colors;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "F ", 2) == 0)
		{
			rgb_value = ft_split(map[i] + 2, ',');
			if (!rgb_value)
				return ;
			data->map->floor_color->r = ft_atoi(rgb_value[0]);
			data->map->floor_color->g = ft_atoi(rgb_value[1]);
			data->map->floor_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
	if ((check_colors = check_color_number(data)) != 0)
		return ;
}

// Fonction pour mettre les valeur rgb du sol a ceiling_floor
void	color_ceiling(t_data *data, char **map)
{
	int		i;
	char	**rgb_value;
	int		check_colors;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "C ", 2) == 0)
		{
			rgb_value = ft_split(map[i] + 2, ',');
			if (!rgb_value)
				return ;
			data->map->ceilling_color->r = ft_atoi(rgb_value[0]);
			data->map->ceilling_color->g = ft_atoi(rgb_value[1]);
			data->map->ceilling_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
	if ((check_colors = check_color_number(data)) != 0)
		return ;

}
/* Fonction qui check les chiffre recu depuis le fichier*/
int	check_color_number(t_data *data)
{
	if (data->map->floor_color->r < 0 || data->map->floor_color->r > 255
		|| data->map->floor_color->g < 0 || data->map->floor_color->g > 255
		|| data->map->floor_color->b < 0 || data->map->floor_color->b > 255)
		return (-1);
	if (data->map->ceilling_color->r < 0 || data->map->ceilling_color->r > 255
		|| data->map->ceilling_color->g < 0 || data->map->ceilling_color->g > 255
		|| data->map->ceilling_color->b < 0 || data->map->ceilling_color->b > 255)
		return (-1);
	return (0);
}

