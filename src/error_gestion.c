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
	free (text->ce);
	free (text->ea);
	free (text->fl);
	free (text->no);
	free (text->so);
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
		free_strcut_player(data->player);
		free_struct_textures(data->text);
	}
	ft_pustr_fd(str, 2);
	return (1);
}
