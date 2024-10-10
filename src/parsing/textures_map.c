//













//
#include "../../include/cub3d.h"

// Fonction pour trouver le chemin des textures et les mettre dans la structure t_map
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
void color_floor(t_data *data, char **map)
{
	int	i;
	char **rgb_value;

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
void color_ceiling(t_data *data, char **map)
{
	int i;
	char **rgb_value;

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
void fill_map_array(t_data *data, char **map)
{
	int	i;
	int	map_height;
	int	map_start;
	int	j;

	i = 0;
	map_start = -1;
	while (map[i])
	{
		if (ft_isdigit(map[i][0]))
		{
			map_start = i;
			break;
		}
		i++;
	}
	if (map_start == -1)
	{
		free_all(data, "Error\nreading map\n");
		return ;
	}
	map_height = 0;
	i = map_start;
	while(map[i] && ft_isdigit(map[i][0]))
	{
		map_height++;
		i++;
	}
	data->map->map_array = malloc(sizeof(char *) * (map_height + 1));
	if (!data->map->map_array)
		return ;
	i = map_start;
	j = 0;
	while (map[i] && ft_isdigit(map[i][0]))
	{
		data->map->map_array[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	data->map->map_array[j] = NULL;
}
void	print_map_info(t_map *map)
{
	// Affichage des textures
	printf("North Texture Path: %s\n", map->no ? map->no : "Not set");
	printf("South Texture Path: %s\n", map->so ? map->so : "Not set");
	printf("West Texture Path: %s\n", map->we ? map->we : "Not set");
	printf("East Texture Path: %s\n", map->ea ? map->ea : "Not set");

	// Affichage des couleurs du sol
	printf("Floor Color: R=%d, G=%d, B=%d\n", 
		map->floor_color->r, 
		map->floor_color->g, 
		map->floor_color->b);

	printf("Ceiling color: R=%d, G=%d, B=%d\n", map->ceilling_color->r, map->ceilling_color->g, map->ceilling_color->b);
	// Affichage de la carte (map_array)
	if (map->map_array)
	{
		printf("Map:\n");
		for (int i = 0; map->map_array[i]; i++)
		{
			printf("%s\n", map->map_array[i]);
		}
	}
	else
	{
		printf("Map not set\n");
	}
}
