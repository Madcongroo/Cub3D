/*












*/

#include "cub3d.h"

int	get_right_pixel(t_data *data, void *xpm_img)
{
	char	*addr;

	addr = mlx_get_data_addr(xpm_img, )
}

char	*get_texture_addr(t_data *data, void *xpm_img)
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


}

int	init_textures(t_data *data, t_textures *text)
{
	data->map->textures->no_text = mlx_xpm_file_to_image(data->mlx, data->map->no, 64, 64);
	if (!data->map->textures->no_text)
		return (-1);
	text->no_addr = get_texture_addr(data, text->no_text);
	data->map->textures->so_text = mlx_xpm_file_to_image(data->mlx, data->map->so, 64, 64);
	if (!data->map->textures->so_text)
		return (-1);
	text->so_addr = get_texture_addr(data, text->so_text);
	data->map->textures->ea_text = mlx_xpm_file_to_image(data->mlx, data->map->ea, 64, 64);
	if (!data->map->textures->ea_text)
		return (-1);
	text->ea_addr = get_texture_addr(data, text->ea_text);
	data->map->textures->we_text = mlx_xpm_file_to_image(data->mlx, data->map->we, 64, 64);
	if (!data->map->textures->we_text)
		return (-1);
	text->we_addr = get_texture_addr(data, text->we_text);
	return (0);
}
