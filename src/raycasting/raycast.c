/*













*/

#include "../../include/cub3d.h"

void	init_ray(t_raycast *ray)
{
	ray->touch_wall = false;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->perp_wall_dist = 0.0;
	ray->ray_dir_x = 0.0;
	ray->ray_dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side = 0;
}

void	draw_ceilling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win_height / 2)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_pixel_put_rgb(data, x, y, data->map->ceilling_color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	y = data->win_height / 2;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_pixel_put_rgb(data, x, y, data->map->floor_color);
			x++;
		}
		y++;
	}
}

void	raycast_ray(t_data *data)
{
	int			x;
	t_raycast	ray;
	t_wall		wall;

	draw_ceilling(data);
	draw_floor(data);
	x = 0;
	while (x < data->win_width)
	{
		init_ray_and_cam(data, &ray, x);
		calculate_steps_and_sides(data, &ray);
		algo_dda(data, &ray);
		calculate_projection(data, &ray, &wall);
		// if (ray.side == 0)
		// 	color = get_right_pixel(data, NORTH, x, y);
		// else
		// 	color = RED_RUSH;
		draw_wall(data, x, &wall, ray.side);
		x++;
	}
}
