/*













*/

#include "../../include/cub3d.h"

void	key_w_and_key_s(t_data *data, float *new_x, float *new_y)
{
	float	proposed_x;
	float	proposed_y;

	proposed_x = *new_x;
	proposed_y = *new_y;
	if (data->keys[KEY_W])
	{
		proposed_x += cos(data->player->angle) / SQUARE_SIZE;
		proposed_y += sin(data->player->angle) / SQUARE_SIZE;
	}
	if (data->keys[KEY_S])
	{
		proposed_x -= cos(data->player->angle) / SQUARE_SIZE;
		proposed_y -= sin(data->player->angle) / SQUARE_SIZE;
	}
	if (control_touch_wall(data, proposed_x, *new_y) == 0)
		*new_x = proposed_x;
	if (control_touch_wall(data, *new_x, proposed_y) == 0)
		*new_y = proposed_y;
}

void	key_a_and_key_d(t_data *data, float *new_x, float *new_y)
{
	float	proposed_x;
	float	proposed_y;

	proposed_x = *new_x;
	proposed_y = *new_y;
	if (data->keys[KEY_A])
	{
		proposed_x -= cos(data->player->angle + M_PI / 2) / SQUARE_SIZE;
		proposed_y -= sin(data->player->angle + M_PI / 2) / SQUARE_SIZE;
	}
	if (data->keys[KEY_D])
	{
		proposed_x += cos(data->player->angle + M_PI / 2) / SQUARE_SIZE;
		proposed_y += sin(data->player->angle + M_PI / 2) / SQUARE_SIZE;
	}
	if (control_touch_wall(data, proposed_x, *new_y) == 0)
		*new_x = proposed_x;
	if (control_touch_wall(data, *new_x, proposed_y) == 0)
		*new_y = proposed_y;
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
