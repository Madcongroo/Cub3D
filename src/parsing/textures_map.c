/*













*/
#include "../../include/cub3d.h"

// Fonction pour trouver le chemin des textures et 
// les mettre dans la structure t_map
void	texturs_paths(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			data->map->no = ft_strdup(map[i] + 3);
		if (ft_strncmp(map[i], "LO ", 3) == 0)
			data->map->so = ft_strdup(map[i] + 3);
		if (ft_strncmp(map[i], "WE ", 3) == 0)
			data->map->we = ft_strdup(map[i] + 3);
		if (ft_strncmp(map[i], "EA ", 3) == 0)
			data->map->ea = ft_strdup(map[i] + 3);
		i++;
	}
}

// Fonction pour mettre les valeur rgb du sol a color_floor
void	color_floor(t_data *data, char **map)
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
				return ;
			data->map->floor_color->r = ft_atoi(rgb_value[0]);
			data->map->floor_color->g = ft_atoi(rgb_value[1]);
			data->map->floor_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
}

// Fonction pour mettre les valeur rgb du sol a ceiling_floor
void	color_ceiling(t_data *data, char **map)
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
				return ;
			data->map->ceilling_color->r = ft_atoi(rgb_value[0]);
			data->map->ceilling_color->g = ft_atoi(rgb_value[1]);
			data->map->ceilling_color->b = ft_atoi(rgb_value[2]);
			ft_free_array(rgb_value);
		}
		i++;
	}
}
