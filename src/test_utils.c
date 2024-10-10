/*
HEADER










HEADER
*/

#include "cub3d.h"

void	display_array(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}
// Teste temporaire pour afficher ce que la struct map contient
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