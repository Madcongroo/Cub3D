/*












*/

#include "../../include/cub3d.h"

int	get_color_pixel(t_data *data, t_textures *text, int x, int y)
{
	char	*dst;
	(void)data;

	dst = text->addr + (y * text->line_len + x * (text->bits_p_pix / 8));
	return (*(int*)dst);
}

int	init_text_helper(t_data *data, t_textures *text, char *path)
{
	text->img = mlx_xpm_file_to_image(data->mlx, path, &text->width, &text->height);
	if (!text->img)
		return (-1);
	text->addr = mlx_get_data_addr(text->img, &text->bits_p_pix, &text->line_len, &text->endian);
	if (!text->addr)
		return (-1);
	return (0);
}

int	init_textures(t_data *data)
{
	if (init_text_helper(data, &data->textures[0], data->map->no) == -1)
		return (-1);
	if (init_text_helper(data, &data->textures[1], data->map->so) == -1)
		return (-1);
	if (init_text_helper(data, &data->textures[2], data->map->ea) == -1)
		return (-1);
	if (init_text_helper(data, &data->textures[3], data->map->we) == -1)
		return (-1);
	return (0);
}
