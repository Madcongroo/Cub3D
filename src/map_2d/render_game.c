/*













*/

#include "../../include/cub3d.h"

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (data->player->x * SQUARE_SIZE) + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
	y = (data->player->y * SQUARE_SIZE) + (SQUARE_SIZE / 2) - (PLAYER_SIZE / 2);
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

void	rotate_player(t_player *player, float angle)
{
	player->angle += angle;
	if (player->angle < 0)
		player->angle += 2 * M_PI;
	else if (player->angle > 2 * M_PI)
		player->angle -= 2 * M_PI;
	player->x_cam = cos(player->angle);
	player->y_cam = sin(player->angle);
	player->plan_x = -PLANE_LENGHT * player->y_cam;
	player->plan_y = PLANE_LENGHT * player->x_cam;
	/* TEMPORAIRE */
	// Imprimer les valeurs pour vérifier la mise à jour des vecteurs
    //printf("Angle : %.2f radians\n", player->angle);
    //printf("Vecteur de direction : (x_cam : %.2f, y_cam : %.2f)\n", player->x_cam, player->y_cam);
    //printf("Vecteur du plan de la caméra : (plan_x : %.2f, plan_y : %.2f)\n", player->plan_x, player->plan_y);
}

void	process_movement(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player->x;
	new_y = data->player->y;
	if (data->keys[KEY_LEFT])
		rotate_player(data->player, -ROT_SPEED);
	if (data->keys[KEY_RIGHT])
		rotate_player(data->player, ROT_SPEED);
	key_w_and_key_s(data, &new_x, &new_y);
	key_a_and_key_d(data, &new_x, &new_y);
	data->player->x = new_x;
	data->player->y = new_y;
}

int	render_game(t_data *data)
{
	ft_memset(data->address, 0, data->win_width * data->win_height
		*(data->bits_p_pix / 8));
	map_img_output(data, data->map->map_array, 0);
	map_img_output(data, data->map->map_array, 1);
	mini_map(data);
	draw_player(data);
	process_movement(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
