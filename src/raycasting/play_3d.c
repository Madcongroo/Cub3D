/*













*/

#include "../../include/cub3d.h"

void	init_ray_and_cam(t_data *data, t_raycast *ray, int x)
{
	float	camera_x;

	init_ray(ray);
	camera_x = 2 * x / (float)data->win_width - 1;
	ray->ray_dir_x = data->player->x_cam + data->player->plan_x * camera_x;
	ray->ray_dir_y = data->player->y_cam + data->player->plan_y * camera_x;
	ray->map_x = (int)data->player->x;
	ray->map_y = (int)data->player->y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	calculate_steps_and_sides(t_data *data, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->y)
			* ray->delta_dist_y;
	}
}

void	algo_dda(t_data *data, t_raycast *ray)
{
	while (!ray->touch_wall)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map->map_array[ray->map_y][ray->map_x] == '1')
			ray->touch_wall = true;
	}
}

void	calculate_projection(t_data *data, t_raycast *ray, t_wall *wall)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player->x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player->y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	wall->line_height = (int)(data->win_height / ray->perp_wall_dist);
	wall->draw_start = -(wall->line_height) / 2 + data->win_height / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + data->win_height / 2;
	if (wall->draw_end >= data->win_height)
		wall->draw_end = data->win_height - 1;
}

void	draw_wall(t_data *data, int x, t_wall *wall, int side)
{
	int	y;
	int	color;

	y = wall->draw_start;
	while (y < wall->draw_end)
	{
		if (side == 0)
			color = get_right_pixel(data, NORTH, x, y);
		else
			color = get_right_pixel(data, SOUTH, x, y);
		if (color == -1)
		{
			free_all(data);
			exit (EXIT_FAILURE);
		}
		printf("color code is %d\n", color);
		my_pixel_put(data, x, y, color);
		y++;
	}
}
