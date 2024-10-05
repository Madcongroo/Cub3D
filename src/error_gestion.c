/*
HEADER










HEADER
*/

#include "../include/cub3d.h"

static void	free_struct_player(t_player *player)
{

}

static void	free_struct_textures(t_textures *text)
{
	if (text->ce)
		free (text->ce);
	if (text->ce)
		free (text->ea);
	if (text->fl)
		free (text->fl);
	if (text->no)
		free (text->no);
	if (text->so)
		free (text->so);
	if (text->we)
		free (text->we);
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
		ft_free_array(data->map);
		free_struct_player(data->player);
		free_struct_textures(data->text);
	}
	ft_putstr_fd(str, 2);
	return (1);
}
