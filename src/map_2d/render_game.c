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

void draw_line(t_data *data, float dir_x, float dir_y)
{
	float start_x = data->player->x * SQUARE_SIZE;
	float start_y = data->player->y * SQUARE_SIZE;
	float end_x = dir_x * SQUARE_SIZE;
	float end_y = dir_y * SQUARE_SIZE;
	float delta_x = end_x - start_x;
	float delta_y = end_y - start_y;
	int steps = fmax(fabs(delta_x), fabs(delta_y));
	float x_inc = delta_x / steps;
	float y_inc = delta_y / steps;
	float current_x = start_x;
	float current_y = start_y;

	for (int i = 0; i < steps; i++)
	{
		my_pixel_put(data, (int)current_x, (int)current_y, BLUE);
		current_x += x_inc;
		current_y += y_inc;
	}
}

void	dda_algorithm(t_data *data)
{
	int dir_x, dir_y;;
	float ray_x, ray_y;
	float side_dist_x, side_dist_y;
	int step_x, step_y;

	ray_x = data->player->x;
	ray_y = data->player->y;
	dir_x = (int)ray_x;
	dir_y = (int)ray_y;
	data->player->dir_x = cos(data->player->angle);
	data->player->dir_y = sin(data->player->angle);
	data->player->delta_x = fabs(1 / data->player->dir_x);
	data->player->delta_y = fabs(1 / data->player->dir_y);
	if (data->player->dir_x > 0)
	{
		step_x = 1;
		side_dist_x = (dir_x + 1.0 - ray_x) * data->player->delta_x;
	}
	else
	{
		step_x = -1;
		side_dist_x = (ray_x - dir_x) * data->player->delta_x;
	}

	if (data->player->dir_y > 0)
	{
		step_y = 1;
		side_dist_y = (dir_y + 1.0 - ray_y) * data->player->delta_y;
	}
	else
	{
		step_y = -1;
		side_dist_y = (ray_y - dir_y) * data->player->delta_y;
	}
	while (data->map->map_array[dir_y][dir_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += data->player->delta_x;
			dir_x += step_x;
			ray_x += step_x * data->player->delta_x;
		}
		else
		{
			side_dist_y += data->player->delta_y;
			dir_y += step_y;
			ray_y += step_y * data->player->delta_y;
		}
	}
	//pour dessiner la ligne du joueur au mur
	draw_line(data, ray_x, ray_y);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, data->player->x, data->player->y);
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
	// printf("Angle : %.2f radians\n", player->angle);
	// printf("Vecteur de direction : (x_cam : %.2f, y_cam : %.2f)\n", player->x_cam, player->y_cam);
	// printf("Vecteur du plan de la caméra : (plan_x : %.2f, plan_y : %.2f)\n", player->plan_x, player->plan_y);

}

void process_movement(t_data *data)
{
	float new_x;
	float new_y;

	new_x = data->player->x;
	new_y = data->player->y;
 	if (data->keys[KEY_LEFT])
		rotate_player(data->player, -ROT_SPEED);
	if (data->keys[KEY_RIGHT])
		rotate_player(data->player, ROT_SPEED);
	if (data->keys[KEY_W])
	{
		new_x += cos(data->player->angle) * 0.1;
		new_y += sin(data->player->angle) * 0.1;
	}
	if (data->keys[KEY_S])
	{
		new_x -= cos(data->player->angle) * 0.1;
		new_y -= sin(data->player->angle) * 0.1;
	}
	if (data->keys[KEY_A])
	{
		new_x -= cos(data->player->angle + M_PI / 2) * 0.1;
		new_y -= sin(data->player->angle + M_PI / 2) * 0.1;
	}
	if (data->keys[KEY_D])
	{
		new_x += cos(data->player->angle + M_PI / 2) * 0.1;
		new_y += sin(data->player->angle + M_PI / 2) * 0.1;
	}
	data->player->x = new_x;
	data->player->y = new_y;
}
int	render_game(t_data *data)
{
	ft_memset(data->address, 0, data->win_width * data->win_height * (data->bits_p_pix / 8));
	map_img_output(data, data->map->map_array, 0);
	map_img_output(data, data->map->map_array, 1);
	draw_player(data);
	dda_algorithm(data);
	process_movement(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
