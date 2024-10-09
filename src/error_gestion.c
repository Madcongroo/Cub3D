/*
HEADER










HEADER
*/

#include "../include/cub3d.h"

static void	free_struct_player(t_player *player)
{
	(void)player;
}

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
}

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

int	free_all(t_data *data, char *str)
{
	if (data)
	{
		if (data->map)
			free_struct_map(data->map);
		if (data->player)
			free_struct_player(data->player);
	}
	ft_putstr_fd(str, 2);
	return (1);
}

