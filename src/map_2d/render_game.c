/*













*/

#include "../../include/cub3d.h"

void draw_player(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (data->player->x_cam * SQUARE_SIZE) + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
	y = (data->player->y_cam * SQUARE_SIZE) + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			my_pixel_put(data, x + i, y + j, RED);
			j++;
		}
		i++;
	}
}
int handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_S)
		data->player->y_cam += 0.2;
	else if (keycode == KEY_W)
		data->player->y_cam -= 0.2;
	else if (keycode == KEY_A)
		data->player->x_cam -= 0.2;
	else if (keycode == KEY_D)
		data->player->x_cam += 0.2;
	return (0);
}
int	render_game(t_data *data)
{
	ft_memset(data->address, 0, data->win_width * data->win_height * (data->bits_p_pix / 8));
	map_img_output(data, data->map->map_array, 0);
	map_img_output(data, data->map->map_array, 1);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
