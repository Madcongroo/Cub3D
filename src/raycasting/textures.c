/*












*/

#include "cub3d.h"

int	get_right_pixel(t_data *data, t_texture_type direction, int x, int y)
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;

	if (direction == NORTH)
	{
		addr = mlx_get_data_addr(data->map->textures->no_text,
			&bits_per_pixel, &line_length, &endian);
		color = (y * line_length + x * (bits_per_pixel / 8));
	}
	else if (direction == SOUTH)
	{
		addr = mlx_get_data_addr(data->map->textures->so_text,
			&bits_per_pixel, &line_length, &endian);
		color = (y * line_length + x * (bits_per_pixel / 8));
	}
	else if (direction == EAST)
	{
		addr = mlx_get_data_addr(data->map->textures->ea_text,
			&bits_per_pixel, &line_length, &endian);
		color = (y * line_length + x * (bits_per_pixel / 8));
	}
	else
	{
		addr = mlx_get_data_addr(data->map->textures->we_text,
			&bits_per_pixel, &line_length, &endian);
		color = (y * line_length + x * (bits_per_pixel / 8));
	}
	return *(int *)(addr + color);
}

int	init_textures(t_data *data)
{
	int	height;
	int	width;

	data->map->textures->no_text = mlx_xpm_file_to_image(data->mlx, data->map->no, &width, &height);
	if (!data->map->textures->no_text)
		return (-1);
	data->map->textures->so_text = mlx_xpm_file_to_image(data->mlx, data->map->so, &width, &height);
	if (!data->map->textures->so_text)
		return (-1);
	data->map->textures->ea_text = mlx_xpm_file_to_image(data->mlx, data->map->ea, &width, &height);
	if (!data->map->textures->ea_text)
		return (-1);
	data->map->textures->we_text = mlx_xpm_file_to_image(data->mlx, data->map->we, &width, &height);
	if (!data->map->textures->we_text)
		return (-1);
	return (0);
}
