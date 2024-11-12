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

void draw_line(t_data *data, int dir_x, int dir_y)
{
    // Position de départ (joueur) en pixels
    float start_x = data->player->x * SQUARE_SIZE;
    float start_y = data->player->y * SQUARE_SIZE;

    // Position d’arrivée (mur) en pixels
    float end_x = dir_x * SQUARE_SIZE;
    float end_y = dir_y * SQUARE_SIZE;

    // Calcul de la différence entre les coordonnées de début et de fin
    float delta_x = end_x - start_x;
    float delta_y = end_y - start_y;

    // Calcul du nombre d’étapes basé sur la plus grande distance
    int steps = fmax(fabs(delta_x), fabs(delta_y));

    // Calcul des incréments en x et y par étape
    float x_inc = delta_x / steps;
    float y_inc = delta_y / steps;

    // Position courante pour le dessin
    float current_x = start_x;
    float current_y = start_y;

    // Boucle pour dessiner le trait point par point
    for (int i = 0; i < steps; i++) {
        my_pixel_put(data, (int)current_x, (int)current_y, BLUE);
        current_x += x_inc;
        current_y += y_inc;
    }
}



void	dda_algorithm(t_data *data)
{
	int		dir_x;
	int		dir_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;

	if (cos(data->player->angle) > 0)
		step_x = 1;
	else
		step_x = -1;
	if (sin(data->player->angle) > 0)
		step_y = 1;
	else
		step_y = -1;
	dir_x = data->player->x;
	dir_y = data->player->y;
	data->player->dir_x = cos(data->player->angle);
	data->player->dir_y = sin(data->player->angle);
	data->player->delta_x = fabs(1 / cos(data->player->angle));
	data->player->delta_y = fabs(1 / sin(data->player->angle));
	if (step_x == 1)
		side_dist_x = (dir_x + 1 - data->player->x) * data->player->delta_x;
	else
		side_dist_x = (data->player->x - dir_x) * data->player->delta_x;
	if (step_y == 1)
		side_dist_y = (dir_y + 1 - data->player->y) * data->player->delta_y;
	else
		side_dist_y = (data->player->y - dir_y) * data->player->delta_y;
	while (data->map->map_array[dir_y][dir_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += data->player->delta_x;
			dir_x += step_x;
		}
		else
		{
			side_dist_y += data->player->delta_y;
			dir_y += step_y;
		}
	}
	draw_line(data, dir_x, dir_y);
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
		new_x += cos(data->player->angle) * 0.2;
		new_y += sin(data->player->angle) * 0.2;
	}
	if (data->keys[KEY_S])
	{
		new_x -= cos(data->player->angle) * 0.2;
		new_y -= sin(data->player->angle) * 0.2;
	}
	if (data->keys[KEY_A])
	{
		new_x -= cos(data->player->angle + M_PI / 2) * 0.2;
		new_y -= sin(data->player->angle + M_PI / 2) * 0.2;
	}
	if (data->keys[KEY_D])
	{
		new_x += cos(data->player->angle + M_PI / 2) * 0.2;
		new_y += sin(data->player->angle + M_PI / 2) * 0.2;
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
