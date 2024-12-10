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

void	calculate_projection(t_data *data, t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player->x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player->y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->wall.line_height = (int)(data->win_height / ray->perp_wall_dist);
	ray->wall.draw_start = -(ray->wall.line_height) / 2 + data->win_height / 2;
	if (ray->wall.draw_start < 0)
		ray->wall.draw_start = 0;
	ray->wall.draw_end = ray->wall.line_height / 2 + data->win_height / 2;
	if (ray->wall.draw_end >= data->win_height)
		ray->wall.draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall.wall_x = data->player->y + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		ray->wall.wall_x = data->player->x + ray->perp_wall_dist
			* ray->ray_dir_x;
	ray->wall.wall_x -= floor(ray->wall.wall_x);
}

void	draw_wall(t_data *data, int x, t_textures *text, t_raycast *ray)
{
	int		y;
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;

	tex_x = (int)(ray->wall.wall_x * (float)text->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = text->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = text->width - tex_x - 1;
	step = 1.0 * text->height / ray->wall.line_height;
	tex_pos = (ray->wall.draw_start - data->win_height / 2
			+ ray->wall.line_height / 2) * step;
	y = ray->wall.draw_start;
	while (y < ray->wall.draw_end)
	{
		tex_y = (int)tex_pos & (text->height - 1);
		tex_pos += step;
		my_pixel_put(data, x, y, get_color_pixel(text, tex_x, tex_y));
		y++;
	}
}
