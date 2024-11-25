/*













*/

#include "../../include/cub3d.h"

void	key_w_and_key_s(t_data *data, float *new_x, float *new_y)
{
	if (data->keys[KEY_W])
	{
		*new_x += cos(data->player->angle) * 0.03;
		*new_y += sin(data->player->angle) * 0.03;
	}
	if (data->keys[KEY_S])
	{
		*new_x -= cos(data->player->angle) * 0.03;
		*new_y -= sin(data->player->angle) * 0.03;
	}
}

void	key_a_and_key_d(t_data *data, float *new_x, float *new_y)
{
	if (data->keys[KEY_A])
	{
		*new_x -= cos(data->player->angle + M_PI / 2) * 0.03;
		*new_y -= sin(data->player->angle + M_PI / 2) * 0.03;
	}
	if (data->keys[KEY_D])
	{
		*new_x += cos(data->player->angle + M_PI / 2) * 0.03;
		*new_y += sin(data->player->angle + M_PI / 2) * 0.03;
	}
}

// touche presser
int	handle_keypress_on(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = 1;
	return (0);
}

// touche relacher
int	handle_keypress_off(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65536)
		data->keys[keycode] = 0;
	return (0);
}
