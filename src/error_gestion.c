/*
HEADER










HEADER
*/

#include "../include/cub3d.h"

static void	free_struct_player(t_player *player)
{
	(void)player;
}

static void	free_struct_textures(t_map *map)
{
	if (map->no)
		free (map->no);
	if (map->ea)
		free (map->ea);
	if (map->so)
		free (map->so);
	if (map->we)
		free (map->we);
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
		if (data->map->map_array)
			ft_free_array(data->map->map_array);
		free_struct_player(data->player);
		free_struct_textures(data->text);
	}
	ft_putstr_fd(str, 2);
	return (1);
}
