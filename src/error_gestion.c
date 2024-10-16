/*
HEADER










HEADER
*/

#include "../include/cub3d.h"

static void	free_struct_map(t_map *map)
{
	if (map->no)
		free (map->no);
	if (map->ea)
		free (map->ea);
	if (map->so)
		free (map->so);
	if (map->we)
		free (map->we);
	if (map->map_array)
		ft_free_array(map->map_array);
	if (map->ceilling_color)
		free (map->ceilling_color);
	if (map->floor_color)
		free (map->floor_color);
	if (map)
		free (map);
}

int	ft_free_array(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
	return (-1);
}

int	free_all(t_data *data)
{
	if (data)
	{
		if (data->player)
			free (data->player);
		if (data->map)
			free_struct_map(data->map);
		if (data->raycast)
			free (data->raycast);
		if (data->text)
			free (data->text);
		if (data->win)
			free (data->win);
	}
	return (1);
}

